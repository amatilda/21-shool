/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_jobs_find.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

static t_jobs_42sh		*fn_test(register t_main_42sh *array,
register size_t b_view, register unsigned char litter)
{
	register t_jobs_42sh		*jobs;

	if (litter == '-')
	{
		if ((jobs = array->pr.jobs_minus) == 0)
		{
			ft_42sh_dsp_err_msg(array,
			WAR_42SH""MSG_JOBS_NOT_PREV_TXT_42SH""PRTF_RESET);
			return (0);
		}
		if ((b_view & JOBS_MSG_JOBS_42SH) != 0)
			ft_42sh_jobs_msg(array, jobs, b_view | JOBS_MSG_MINUS_42SH);
		return (jobs);
	}
	if ((jobs = array->pr.jobs_plus) == 0)
	{
		ft_42sh_dsp_err_msg(array,
		WAR_42SH""MSG_JOBS_NOT_CUR_TXT_42SH""PRTF_RESET);
		return (0);
	}
	if ((b_view & JOBS_MSG_JOBS_42SH) != 0)
		ft_42sh_jobs_msg(array, jobs, b_view | JOBS_MSG_PLUS_42SH);
	return (jobs);
}

static t_jobs_42sh		*fn_stub(register t_main_42sh *array,
register unsigned char *str, register size_t b_view,
register unsigned char litter)
{
	register t_jobs_42sh		*jobs;

	jobs = 0;
	if (litter >= 0x30 && litter <= 0x39)
	{
		if ((jobs = ft_42sh_cm_jobs_number(array, str, b_view)) == 0)
		{
			ft_42sh_dsp_err_msg_add_n(array,
			WAR_42SH""MSG_JOBS_NOT_TXT_42SH""PRTF_RESET, (void *)str, 0);
			return (0);
		}
	}
	else
	{
		if ((jobs = ft_42sh_cm_jobs_str(array, str, b_view)) == 0)
		{
			ft_42sh_dsp_err_msg_add_n(array,
			WAR_42SH""MSG_JOBS_NOT_TXT_42SH""PRTF_RESET, (void *)str, 0);
			return (0);
		}
	}
	return (jobs);
}

static t_jobs_42sh		*fn_finish(register t_jobs_42sh *jobs)
{
	register size_t				count;

	count = jobs->count;
	while (count-- > 1)
		jobs = jobs->prev;
	return (jobs);
}

static t_jobs_42sh		*fn_err(register t_main_42sh *array,
register unsigned char *str)
{
	ft_42sh_dsp_err_msg_add_n(array,
	WAR_42SH""MSG_JOBS_NOT_TXT_42SH""PRTF_RESET, (void *)str - 1, 0);
	return (0);
}

t_jobs_42sh				*ft_42sh_cm_jobs_find(register t_main_42sh *array,
register unsigned char *str, register size_t b_view)
{
	register unsigned char		litter;
	register t_jobs_42sh		*jobs;

	if ((litter = str++[0]) == 0)
	{
		if ((jobs = ft_42sh_cm_jobs_str(array, str - 1, b_view)) == 0)
			return (fn_err(array, str));
	}
	else if (litter != '%')
	{
		ft_42sh_dsp_err_msg_add_n(array,
		WAR_42SH""MSG_JOBS_NOT_TXT_42SH""PRTF_RESET, (void *)str, 0);
		return (0);
	}
	if ((litter = str[0]) == 0 || litter == '%' || litter == '+' ||
	litter == '-')
	{
		if ((jobs = fn_test(array, b_view, litter)) == 0)
			return (0);
	}
	else if ((jobs = fn_stub(array, str, b_view, litter)) == 0)
		return (0);
	return (fn_finish(jobs));
}
