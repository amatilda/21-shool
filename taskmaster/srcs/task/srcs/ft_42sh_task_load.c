/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_load.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void		fn_error_fd(register t_main_42sh *array, register int fd)
{
	if (fd != -1)
		close(fd);
	task_log("["TASK_CMD_LOAD"] "TASK_LOG_CRITICAL
	" Open descriptor limit exceeded.\n");
	array->env.exit_status->number = STATUS_FALTURE_42SH;
	return ;
}

static void		fn_pre(register t_task_load_fd *fds,
char ***arg)
{
	arg[0] = 0;
	fds->fd_out = -1;
	fds->fd_err = -1;
}

void			ft_42sh_task_load(register t_main_42sh *array,
register t_list *task_list)
{
	char						**arg;
	register t_task				*task;
	t_task_load_fd				fds;

	if ((fds.fd_null = open("/dev/null", O_RDWR)) == -1)
		return (fn_error_fd(array, fds.fd_null));
	fn_pre(&fds, &arg);
	while (task_list != 0)
	{
		ft_42sh_task_load_clean(&fds, &arg);
		task = task_list->task;
		task_list = task_list->next;
		if ((arg = ft_42sh_task_test_path(array, task, task->command,
		ft_strlen(task->command)))
		== (void *)1)
			continue ;
		if (arg == 0)
			continue ;
		ft_42sh_task_load_start(array, task, &fds, arg);
	}
	close(fds.fd_null);
	ft_42sh_task_load_clean(&fds, &arg);
}

void			ft_42sh_task_load_one(register t_main_42sh *array,
register t_list *task_list)
{
	char						**arg;
	register t_task				*task;
	t_task_load_fd				fds;

	if ((fds.fd_null = open("/dev/null", O_RDWR)) == -1)
		return (fn_error_fd(array, fds.fd_null));
	fn_pre(&fds, &arg);
	task = task_list->task;
	if ((arg = ft_42sh_task_test_path(array, task, task->command,
	ft_strlen(task->command)))
	!= (void *)1 && arg != 0)
		ft_42sh_task_load_start(array, task, &fds, arg);
	close(fds.fd_null);
	ft_42sh_task_load_clean(&fds, &arg);
}

void			ft_42sh_task_load_singl(register t_main_42sh *array,
register t_list *task_list, register t_task *task,
register t_jobs *jobs_b)
{
	char						**arg;
	t_task_load_fd				fds;

	if ((fds.fd_null = open("/dev/null", O_RDWR)) == -1)
	{
		array->env.exit_status->number = STATUS_FALTURE_42SH;
		jobs_b->status_task = status_task_fail;
		return (task_log("["TASK_CMD_LOAD"] "TASK_LOG_CRITICAL
		" Open descriptor limit exceeded.\n"));
	}
	arg = 0;
	fds.fd_out = -1;
	fds.fd_err = -1;
	if ((arg = ft_42sh_task_test_path(array, task, task->command,
	ft_strlen(task->command)))
	== (void *)1 || arg == 0)
	{
		jobs_b->status_task = status_task_fail;
		return (ft_42sh_task_load_clean(&fds, &arg));
	}
	fds.jobs_b = jobs_b;
	ft_42sh_task_load_start_singl(array, task, &fds, arg);
	close(fds.fd_null);
	ft_42sh_task_load_clean(&fds, &arg);
	(void)task_list;
}
