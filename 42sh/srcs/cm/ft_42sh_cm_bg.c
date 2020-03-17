/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_bg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_cm.h"

static void			fn_corection(register t_jobs_42sh *jobs)
{
	while (0xFF)
	{
		jobs->b_type = jobs->b_type | AUTO_TYPE_RUN_42SH;
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
}

static size_t		fn_test(register t_jobs_42sh *jobs)
{
	register size_t				b_test;

	b_test = 0;
	while (0xFF)
	{
		b_test = b_test | jobs->b_type;
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
	return (b_test);
}

static size_t		fn_flag(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	if (jobs == array->pr.jobs_plus)
		return (JOBS_MSG_ID_42SH | JOBS_MSG_PLUS_42SH |
		JOBS_MSG_CONTINUED_42SH);
	else if (jobs == array->pr.jobs_minus)
		return (JOBS_MSG_ID_42SH | JOBS_MSG_MINUS_42SH |
		JOBS_MSG_CONTINUED_42SH);
	return (JOBS_MSG_ID_42SH | JOBS_MSG_CONTINUED_42SH);
}

static void			fn_process(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	ft_42sh_jobs_up(array, jobs);
	ft_42sh_jobs_msg(array, jobs, fn_flag(array, jobs));
	fn_corection(jobs);
	ft_write_buffer(&array->out);
	array->pr.b_auto_view = 0;
	ft_42sh_cm_jobs_killgrp(jobs, SIGCONT);
	if (ioctl(array->fd, TIOCSPGRP, &array->pr.pid_main) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	if (ioctl(array->fd, TIOCSETA, &array->tty_change) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
}

void				ft_42sh_cm_bg(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char		*str;
	register t_jobs_42sh		*jobs;

	if ((array->b_location & LOCATION_FORK_42SH) != 0)
		return (ft_42sh_dsp_err_msg(array, MSG_BG_NOT_CONT_42SH));
	if ((str = (void *)lp_arg[0]) == 0)
	{
		ft_42sh_jobs_set_current(array);
		if ((jobs = ft_42sh_cm_jobs_find(array, (void *)"%%", JOBS_MSG_BG_42SH)) == 0)
			return ;
		if ((fn_test(jobs) & AUTO_TYPE_RUN_42SH) != 0)
			return (ft_42sh_dsp_err_msg(array, MSG_BG_ALREDY_42SH));
		fn_process(array, jobs);
		return ;
	}
	while ((str = (void *)lp_arg++[0]) != 0)
	{
		ft_42sh_jobs_set_current(array);
		if ((jobs = ft_42sh_cm_jobs_find(array, str, JOBS_MSG_BG_42SH)) == 0)
			return ;
		if ((fn_test(jobs) & AUTO_TYPE_RUN_42SH) != 0)
			return (ft_42sh_dsp_err_msg(array, MSG_BG_ALREDY_42SH));
		fn_process(array, jobs);
	}
}