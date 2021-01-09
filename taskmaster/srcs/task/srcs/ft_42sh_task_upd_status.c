/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_upd_status.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

void			ft_42sh_task_upd_status_time(register t_jobs *jobs_b,
register time_t time_cur)
{
	register time_t				time_start;
	register t_status_task		status_task;

	if ((status_task = jobs_b->status_task) == status_task_run ||
	status_task == status_task_start)
	{
		time_start = jobs_b->time_start;
		jobs_b->time_start = time_cur;
		if (time_start > time_cur)
		{
			task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
			" The date is set incorrectly.\n");
			return ;
		}
		jobs_b->time_work = jobs_b->time_work + (time_cur - time_start);
	}
}

static void		fn_kill(register t_task *task,
register t_jobs *jobs_b, uint8_t action)
{
	kill(jobs_b->pid, SIGKILL);
	if (action == 0)
	{
		jobs_b->status_task = status_task_fail;
		task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" A problem with `waitpid`.\n");
	}
	else if (action == 1)
	{
		jobs_b->status_task = status_task_completed_falled;
		task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" The task took longer %zu than necessary to complete %d.\n",
		jobs_b->time_work, task->success_waiting);
	}
}

static void		fn_wait(register t_jobs *jobs_b,
register t_task *task, register time_t time_cur)
{
	pid_t						pid;
	register t_status_task		status_task;
	int							status;

	if ((status_task = jobs_b->status_task) == status_task_fail ||
	status_task == status_task_completed ||
	status_task == status_task_completed_falled ||
	status_task == status_task_not_auto_start)
		return ;
	pid = waitpid(jobs_b->pid, &status, WUNTRACED | WNOHANG | WCONTINUED);
	ft_42sh_task_upd_status_time(jobs_b, time_cur);
	if (pid == 0)
	{
		if (status_task == status_task_start &&
		(int)jobs_b->time_work >= task->success_waiting)
			jobs_b->status_task = status_task_run;
		else if (status_task == status_task_quits &&
		(int)jobs_b->time_work >= task->stop_waiting)
			fn_kill(task, jobs_b, 1);
		return ;
	}
	if (pid == -1)
		return (fn_kill(task, jobs_b, 0));
	ft_42sh_task_upd_status_add(jobs_b, task, time_cur, status);
}

void			ft_42sh_task_upd_status(register t_main_42sh *array)
{
	register t_list				*task_list;
	register t_task				*task;
	register t_jobs				*jobs_b;
	register t_jobs				*jobs_e;
	time_t						time_cur;

	if ((task_list = array->task.task_list) == 0)
		return ;
	time_cur = time(0);
	while (task_list != 0)
	{
		task = task_list->task;
		jobs_b = task->jobs;
		if (jobs_b != 0)
		{
			jobs_e = &jobs_b[task->copies];
			while (jobs_b < jobs_e)
			{
				fn_wait(jobs_b, task, time_cur);
				jobs_b++;
			}
		}
		task_list = task_list->next;
	}
}