/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_task.h"

size_t		ft_42sh_task_init_path_file(register t_main_42sh *array,
register void *str, char *type)
{
	if ((array->task.path_file = ft_strdup(str)) == 0)
	{
		if (type == TASK_CMD_LOAD)
		{
			task_log("["TASK_CMD_LOAD"] "TASK_LOG_CRITICAL
			" "TASK_LOG_MEMORY".\n");
		}
		else
		{
			task_log("["TASK_CMD_RELOAD"] "TASK_LOG_CRITICAL
			" "TASK_LOG_MEMORY".\n");
		}
		array->env.exit_status->number = STATUS_FALTURE_42SH;
		pthread_mutex_lock(&array->task.mutex);
		ft_42sh_task_delete(array);
		pthread_mutex_unlock(&array->task.mutex);
		return (0);
	}
	return (1);
}

static void	fn_init_finish(register t_main_42sh *array,
register t_list *task_list, register void *str)
{
	task_log("["TASK_CMD_LOAD"] "TASK_LOG_SUCCESS
	" Load file configuration: %s\n", str);
	ft_42sh_task_load(array, task_list);
	pthread_mutex_lock(&array->task.mutex);
	array->task.task_list = task_list;
	pthread_mutex_unlock(&array->task.mutex);
}

static void	*fn_path_free(int fd, char *tmp)
{
	close(fd);
	if (tmp != 0)
		ft_free(tmp);
	return (0);
}

static void	*fn_path_file(register t_main_42sh *array,
int argc, char **argv)
{
	int						fd;
	char					*tmp;
	struct stat				st;

	if (argc == 2)
		return (ft_strdup(argv[1]));
	tmp = 0;
	if (array->home.lp_home != 0 &&
	(tmp = ft_strjoin(array->home.lp_home, "/.taskmaster.ini")) == 0)
		return (0);
	fd = open(tmp, O_RDONLY);
	ft_free(tmp);
	if (fd == -1)
		return (0);
	if (fstat(fd, &st) == -1 || st.st_size > 500 ||
	(tmp = malloc(st.st_size + 1)) == 0)
		return (fn_path_free(fd, 0));
	if (read(fd, tmp, st.st_size) != st.st_size)
		return (fn_path_free(fd, tmp));
	close(fd);
	tmp[st.st_size] = 0;
	array->task.b_init = 1;
	return (tmp);
}

void		ft_42sh_task_init(register t_main_42sh *array,
int argc, char **argv)
{
	register t_list			*task_list;
	register void			*str;

	ft_42sh_task_thread_init(array);
	array->task.b_init = 0;
	if ((str = fn_path_file(array, argc, argv)) == 0)
		return (ft_free(str));
	ft_42sh_task_set_fd(array);
	if ((task_list = conf_read(str)) == 0)
		return (ft_free(str));
	array->task.path_file = str;
	fn_init_finish(array, task_list, str);
}
