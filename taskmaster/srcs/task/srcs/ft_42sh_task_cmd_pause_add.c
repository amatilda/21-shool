/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_pause_add.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void		fn_pause_log_err_pause(register t_task *task,
register t_jobs *jobs_b)
{
	return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
	" Failed job %s pid %d to pause.\n", task->name, jobs_b->pid));
}

static void		fn_stoped(register t_jobs *jobs_b)
{
	jobs_b->status_task = status_task_stop;
}

void			ft_42sh_task_cmd_pause_kill(register t_task *task,
register t_jobs *jobs_b,
time_t time_cur, int status)
{
	pid_t								pid;

	if (jobs_b->status_task != status_task_run)
	{
		return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" Failed job %s pid %d to pause - not runung.\n",
		task->name, jobs_b->pid));
	}
	if (SIGSTOP == task->stop_signal)
	{
		return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" Failed job %s pid %d to pause - not support.\n",
		task->name, jobs_b->pid));
	}
	if (kill(jobs_b->pid, SIGSTOP) == -1)
		return (fn_pause_log_err_pause(task, jobs_b));
	pid = waitpid(jobs_b->pid, &status, WUNTRACED | WNOHANG | WCONTINUED);
	if (pid == 0 || pid == -1)
		return (fn_pause_log_err_pause(task, jobs_b));
	ft_42sh_task_upd_status_time(jobs_b, time_cur);
	if (WIFSTOPPED(status))
		return (fn_stoped(jobs_b));
	ft_42sh_task_upd_status_add(jobs_b, task, time_cur, status);
	return (fn_pause_log_err_pause(task, jobs_b));
}

void			ft_42sh_task_cmd_pause_all(register t_task *task,
time_t time_cur)
{
	register t_jobs						*jobs_b;
	register t_jobs						*jobs_e;

	jobs_b = task->jobs;
	if (jobs_b == 0)
	{
		return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" Failed job %s to pause.\n", task->name));
	}
	jobs_e = &jobs_b[task->copies];
	while (jobs_b < jobs_e)
	{
		ft_42sh_task_cmd_pause_kill(task, jobs_b, time_cur, 0);
		jobs_b++;
	}
}
