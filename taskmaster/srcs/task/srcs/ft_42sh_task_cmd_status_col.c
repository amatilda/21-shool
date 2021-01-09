/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd_status_col.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void		fn_jobs_naming(register t_main_42sh *array,
t_task *task)
{
	size_t								len;
	size_t								ws_col;

	if ((len = ft_strlen(task->name)) > (sizeof(TASK_COL_NAME) - 3))
		len = (sizeof(TASK_COL_NAME) - 3);
	ft_write_buffer_str(&array->out, task->name, len);
	ft_write_buffer_char(&array->out, ' ', (sizeof(TASK_COL_NAME) - 1) - len);
	ws_col = array->ws.ws_col - sizeof(TASK_COL_STATUS) - 1 +
	sizeof(TASK_COL_TIME) - 1 + sizeof(TASK_COL_RETRIES) - 1 +
	sizeof(TASK_COL_PID) - 1 + sizeof(TASK_COL_NAME) - 1;
	if ((len = ft_strlen(task->command)) > ws_col)
		len = ws_col;
	ft_write_buffer_str(&array->out, task->command, len);
	ft_write_buffer_str_zero(&array->out, "\n");
}

static void		fn_jobs_null_while(register t_main_42sh *array,
t_task *task)
{
	size_t						i;
	uint8_t						buff[200];

	sprintf((char *)&buff[0], "000/%03.3u  ", task->retries);
	i = task->copies;
	while (i-- != 0)
	{
		ft_write_buffer_str_zero(&array->out,
		PRTF_RED""TASK_COL_STATUS_TXT_CRITICAL""PRTF_RESET);
		ft_write_buffer_str_zero(&array->out, TASK_COL_TIME_TXT);
		ft_write_buffer_str_zero(&array->out, (char *)&buff[0]);
		ft_write_buffer_str_zero(&array->out, TASK_COL_PID_TXT);
		fn_jobs_naming(array, task);
	}
}

static void		fn_time_work(register t_main_42sh *array,
t_task *task, register t_jobs *jobs_b)
{
	uint8_t						buff[200];
	size_t						day;
	size_t						hour;
	size_t						min;
	size_t						time_work;

	time_work = jobs_b->time_work;
	day = time_work / (24 * 60 * 60);
	time_work = time_work - (day * (24 * 60 * 60));
	hour = time_work / (60 * 60);
	time_work = (time_work - (hour * (60 * 60)));
	min = time_work / (60);
	sprintf((char *)&buff[0],
	"%03.3zu.%02.2zu.%02.2zu.%02.2zu  %03.3u/%03.3u  %-10d  ", day, hour,
	min, (time_work - (min * (60))), task->retries - jobs_b->retries,
	task->retries, jobs_b->pid);
	ft_write_buffer_str_zero(&array->out, (char *)&buff[0]);
	fn_jobs_naming(array, task);
}

static char		*fn_get_msg(register t_jobs *jobs_b)
{
	register char						*tmp;

	if (jobs_b->status_task == status_task_fail)
		tmp = PRTF_RED""TASK_COL_STATUS_TXT_FAIL""PRTF_RESET;
	else if (jobs_b->status_task == status_task_start)
		tmp = TASK_COL_STATUS_TXT_STARTING;
	else if (jobs_b->status_task == status_task_stop)
		tmp = TASK_COL_STATUS_TXT_STOP;
	else if (jobs_b->status_task == status_task_quits)
		tmp = TASK_COL_STATUS_TXT_QUITS;
	else if (jobs_b->status_task == status_task_not_auto_start)
		tmp = TASK_COL_STATUS_TXT_NOT_ON_START;
	else if (jobs_b->status_task == status_task_run)
		tmp = PRTF_GREEN""TASK_COL_STATUS_TXT_RUNING""PRTF_RESET;
	else if (jobs_b->status_task == status_task_completed)
		tmp = PRTF_PURPLE""TASK_COL_STATUS_TXT_COMLETED""PRTF_RESET;
	else if (jobs_b->status_task == status_task_completed_falled)
		tmp = PRTF_RED""TASK_COL_STATUS_TXT_COMLETED_FALED""PRTF_RESET;
	else
		tmp = "unknow";
	return (tmp);
}

void			ft_42sh_task_cmd_status_col(register t_main_42sh *array,
t_task *task)
{
	register t_jobs						*jobs_b;
	register char						*tmp;

	if ((jobs_b = task->jobs) == 0)
		return (fn_jobs_null_while(array, task));
	while (jobs_b < &task->jobs[task->copies])
	{
		tmp = fn_get_msg(jobs_b);
		ft_write_buffer_str_zero(&array->out, tmp);
		fn_time_work(array, task, jobs_b);
		jobs_b++;
	}
}
