/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_bg_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

static void			fn_corection(register t_jobs_42sh *jobs)
{
	while (0xFF)
	{
		jobs->b_type = jobs->b_type | AUTO_TYPE_RUN_42SH;
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
}

static size_t		fn_flag(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	if (jobs == array->pr.jobs_plus)
		return (JOBS_MSG_ID_42SH | JOBS_MSG_PLUS_42SH |
		JOBS_MSG_CONTINUED_42SH);
	else if (jobs == array->pr.jobs_minus)
	{
		return (JOBS_MSG_ID_42SH | JOBS_MSG_MINUS_42SH |
		JOBS_MSG_CONTINUED_42SH);
	}
	return (JOBS_MSG_ID_42SH | JOBS_MSG_CONTINUED_42SH);
}

void				ft_42sh_cm_bg_process(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	ft_42sh_jobs_up(array, jobs);
	ft_42sh_jobs_msg(array, jobs, fn_flag(array, jobs));
	fn_corection(jobs);
	ft_write_buffer(&array->out);
	array->pr.b_auto_view = 0;
	ft_42sh_cm_jobs_killgrp(jobs, SIGCONT);
	if (ft_42sh_stub_ioctl(array, TIOCSPGRP, &array->pr.pid_main) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH, __FILE__, __func__, __LINE__);
	if (ft_42sh_stub_ioctl(array, TIOCSETA, &array->tty_change) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH, __FILE__, __func__, __LINE__);
}
