/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_exe.h"

static size_t	fn_set(register t_main_42sh *array,
register t_jobs_42sh *tmp, register size_t b_test)
{
	if (b_test == '&')
	{
		array->pr.b_auto_view = 1;
		b_test = AUTO_TYPE_RUN_42SH;
	}
	else
	{
		array->pr.jobs_current = tmp;
		b_test = 0;
		if (ioctl(array->fd, TIOCSETA, &array->tty) == -1)
			ft_42sh_exit(E_IOTL_CODE_42SH);
	}
	return (b_test);
}

static size_t	fn_finish(register t_main_42sh *array,
register size_t tempos, register size_t out)
{
	if (tempos != 0)
	{
		array->env.exit_status->number = (unsigned char)tempos;
		return (0);
	}
	return (out);
}

size_t			ft_42sh_exe(register t_main_42sh *array,
register size_t b_test)
{
	register t_jobs_42sh		*jobs;
	register t_jobs_42sh		*tmp;
	register size_t				tempos;

	array->pr.jobs_last = 0;
	jobs = array->pr.jb.last;
	tempos = jobs->count;
	tmp = jobs;
	while (--tempos > 0)
		tmp = tmp->prev;
	ft_write_buffer(&array->out);
	b_test = fn_set(array, tmp, b_test);
	tempos = ft_42sh_exe_while(array, tmp, b_test);
	if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
		return (ft_42sh_exe_wait_script(array, tmp, jobs, b_test));
	if ((b_test & AUTO_TYPE_RUN_42SH) == 0)
		return (fn_finish(array, tempos, ft_42sh_exe_wait(array, tmp, jobs)));
	if (ioctl(array->fd, TIOCSPGRP, &array->pr.pid_main) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	if (ioctl(array->fd, TIOCSETA, &array->tty_change) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	if (array->pr.b_auto_view != 0)
	{
		array->pr.b_auto_view = 0;
		ft_42sh_jobs_msg(array, tmp, JOBS_MSG_ID_RUN_42SH);
		ft_write_buffer(&array->out);
	}
	return (fn_finish(array, tempos, 1));
}
