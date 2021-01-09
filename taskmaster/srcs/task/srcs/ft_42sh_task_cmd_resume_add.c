/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_resume_add.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void		fn_resume_log_err(register t_task *task,
register t_jobs *jobs_b)
{
	return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
	" Failed job %s pid %d to resume.\n", task->name, jobs_b->pid));
}

void			ft_42sh_task_cmd_resume_kill(register t_task *task,
register t_jobs *jobs_b,
time_t time_cur, int status)
{
	pid_t								pid;

	if (jobs_b->status_task != status_task_stop)
	{
		return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" Failed job %s pid %d to resume - not stoping.\n",
		task->name, jobs_b->pid));
	}
	if (kill(jobs_b->pid, SIGCONT) == -1)
		return (fn_resume_log_err(task, jobs_b));
	pid = waitpid(jobs_b->pid, &status, WUNTRACED | WNOHANG | WCONTINUED);
	if (pid == 0 || pid == -1)
		return (fn_resume_log_err(task, jobs_b));
	jobs_b->time_start = time_cur;
	if (WIFCONTINUED(status))
	{
		jobs_b->status_task = status_task_run;
		return ;
	}
	ft_42sh_task_upd_status_add(jobs_b, task, time_cur, status);
	return (fn_resume_log_err(task, jobs_b));
}

void			ft_42sh_task_cmd_resume_all(register t_task *task,
time_t time_cur)
{
	register t_jobs						*jobs_b;
	register t_jobs						*jobs_e;

	jobs_b = task->jobs;
	if (jobs_b == 0)
	{
		return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" Failed job %s to resume.\n", task->name));
	}
	jobs_e = &jobs_b[task->copies];
	while (jobs_b < jobs_e)
	{
		ft_42sh_task_cmd_resume_kill(task, jobs_b, time_cur, 0);
		jobs_b++;
	}
}
