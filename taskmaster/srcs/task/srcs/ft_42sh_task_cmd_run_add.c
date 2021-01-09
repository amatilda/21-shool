/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_run_add.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

void			ft_42sh_task_cmd_run_kill(register t_main_42sh *array,
register t_list *task_list, register t_task *task,
register t_jobs *jobs_b)
{
	t_status_task								status_task;

	if ((status_task = jobs_b->status_task) == status_task_run ||
	status_task == status_task_start)
	{
		return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" Failed job %s pid %d to run - runung.\n", task->name, jobs_b->pid));
	}
	else if (status_task == status_task_quits)
	{
		return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" Failed job %s pid %d to run - quits.\n", task->name, jobs_b->pid));
	}
	else if (status_task == status_task_stop)
	{
		return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" Failed job %s pid %d to run - pause.\n", task->name, jobs_b->pid));
	}
	ft_42sh_task_load_singl(array, task_list, task, jobs_b);
}

void			ft_42sh_task_cmd_run_all(register t_main_42sh *array,
register t_list *task_list, register t_task *task)
{
	register t_jobs						*jobs_b;
	register t_jobs						*jobs_e;

	jobs_b = task->jobs;
	if (jobs_b == 0)
	{
		return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" Failed job %s to run.\n", task->name));
	}
	jobs_e = &jobs_b[task->copies];
	while (jobs_b < jobs_e)
	{
		ft_42sh_task_cmd_run_kill(array, task_list, task, jobs_b);
		jobs_b++;
	}
}
