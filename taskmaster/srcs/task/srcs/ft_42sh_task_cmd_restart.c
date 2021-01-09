/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_restart.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void		fn_restart_name_finish(register t_main_42sh *array,
register char **lp_arg, register t_list *task_list)
{
	int									id;
	register t_jobs						*jobs_b;

	if ((id = ft_atoi(lp_arg[1])) >= task_list->task->copies)
	{
		return (ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN
		" ", TASK_CMD_RESTART": "TASK_NOT_NAME_JOB""TASK_RESET, lp_arg[1]));
	}
	jobs_b = task_list->task->jobs;
	if (jobs_b == 0)
	{
		return (task_log("["TASK_LOG_EVENT_CORE"] "TASK_LOG_ERROR
		" Failed job %s to restart.\n", task_list->task->name));
	}
	ft_42sh_task_cmd_stop(array, lp_arg);
	ft_42sh_task_cmd_delete_wait(array);
	ft_42sh_task_cmd_run(array, lp_arg);
}

static void		fn_restart_name(register t_main_42sh *array,
register char **lp_arg, register t_list *task_list)
{
	while (task_list != 0)
	{
		if (ft_strcmp(task_list->task->name, lp_arg[0]) == 0)
			break ;
		task_list = task_list->next;
	}
	if (task_list == 0)
	{
		return (ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN
		" ", TASK_CMD_RESTART": "TASK_NOT_NAME_JOB""TASK_RESET, lp_arg[0]));
	}
	if (lp_arg[1] == 0)
	{
		ft_42sh_task_cmd_stop(array, lp_arg);
		ft_42sh_task_cmd_delete_wait(array);
		ft_42sh_task_cmd_run(array, lp_arg);
		return ;
	}
	if (lp_arg[2] != 0)
	{
		return (ft_42sh_dsp_err_msg(array, TASK_ERROR_COLOR""TASK_BULTIN" "
		TASK_CMD_RESTART": "TASK_TOO_MANY_ARG""TASK_RESET""TASK_RELOAD_LOAD));
	}
	fn_restart_name_finish(array, lp_arg, task_list);
}

void			ft_42sh_task_cmd_restart(register t_main_42sh *array,
register char **lp_arg)
{
	register t_list				*task_list;

	if ((task_list = array->task.task_list) == 0)
	{
		ft_42sh_dsp_err_msg(array, TASK_ERROR_COLOR""TASK_BULTIN" "
		TASK_CMD_RESTART": "TASK_NOT_TASK""TASK_RESET""TASK_RELOAD_LOAD);
		return ;
	}
	if (lp_arg[0] != 0)
	{
		fn_restart_name(array, lp_arg, task_list);
		return ;
	}
	ft_42sh_task_cmd_stop(array, lp_arg);
	ft_42sh_task_cmd_delete_wait(array);
	ft_42sh_task_cmd_run(array, lp_arg);
}
