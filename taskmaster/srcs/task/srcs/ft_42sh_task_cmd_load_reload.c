/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_load_reload.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

void			ft_42sh_task_load_clean(register t_task_load_fd *fds,
char ***arg)
{
	register char				**tmp;
	int							fd;

	if ((fd = fds->fd_out) != -1)
	{
		fds->fd_out =  -1;
		close(fd);
	}
	if ((fd = fds->fd_err) != -1)
	{
		fds->fd_err =  -1;
		close(fd);
	}
	if ((tmp = arg[0]) > (char **)1)
	{
		arg[0] = 0;
		ft_strsplit_free(tmp);
	}
}

static void		fn_finish_load(register t_main_42sh *array,
register t_list *task_list, register void *str)
{
	task_log("["TASK_CMD_LOAD"] "TASK_LOG_SUCCESS
	" Load file configuration: %s\n", str);
	array->task.b_init = 0;
	pthread_mutex_lock(&array->task.mutex);
	array->task.task_list = task_list;
	pthread_mutex_unlock(&array->task.mutex);
}

void			ft_42sh_task_cmd_load(register t_main_42sh *array,
register char **lp_arg)
{
	register void				*str;
	register t_list				*task_list;

	if (array->task.task_list != 0)
	{
		ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN" ",
		TASK_CMD_LOAD, ": "TASK_LOAD_ALREDY""TASK_RESET""TASK_LOAD_RELOAD);
		return ;
	}
	if ((str = ft_42sh_task_cmd_other_load_test(array, lp_arg,
	TASK_CMD_LOAD)) == 0)
		return ;
	if ((task_list = conf_read(str)) == 0)
	{
		task_log("["TASK_CMD_LOAD"] "TASK_LOG_ERROR
		" Load file configuration: %s\n", str);
		array->env.exit_status->number = STATUS_FALTURE_42SH;
		return ;
	}
	if (ft_42sh_task_init_path_file(array, str, TASK_CMD_LOAD) == 0)
		return ;
	fn_finish_load(array, task_list, str);
}

static void		fn_finish_reload(register t_main_42sh *array,
register t_list *task_list_old, register t_list *task_list_new,
register void *str)
{
	array->task.b_delete = 1;
	array->task.b_init = 0;
	ft_42sh_task_cmd_reload_stop(array, task_list_old, task_list_new);
	pthread_mutex_lock(&array->task.mutex);
	ft_42sh_task_cmd_reload_move_jobs(task_list_old, task_list_new);
	ft_42sh_task_cmd_reload_start(array, task_list_new);
	array->task.task_list = task_list_new;
	pthread_mutex_unlock(&array->task.mutex);
	array->task.b_delete = 0;
	task_list_delete(task_list_old);
	task_log("["TASK_CMD_RELOAD"] "TASK_LOG_SUCCESS
	" Reload file configuration: %s\n", str);
}

void			ft_42sh_task_cmd_reload(register t_main_42sh *array,
register char **lp_arg)
{
	register void				*str;
	register t_list				*task_list_old;
	register t_list				*task_list_new;

	if ((task_list_old = array->task.task_list) == 0)
	{
		ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN" ",
		TASK_CMD_RELOAD, ": "TASK_REOALD_NOT_LOAD""TASK_RESET""
		TASK_RELOAD_LOAD);
		return ;
	}
	if (lp_arg[0] != 0)
	{
		return (ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN
		" ", TASK_CMD_RELOAD, ": "TASK_TOO_MANY_ARG""TASK_RESET));
	}
	str = array->task.path_file;
	if ((task_list_new = conf_reload(str, task_list_old)) == 0)
	{
		task_log("["TASK_CMD_RELOAD"] "TASK_LOG_ERROR
		" Reload file configuration: %s\n", str);
		array->env.exit_status->number = STATUS_FALTURE_42SH;
		return ;
	}
	fn_finish_reload(array, task_list_old, task_list_new, str);
}
