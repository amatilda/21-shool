/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_other.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

void			*ft_42sh_task_cmd_other_load_test(register t_main_42sh *array,
register char **lp_arg, void *name)
{
	register void				*str;

	if ((str = lp_arg++[0]) == 0)
	{
		ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN" ",
		name, ": "TASK_FILE_PATH""TASK_RESET);
		return (0);
	}
	if (lp_arg[0] != 0)
	{
		ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN" ",
		name, ": "TASK_TOO_MANY_ARG""TASK_RESET);
		return (0);
	}
	return (str);
}

size_t			ft_42sh_task_cmd_other_to_many(register t_main_42sh *array,
register char **lp_arg, register void *name)
{
	if (lp_arg[0] != 0)
	{
		ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN" ",
		name, ": "TASK_TOO_MANY_ARG""TASK_RESET);
		return (0);
	}
	return (1);
}

void			ft_42sh_task_cmd_help(register t_main_42sh *array,
register char **lp_arg)
{
	if (ft_42sh_task_cmd_other_to_many(array, lp_arg, TASK_CMD_HELP) == 0)
		return ;
	conf_help();
}

void			ft_42sh_task_cmd_print(register t_main_42sh *array,
register char **lp_arg)
{
	register t_list				*task_list;

	if (ft_42sh_task_cmd_other_to_many(array, lp_arg, TASK_CMD_PRINT) == 0)
		return ;
	if ((task_list = array->task.task_list) != 0)
		print_tasks(task_list);
	else
	{
		ft_42sh_dsp_err_msg(array, TASK_ERROR_COLOR""TASK_BULTIN" "
		TASK_CMD_PRINT": "TASK_NOT_TASK""TASK_RESET""TASK_RELOAD_LOAD);
	}
}
