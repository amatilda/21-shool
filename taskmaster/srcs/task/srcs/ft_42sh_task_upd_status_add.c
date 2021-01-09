/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_upd_status_add.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void		fn_test_quit(register t_jobs *jobs_b,
register t_task *task)
{
	if ((jobs_b->status_task == status_task_start &&
	(int)jobs_b->time_work >= task->success_waiting)
	|| (jobs_b->status_task == status_task_start &&
	(int)jobs_b->time_work >= task->stop_waiting) ||
	jobs_b->status_task != status_task_start ||
	jobs_b->status_task == status_task_quits)
	{
		jobs_b->status_task = status_task_completed;
		return ;
	}
	if (jobs_b->status_task == status_task_start)
	{
		task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" The task only worked for %zu seconds instead of the required %d.\n",
		jobs_b->time_work, task->success_waiting);
	}
	else
	{
		task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" The task took longer %zu than necessary to complete %d.\n",
		jobs_b->time_work, task->stop_waiting);
	}
	jobs_b->status_task = status_task_completed_falled;
}

static void		fn_wait_sig_exit(register t_jobs *jobs_b,
register t_task *task, int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) != task->stop_signal)
		{
			jobs_b->status_task = status_task_completed_falled;
			task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
			" The job %s ended unexpectedly due to a signal: %d.\n",
			task->name, WTERMSIG(status));
		}
		else
			fn_test_quit(jobs_b, task);
	}
	else if (WIFEXITED(status))
	{
		if (task->end_codes[WEXITSTATUS(status)] == -1)
		{
			jobs_b->status_task = status_task_completed_falled;
			task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
			" The job %s ended unexpectedly with code: %d.\n",
			task->name, WEXITSTATUS(status));
		}
		else
			fn_test_quit(jobs_b, task);
	}
}

void			ft_42sh_task_upd_status_add(register t_jobs *jobs_b,
register t_task *task, register time_t time_cur, int status)
{
	if (WIFSTOPPED(status))
	{
		jobs_b->status_task = status_task_stop;
		task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" The job %s was unexpectedly suspended by a signal: %d.\n",
		task->name, WSTOPSIG(status));
	}
	else if (WIFCONTINUED(status))
	{
		jobs_b->time_start = time_cur;
		jobs_b->status_task = status_task_run;
		task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" The job resumed unexpectedly.\n");
	}
	else
		fn_wait_sig_exit(jobs_b, task, status);
}