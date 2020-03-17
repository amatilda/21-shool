/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_msg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_jobs.h"

static void			fn_run(register t_write_buff *out,
register t_jobs_42sh *jobs, register size_t b_test)
{
	ft_42sh_jobs_msg_id(out, jobs, b_test);
	while (0xFF)
	{
		ft_42sh_jobs_msg_pid(out, jobs->pid_view);
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
	ft_write_buffer_str_zero(out, "\n");
}

static void			fn_msg_pre(register t_write_buff *out,
register t_jobs_42sh *jobs, register size_t b_test)
{
	if ((b_test & JOBS_MSG_PROC_42SH) != 0)
		return (ft_write_buffer_str_zero(out, MSG_JOBS_PROC_42SH));
	if ((b_test & JOBS_MSG_ID_42SH) != 0)
		ft_42sh_jobs_msg_id(out, jobs, b_test);
	if ((b_test & JOBS_MSG_ID_PID_42SH) != 0)
		ft_42sh_jobs_msg_pid(out, jobs->pid_view);
}

static void			fn_central(register t_write_buff *out,
register t_jobs_42sh *jobs, register size_t b_test)
{
	if ((b_test & JOBS_MSG_PROC_42SH) != 0)
		return (ft_write_buffer_str_zero(out, MSG_JOBS_PROC_42SH));
	if ((b_test & JOBS_MSG_ID_42SH) != 0)
		ft_write_buffer_char(out, ' ', 7);
	if ((b_test & JOBS_MSG_ID_PID_ALL_42SH) != 0)
		return (ft_42sh_jobs_msg_pid(out, jobs->pid_view));
	if ((b_test & JOBS_MSG_ID_PID_GRUP_42SH) != 0)
		ft_write_buffer_char(out, ' ', 6);
}

void				ft_42sh_jobs_msg(register t_main_42sh *array,
register t_jobs_42sh *jobs, register size_t b_test)
{
	register t_write_buff		*out;

	out = &array->out;
	if ((b_test & JOBS_MSG_ID_RUN_42SH) != 0)
		return (fn_run(out, jobs, b_test));
	fn_msg_pre(out, jobs, b_test);
	if (jobs->pid_view == 0 || (jobs->b_type & AUTO_TYPE_RUN_42SH) != 0 ||
	WIFEXITED(jobs->stat_loc) != 0)
		jobs = ft_42sh_jobs_msg_exit(out, jobs, b_test);
	else
		jobs = ft_42sh_jobs_msg_signal(array, out, jobs, b_test);
	ft_write_buffer_str_zero(out, "\n");
	while (jobs != 0)
	{
		fn_central(out, jobs, b_test);
		if (jobs->pid_view == 0 || (jobs->b_type & AUTO_TYPE_RUN_42SH) != 0 ||
		WIFEXITED(jobs->stat_loc) != 0)
			jobs = ft_42sh_jobs_msg_exit(out, jobs, b_test);
		else
			jobs = ft_42sh_jobs_msg_signal(array, out, jobs, b_test);
		ft_write_buffer_str_zero(out, "\n");
	}
}
