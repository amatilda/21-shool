/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_load_start_error.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

size_t			ft_42sh_task_load_on_start(t_jobs *jobs_b, t_jobs *jobs_e,
register t_task *task)
{
	while (jobs_b < jobs_e)
	{
		jobs_b->pid = -1;
		jobs_b->retries = task->retries;
		jobs_b->status_task = status_task_not_auto_start;
		jobs_b++;
	}
	return (1);
}

size_t			ft_42sh_task_load_start_fd(register t_task *task,
register t_task_load_fd *fds)
{
	register char				*tmp;

	if ((tmp = task->tstdout) != 0)
	{
		if ((fds->fd_out = open(tmp, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR |
		S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		{
			return (ft_42sh_task_load_start_error(task, TASK_LOG_REDIRECT,
			tmp, 0));
		}
	}
	if ((tmp = task->tstderr) != 0)
	{
		if ((fds->fd_err = open(tmp, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR |
		S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		{
			return (ft_42sh_task_load_start_error(task, TASK_LOG_REDIRECT,
			tmp, 0));
		}
	}
	return (1);
}

size_t			ft_42sh_task_load_start_critical(register t_task *task,
register char *str)
{
	task_log("[%s] "TASK_LOG_CRITICAL
	" %s.\n", task->name, str);
	return (0);
}

size_t			ft_42sh_task_load_start_error(register t_task *task,
register char *str, register char *name, register size_t n)
{
	task_log("[%s] "TASK_LOG_ERROR
	" %s: %s\n", task->name, str, name);
	return (n);
}
