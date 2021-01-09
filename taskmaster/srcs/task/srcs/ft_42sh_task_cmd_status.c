/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_status.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void		fn_name(register t_main_42sh *array,
register char **lp_arg, register t_list *task_list)
{
	while (task_list != 0)
	{
		if (ft_strcmp(task_list->task->name, lp_arg[0]) == 0)
		{
			ft_42sh_task_cmd_status_pre_table(array);
			ft_42sh_task_cmd_status_col(array, task_list->task);
			ft_write_buffer_str_zero(&array->out, "\n");
			return ;
		}
		task_list = task_list->next;
	}
	ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN" ",
	TASK_CMD_STATUS": "TASK_NOT_NAME_JOB""TASK_RESET, lp_arg[0]);
}

static void		fn_while(register t_main_42sh *array,
register char **lp_arg, register t_list *task_list)
{
	while (lp_arg[0] != 0)
		fn_name(array, lp_arg++, task_list);
	pthread_mutex_unlock(&array->task.mutex);
}

static void		fn_while_finish(register t_main_42sh *array,
register t_list *task_list)
{
	while (task_list != 0)
	{
		ft_42sh_task_cmd_status_pre_table(array);
		ft_42sh_task_cmd_status_col(array, task_list->task);
		ft_write_buffer_str_zero(&array->out, "\n");
		task_list = task_list->next;
	}
}

void			ft_42sh_task_cmd_status(register t_main_42sh *array,
register char **lp_arg)
{
	register t_list				*task_list;

	pthread_mutex_lock(&array->task.mutex);
	if ((task_list = array->task.task_list) == 0)
	{
		ft_42sh_dsp_err_msg(array, TASK_ERROR_COLOR""TASK_BULTIN" "
		TASK_CMD_STATUS": "TASK_NOT_TASK""TASK_RESET""TASK_RELOAD_LOAD);
		pthread_mutex_unlock(&array->task.mutex);
		return ;
	}
	if (lp_arg[0] != 0)
		return (fn_while(array, lp_arg, task_list));
	if (ft_42sh_task_cmd_status_pre_test(array) == 0)
	{
		pthread_mutex_unlock(&array->task.mutex);
		return ;
	}
	ft_42sh_task_cmd_status_pre_total(array);
	fn_while_finish(array, task_list);
	pthread_mutex_unlock(&array->task.mutex);
}
