/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_status_pre.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

void		ft_42sh_task_cmd_status_pre_table(register t_main_42sh *array)
{
	register t_write_buff		*out;

	out = &array->out;
	ft_write_buffer_str_zero(out, PRTF_BOLT""TASK_COL_STATUS);
	ft_write_buffer_str_zero(out, TASK_COL_TIME);
	ft_write_buffer_str_zero(out, TASK_COL_RETRIES);
	ft_write_buffer_str_zero(out, TASK_COL_PID);
	ft_write_buffer_str_zero(out, TASK_COL_NAME);
	ft_write_buffer_str_zero(out, TASK_COL_PATCH"\n"PRTF_RESET);
}

size_t		ft_42sh_task_cmd_status_pre_test(register t_main_42sh *array)
{
	register size_t					min;
	register size_t					ws_col;

	min = sizeof(TASK_COL_STATUS) - 1 + sizeof(TASK_COL_TIME) - 1 +
	sizeof(TASK_COL_RETRIES) - 1 + sizeof(TASK_COL_PID) - 1
	+ sizeof(TASK_COL_NAME) - 1 + sizeof(TASK_COL_PATCH) - 1;
	if ((ws_col = array->ws.ws_col) > min)
		return (ws_col - min + sizeof(TASK_COL_PATCH) - 1);
	ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN" ",
		TASK_CMD_STATUS, ": "TASK_TERMINAL_NOT_SPACE""TASK_RESET);
	return (0);
}

static void	fn_total_count(register t_jobs *jobs_b, register t_jobs *jobs_e,
t_task_status_total *total)
{
	while (jobs_b < jobs_e)
	{
		if (jobs_b->status_task == status_task_fail)
			total->faill++;
		else if (jobs_b->status_task == status_task_start)
			total->starting++;
		else if (jobs_b->status_task == status_task_stop)
			total->stop++;
		else if (jobs_b->status_task == status_task_run)
			total->runing++;
		else if (jobs_b->status_task == status_task_completed)
			total->completed++;
		else if (jobs_b->status_task == status_task_completed_falled)
			total->completed_falled++;
		else if (jobs_b->status_task == status_task_quits)
			total->quits++;
		else if (jobs_b->status_task == status_task_not_auto_start)
			total->not_auto_start++;
		jobs_b++;
	}
}

static void	fn_total_print(register t_main_42sh *array,
t_task_status_total *total)
{
	uint8_t						buff[200];
	size_t						full;

	full = total->completed + total->stop + total->runing +
	total->starting + total->faill + total->critical + total->completed_falled
	+ total->not_auto_start;
	sprintf((char *)&buff[0], PRTF_BOLT""TASK_COL_STATUS_TXT_PRE_TOTAL"%zu "
	TASK_COL_STATUS_TXT_PRE_RUNING"%zu, "TASK_COL_STATUS_TXT_PRE_STARTING
	"%zu, "
	TASK_COL_STATUS_TXT_PRE_STOP"%zu, "TASK_COL_STATUS_TXT_PRE_COMLETED"%zu, "
	TASK_COL_STATUS_TXT_PRE_COMLETED_FAILED"%zu, "TASK_COL_STATUS_TXT_PRE_QUITS
	"%zu, "
	TASK_COL_STATUS_TXT_PRE_FAIL"%zu, "TASK_COL_STATUS_TXT_PRE_CRITICAL"%zu\n"
	PRTF_RESET,
	full, total->runing, total->starting, total->stop, total->completed,
	total->completed_falled, total->quits,
	total->faill, total->critical);
	ft_write_buffer_str_zero(&array->out, (char *)&buff[0]);
}

void		ft_42sh_task_cmd_status_pre_total(register t_main_42sh *array)
{
	register t_list				*task_list;
	register t_task				*task;
	t_task_status_total			total;
	register t_jobs				*jobs_b;

	ft_memset(&total, 0x0, sizeof(total));
	task_list = array->task.task_list;
	while (task_list != 0)
	{
		task = task_list->task;
		if ((jobs_b = task->jobs) == 0)
			total.critical = total.critical + task->copies;
		else
			fn_total_count(jobs_b, &jobs_b[task->copies], &total);
		task_list = task_list->next;
	}
	fn_total_print(array, &total);
}