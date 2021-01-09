/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_auto.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void		fn_auto_test(register t_main_42sh *array,
register t_list *task_list,
register t_jobs *jobs_b, register t_task *task)
{
	register t_status_task		status_task;

	if ((status_task = jobs_b->status_task) == status_task_start ||
	status_task == status_task_run ||
	status_task == status_task_not_auto_start ||
	status_task == status_task_quits || status_task == status_task_stop)
		return ;
	else if (task->restart != ALWAYS)
	{
		if (task->restart != ON_CRASH && (status_task == status_task_fail ||
		status_task == status_task_completed_falled))
			return ;
		else if (task->restart != ON_GOOD && status_task == status_task_completed)
			return ;
	}
	ft_42sh_task_load_singl(array, task_list, task, jobs_b);
}

void			ft_42sh_task_auto(register t_main_42sh *array)
{
	register t_list				*task_list;
	register t_task				*task;
	register t_jobs				*jobs_b;
	register t_jobs				*jobs_e;

	if ((task_list = array->task.task_list) == 0 || array->task.b_delete == 1)
		return ;
	while (task_list != 0)
	{
		task = task_list->task;
		jobs_b = task->jobs;
		if (jobs_b != 0 && task->restart != NEVER)
		{
			jobs_e = &jobs_b[task->copies];
			while (jobs_b < jobs_e)
			{
				fn_auto_test(array, task_list, jobs_b, task);
				jobs_b++;
			}
		}
		task_list = task_list->next;
	}
}