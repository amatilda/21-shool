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

static void			fn_while(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char		*str;
	register t_jobs_42sh		*jobs;

	while ((str = (void *)lp_arg++[0]) != 0)
	{
		ft_42sh_jobs_set_current(array);
		if ((jobs = ft_42sh_cm_jobs_find(array, str, JOBS_MSG_BG_42SH)) == 0)
			return ;
		if ((fn_test(jobs) & AUTO_TYPE_RUN_42SH) != 0)
		{
			return (ft_42sh_dsp_err_msg(array,
			WAR_42SH""MSG_BG_ALREDY_TXT_42SH""PRTF_RESET));
		}
		ft_42sh_cm_bg_process(array, jobs);
	}
}

void				ft_42sh_cm_bg(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char		*str;
	register t_jobs_42sh		*jobs;

	if ((array->b_location & LOCATION_FORK_42SH) != 0)
	{
		return (ft_42sh_dsp_err_msg(array,
		WAR_42SH""MSG_BG_NOT_CONT_TXT_42SH""PRTF_RESET));
	}
	if ((str = (void *)lp_arg[0]) == 0)
	{
		ft_42sh_jobs_set_current(array);
		if ((jobs = ft_42sh_cm_jobs_find(array, (void *)"%%",
		JOBS_MSG_BG_42SH)) == 0)
			return ;
		if ((fn_test(jobs) & AUTO_TYPE_RUN_42SH) != 0)
		{
			return (ft_42sh_dsp_err_msg(array,
			WAR_42SH""MSG_BG_ALREDY_TXT_42SH""PRTF_RESET));
		}
		ft_42sh_cm_bg_process(array, jobs);
		return ;
	}
	fn_while(array, lp_arg);
}
