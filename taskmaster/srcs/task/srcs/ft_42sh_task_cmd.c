/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

void			ft_42sh_task_set_fd(register t_main_42sh *array)
{
	int							fd;

	if (ft_42sh_pipe_test_fd(array, (fd = array->out.fd)) == 0)
		fd = -1;
	set_fd_out(fd);
	if (ft_42sh_pipe_test_fd(array, (fd = array->err.fd)) == 0)
		fd = -1;
	set_fd_err(fd);
}

static void		fn_while(register t_main_42sh *array,
register char **lp_arg, t_task_find_cmd *lp, register void *cmp)
{
	register void				*tmp;

	while ((tmp = lp[0].cmd) != 0)
	{
		if (ft_strcmp(tmp, cmp) == 0)
		{
			pthread_mutex_lock(&array->task.mutex);
			if (array->task.b_reload == 0)
			{
				array->task.b_cmd = 1;
				pthread_mutex_unlock(&array->task.mutex);
				lp[0].f(array, lp_arg);
				array->task.b_cmd = 0;
				return ;
			}
			pthread_mutex_unlock(&array->task.mutex);
			return (ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""
			TASK_BULTIN":"TASK_RESET" "TASK_BOLD, cmp,
			TASK_RESET"Wait configuration reload in progress"));
		}
		lp++;
	}
	ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN":"
	TASK_RESET" "TASK_BOLD, cmp, TASK_RESET""TASK_NOT_CMD);
}

static void		fn_finish(register t_main_42sh *array,
register char **lp_arg, t_task_find_cmd *lp)
{
	register void				*cmp;

	if ((cmp = (void *)lp_arg[0]) == 0)
	{
		ft_42sh_dsp_err_msg_adds(array, TASK_ERROR_COLOR""TASK_BULTIN,
		"", ": "TASK_RESET""TASK_TASK);
		return ;
	}
	ft_42sh_task_set_fd(array);
	lp_arg++;
	fn_while(array, lp_arg, lp, cmp);
}

void			ft_42sh_task_cmd(register t_main_42sh *array,
register char **lp_arg)
{
	static t_task_find_cmd		find_cmd[] = {
	{TASK_CMD_HELP, &ft_42sh_task_cmd_help},
	{TASK_CMD_LOAD, &ft_42sh_task_cmd_load},
	{TASK_CMD_RELOAD, &ft_42sh_task_cmd_reload},
	{TASK_CMD_PRINT, &ft_42sh_task_cmd_print},
	{TASK_CMD_DELETE, &ft_42sh_task_cmd_delete},
	{TASK_CMD_STATUS, &ft_42sh_task_cmd_status},
	{TASK_CMD_PAUSE, &ft_42sh_task_cmd_pause},
	{TASK_CMD_STOP, &ft_42sh_task_cmd_stop},
	{TASK_CMD_RESUME, &ft_42sh_task_cmd_resume},
	{TASK_CMD_RUN, &ft_42sh_task_cmd_run},
	{TASK_CMD_RESTART, &ft_42sh_task_cmd_restart},
	{(char *)0, (void *)0}};

	fn_finish(array, lp_arg, &find_cmd[0]);
}