/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe_wait_finish.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exe.h"

static void		fn_status(register t_main_42sh *array,
t_jobs_42sh *jobs_cl, int stat_loc)
{
	if ((jobs_cl->b_type & AUTO_TYPE_EXE_42SH) != 0 ||
	(jobs_cl->b_type & AUTO_TYPE_RUN_42SH) != 0)
	{
		if (WIFEXITED(stat_loc) != 0)
			stat_loc = WEXITSTATUS(stat_loc);
		else
		{
			if (WIFSIGNALED(stat_loc) != 0)
				stat_loc = 128 + WTERMSIG(stat_loc);
			else if (WIFSTOPPED(stat_loc) != 0)
				stat_loc = 128 + WSTOPSIG(stat_loc);
			else
				stat_loc = 128;
		}
	}
	array->env.exit_status->number = (unsigned char)stat_loc;
}

size_t			ft_42sh_exe_wait_finish(register t_main_42sh *array,
register t_jobs_42sh *jobs, t_jobs_42sh *jobs_cl, register size_t b_test)
{
	if ((b_test & JOBS_SUSPEND_42SH) != 0)
	{
		array->b_read = 1;
		array->tty_change.c_cc[VMIN] = 0;
		array->tty_change.c_cc[VTIME] = 1;
	}
	if ((array->b_location & LOCATION_SCRIPT_42SH) == 0)
	{
		if (ft_42sh_stub_ioctl(array, TIOCSPGRP, &array->pr.pid_main) == -1)
			ft_42sh_exit(E_IOTL_CODE_42SH, __FILE__, __func__, __LINE__);
	}
	if (ft_42sh_stub_ioctl(array, TIOCSETA, &array->tty_change) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH, __FILE__, __func__, __LINE__);
	if ((array->b_location & LOCATION_SCRIPT_42SH) == 0 &&
	array->b_quest_exit == 0 && (ft_42sh_dsp_position() & 0xFFFFFFFF) != 1)
		ft_write_buffer_str_zero(&array->out, PRTF_INVERT"%\n"PRTF_RESET);
	if ((b_test & JOBS_MSG_42SH) != 0)
		ft_42sh_jobs_msg(array, jobs, JOBS_MSG_PROC_42SH);
	fn_status(array, jobs_cl, jobs_cl->stat_loc);
	if ((b_test & JOBS_SUSPEND_42SH) == 0)
		ft_42sh_jobs_free_list_count(array, jobs_cl);
	return (((b_test & JOBS_STOP_42SH) != 0) ? 0 : 1);
}
