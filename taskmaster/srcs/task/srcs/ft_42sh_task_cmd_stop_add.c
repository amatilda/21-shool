/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_stop_add.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void		fn_stop_log_err(register t_task *task, register t_jobs *jobs_b)
{
	return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
	" Failed job %s pid %d to stop.\n", task->name, jobs_b->pid));
}

void			ft_42sh_task_cmd_stop_kill(register t_task *task,
register t_jobs *jobs_b, time_t time_cur)
{
	if (jobs_b->status_task == status_task_run || jobs_b->status_task ==
	status_task_start || jobs_b->status_task == status_task_stop)
	{
		if (kill(jobs_b->pid, task->stop_signal) == -1)
			return (fn_stop_log_err(task, jobs_b));
		jobs_b->status_task = status_task_quits;
		jobs_b->time_start = time_cur;
		jobs_b->time_work = 0;
	}
	task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
	" Failed job %s pid %d to stop - not runung.\n", task->name, jobs_b->pid);
}

void			ft_42sh_task_cmd_stop_all(register t_task *task,
time_t time_cur)
{
	register t_jobs						*jobs_b;
	register t_jobs						*jobs_e;

	jobs_b = task->jobs;
	if (jobs_b == 0)
	{
		return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" Failed job %s to stop.\n", task->name));
	}
	jobs_e = &jobs_b[task->copies];
	while (jobs_b < jobs_e)
	{
		ft_42sh_task_cmd_stop_kill(task, jobs_b, time_cur);
		jobs_b++;
	}
}
