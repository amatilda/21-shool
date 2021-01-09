/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_reload_stop.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

void			ft_42sh_task_cmd_reload_stop(register t_main_42sh *array,
register t_list *task_list_old, register t_list *task_list_new)
{
	register t_list					*task_list_new_tmp;

	while (task_list_old != 0)
	{
		task_list_new_tmp = task_list_new;
		while (task_list_new_tmp != 0)
		{
			if (ft_strcmp(task_list_new_tmp->task->name,
			task_list_old->task->name) == 0)
				break ;
			task_list_new_tmp = task_list_new_tmp->next;
		}
		if (task_list_new_tmp == 0 || task_list_new_tmp->task->remake == 0)
		{
			pthread_mutex_lock(&array->task.mutex);
			ft_42sh_task_cmd_stop_all(task_list_old->task, time(0));
			pthread_mutex_unlock(&array->task.mutex);
		}
		task_list_old = task_list_old->next;
	}
	ft_42sh_task_cmd_delete_wait(array);
}

void			ft_42sh_task_cmd_reload_move_jobs(register
t_list *task_list_old, register t_list *task_list_new)
{
	register t_list					*task_list_old_tmp;

	while (task_list_new != 0)
	{
		task_list_old_tmp = task_list_old;
		while (task_list_old_tmp != 0)
		{
			if (ft_strcmp(task_list_old_tmp->task->name,
			task_list_new->task->name) == 0)
				break ;
			task_list_old_tmp = task_list_old_tmp->next;
		}
		if (task_list_old_tmp != 0 && task_list_old_tmp->task->copies ==
		task_list_new->task->copies)
		{
			task_list_new->task->jobs = task_list_old_tmp->task->jobs;
			task_list_old_tmp->task->jobs = 0;
		}
		else
			task_list_new->task->remake = -1;
		task_list_new = task_list_new->next;
	}
}

void			ft_42sh_task_cmd_reload_start(register t_main_42sh *array,
register t_list *task_list_new)
{
	ft_write_buffer_str_zero(&array->out,
	"Now starting new and changed tasks - it may take some time.\n");
	ft_write_buffer(&array->out);
	while (task_list_new != 0)
	{
		if (task_list_new->task->remake == 0)
		{
			task_list_new->task->remake = 1;
			ft_42sh_task_cmd_run_all(array, task_list_new, task_list_new->task);
		}
		else if (task_list_new->task->remake == -1)
		{
			task_list_new->task->remake = 1;
			ft_42sh_task_load_one(array, task_list_new);
		}
		task_list_new = task_list_new->next;
	}
}
