/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_load_start.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static size_t	fn_finish(register t_task *task)
{
	t_jobs					*jobs;

	if ((jobs = task->jobs) == 0)
		return (1);
	task->jobs = 0;
	ft_free(jobs);
	return (1);
}

static pid_t	fn_while(register t_main_42sh *array,
register t_task *task, register t_task_load_fd *fds, register char **arg)
{
	pid_t						pid;
	int							status;

	fds->retries = task->retries + 1;
	while (fds->retries-- != 0)
	{
		if ((pid = fork()) == 0)
			ft_42sh_task_load_start_fork(array, task, fds, arg);
		else if (pid < 0)
			task_log("[%s] "TASK_LOG_ERROR" %s\n", task->name, "fork");
		else if (waitpid(pid, &status, WUNTRACED | WCONTINUED) != -1)
		{
			if (WIFSTOPPED(status) && WSTOPSIG(status) == SIGTRAP)
				return (pid);
			else if (!WIFEXITED(status))
				task_log("[%s] "TASK_LOG_ERROR" %s\n", task->name, "unknown");
		}
		else
		{
			task_log("[%s] "TASK_LOG_ERROR" %s\n", task->name, "waitpid");
			kill(pid, SIGKILL);
		}
	}
	return (0);
}

static void		fn_set(t_jobs *jobs_b)
{
	jobs_b->status_task = status_task_start;
	jobs_b->time_start = time(0);
	jobs_b->time_work = 0;
}

size_t			ft_42sh_task_load_start(register t_main_42sh *array,
register t_task *task, register t_task_load_fd *fds, register char **arg)
{
	t_jobs						*jobs_b;
	t_jobs						*jobs_e;

	if ((jobs_b = ft_malloc(sizeof(t_jobs) * task->copies)) == 0)
		return (ft_42sh_task_load_start_critical(task, TASK_LOG_MEMORY));
	task->jobs = jobs_b;
	jobs_e = &jobs_b[task->copies];
	ft_memset(task->jobs, 0, sizeof(t_jobs) * task->copies);
	if (array->task.b_init == 1 && task->on_start == 0)
		return (ft_42sh_task_load_on_start(jobs_b, jobs_e, task));
	if (ft_42sh_task_load_start_fd(task, fds) == 0)
		return (fn_finish(task));
	while (jobs_b < jobs_e)
	{
		if ((jobs_b->pid = fn_while(array, task, fds, arg)) != 0)
		{
			fn_set(jobs_b);
			jobs_b->retries = fds->retries;
			ptrace(PT_DETACH, jobs_b->pid, 0, 0);
		}
		else
			jobs_b->status_task = status_task_fail;
		jobs_b++;
	}
	return (1);
}

size_t			ft_42sh_task_load_start_singl(register t_main_42sh *array,
register t_task *task, register t_task_load_fd *fds, register char **arg)
{
	t_jobs						*jobs_b;
	pid_t						pid;

	jobs_b = fds->jobs_b;
	if (ft_42sh_task_load_start_fd(task, fds) == 0)
	{
		jobs_b->status_task = status_task_fail;
		return (fn_finish(task));
	}
	if ((pid = fn_while(array, task, fds, arg)) != 0)
	{
		jobs_b->time_start = time(0);
		jobs_b->time_work = 0;
		jobs_b->retries = fds->retries;
		ptrace(PT_DETACH, pid, 0, 0);
		jobs_b->status_task = status_task_start;
		jobs_b->pid = pid;
	}
	else
	{
		jobs_b->status_task = status_task_fail;
		jobs_b->pid = -1;
	}
	return (1);
}