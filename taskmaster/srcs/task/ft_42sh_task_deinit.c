/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_deinit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_task.h"

void		ft_42sh_task_delete(register t_main_42sh *array)
{
	register t_list			*task_list;
	register void			*b;

	if ((task_list = array->task.task_list) == 0)
		return ;
	b = array->task.path_file;
	array->task.path_file = 0;
	array->task.task_list = 0;
	ft_42sh_task_set_fd(array);
	task_log("["TASK_CMD_DELETE"] "TASK_LOG_SUCCESS
	" Unload file configuration: %s\n", b);
	ft_free(b);
	task_list_delete(task_list);
}

void		ft_42sh_task_deinit(register t_main_42sh *array)
{
	int						fd;
	char					*tmp;

	if (array->task.path_file != 0 && array->home.lp_home != 0 &&
	(tmp = ft_strjoin(array->home.lp_home, "/.taskmaster.ini")) != 0)
	{
		if ((fd = open(tmp, O_CREAT | O_TRUNC | O_RDWR,
		S_IWUSR | S_IRUSR)) != -1)
		{
			write(fd, array->task.path_file, ft_strlen(array->task.path_file));
			close(fd);
		}
		ft_free(tmp);
	}
	pthread_mutex_lock(&array->task.mutex);
	ft_42sh_task_delete(array);
	pthread_mutex_unlock(&array->task.mutex);
	ft_42sh_task_thread_deinit(array);
}

void		ft_42sh_task_add_bultin(register t_main_42sh *array,
void (*f)(register t_main_42sh *array,
register char *lp_key, register void *str, uint_fast8_t b_type))
{
	f(array, TASK_BULTIN, &ft_42sh_task_cmd, AUTO_TYPE_FUN_42SH);
}
