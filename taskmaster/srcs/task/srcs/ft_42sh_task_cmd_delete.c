/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_delete.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void		fn_wait(register t_main_42sh *array,
register size_t time_wait)
{
	char					buffer[200];

	sprintf(&buffer[0],
	"You will have to wait at least %zu seconds"
	" - until all tasks complete their work\n", time_wait);
	ft_write_buffer_str_zero(&array->out, &buffer[0]);
	ft_write_buffer(&array->out);
	sleep(1);
}

static size_t	fn_jobs_wait(register t_task *task,
register size_t time_wait)
{
	register size_t						tempos;
	register t_jobs						*jobs_b;
	register t_jobs						*jobs_e;

	if ((jobs_b = task->jobs) == 0)
		return (time_wait);
	jobs_e = &jobs_b[task->copies];
	while (jobs_b < jobs_e)
	{
		if (jobs_b->status_task == status_task_quits)
		{
			if ((int)jobs_b->time_work > task->stop_waiting)
				tempos = 1;
			else
				tempos = task->stop_waiting - (int)jobs_b->time_work;
			if (tempos > time_wait)
				time_wait = tempos;
		}
		jobs_b++;
	}
	return (time_wait);
}

void			ft_42sh_task_cmd_delete_wait(register t_main_42sh *array)
{
	register t_list				*task_list;
	register t_list				*task_list_tmp;
	register size_t				time_wait;

	if ((task_list_tmp = array->task.task_list) == 0)
		return ;
	while (0xFF)
	{
		task_list = task_list_tmp;
		time_wait = 0;
		while (task_list != 0)
		{
			time_wait = fn_jobs_wait(task_list->task, time_wait);
			task_list = task_list->next;
		}
		if (time_wait == 0)
			return ;
		fn_wait(array, time_wait);
	}
}

void			ft_42sh_task_cmd_delete(register t_main_42sh *array,
register char **lp_arg)
{
	register t_list				*task_list;

	if (ft_42sh_task_cmd_other_to_many(array, lp_arg, TASK_CMD_DELETE) == 0)
		return ;
	if ((task_list = array->task.task_list) != 0)
	{
		array->task.b_delete = 1;
		ft_42sh_task_cmd_stop(array, lp_arg);
		ft_42sh_task_cmd_delete_wait(array);
		pthread_mutex_lock(&array->task.mutex);
		ft_42sh_task_delete(array);
		pthread_mutex_unlock(&array->task.mutex);
		array->task.b_delete = 0;
	}
	else
	{
		ft_42sh_dsp_err_msg(array, TASK_ERROR_COLOR""TASK_BULTIN" "
		TASK_CMD_DELETE": "TASK_NOT_TASK""TASK_RESET""TASK_RELOAD_LOAD);
	}
}
