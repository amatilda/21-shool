/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_fg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_cm.h"

static void			fn_corection(register t_jobs_42sh *jobs,
register size_t b_test)
{
	if ((b_test & AUTO_TYPE_RUN_42SH) == 0)
		return ;
	while (0xFF)
	{
		if ((jobs->b_type & AUTO_TYPE_RUN_42SH) != 0)
			jobs->b_type = jobs->b_type ^ AUTO_TYPE_RUN_42SH;
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
}

static size_t		fn_flag(register t_main_42sh *array,
register t_jobs_42sh *jobs, register size_t b_test)
{
	if ((b_test & AUTO_TYPE_RUN_42SH) == 0)
		b_test = JOBS_MSG_ID_42SH | JOBS_MSG_CONTINUED_42SH;
	else
		b_test = JOBS_MSG_ID_42SH;
	if (jobs == array->pr.jobs_plus)
		return (b_test | JOBS_MSG_PLUS_42SH);
	else if (jobs == array->pr.jobs_minus)
		return (b_test | JOBS_MSG_MINUS_42SH);
	return (b_test | JOBS_MSG_CONTINUED_42SH);
}

static void			fn_process(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	register t_jobs_42sh		*last;
	register t_jobs_42sh		*tmp;
	register size_t				b_test;

	array->pr.jobs_current = jobs;
	tmp = jobs;
	b_test = 0;
	while (0xFF)
	{
		last = tmp;
		b_test = b_test | tmp->b_type;
		if ((tmp = tmp->next) == 0 || tmp->count == 1)
			break ;
	}
	ft_42sh_jobs_up(array, jobs);
	ft_42sh_jobs_msg(array, jobs, fn_flag(array, jobs, b_test));
	fn_corection(jobs, b_test);
	ft_write_buffer(&array->out);
	if (ioctl(array->fd, TIOCSETA, &array->tty) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	if (ioctl(array->fd, TIOCSPGRP, &jobs->pid_view) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	if ((b_test & AUTO_TYPE_RUN_42SH) == 0)
		ft_42sh_cm_jobs_killgrp(jobs, SIGCONT);
	ft_42sh_exe_wait(array, jobs, last);
}

void				ft_42sh_cm_fg(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char		*str;
	register t_jobs_42sh		*jobs;

	if ((array->b_location & LOCATION_FORK_42SH) != 0)
		return (ft_42sh_dsp_err_msg(array, MSG_FG_NOT_CONT_42SH));
	if ((str = (void *)lp_arg[0]) == 0)
	{
		ft_42sh_jobs_set_current(array);
		if ((jobs = ft_42sh_cm_jobs_find(array, (void *)"%%",
		JOBS_MSG_FG_42SH)) == 0)
			return ;
		fn_process(array, jobs);
		return ;
	}
	while ((str = (void *)lp_arg++[0]) != 0)
	{
		ft_42sh_jobs_set_current(array);
		if ((jobs = ft_42sh_cm_jobs_find(array, str, JOBS_MSG_FG_42SH)) == 0)
			return ;
		fn_process(array, jobs);
	}
}
