/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_jobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_cm.h"

static	void	fn_only(register t_main_42sh *array,
register size_t b_view)
{
	register t_jobs_42sh		*jobs;
	register size_t				b_test;

	if ((jobs = array->pr.jb_id.first) == 0)
		return ;
	if (ft_42sh_pipe_test_fd_dsp(array, STDOUT_FILENO, MSG_JOBS_42SH) == 0)
		return ;
	while (jobs != 0)
	{
		if (jobs == array->pr.jobs_current)
		{
			jobs = jobs->next_id;
			continue ;
		}
		b_test = b_view;
		if (jobs == array->pr.jobs_plus)
			b_test = b_test | JOBS_MSG_PLUS_42SH;
		else if (jobs == array->pr.jobs_minus)
			b_test = b_test | JOBS_MSG_MINUS_42SH;
		ft_42sh_jobs_msg(array, jobs, b_test);
		jobs = jobs->next_id;
	}
}

static void		fn_finish(register t_main_42sh *array, register char **lp_arg,
register unsigned char *str, register size_t b_view)
{
	if (b_view == 0)
		b_view = JOBS_MSG_ID_42SH | JOBS_MSG_JOBS_42SH;
	else
	{
		if (b_view == 'p')
		{
			b_view = JOBS_MSG_ID_PID_GRUP_42SH | JOBS_MSG_ID_PID_42SH |
			JOBS_MSG_ID_42SH | JOBS_MSG_JOBS_42SH;
		}
		else
		{
			b_view = JOBS_MSG_ID_PID_ALL_42SH | JOBS_MSG_ID_42SH |
			JOBS_MSG_ID_PID_42SH | JOBS_MSG_JOBS_42SH;
		}
	}
	ft_42sh_jobs_set_current(array);
	if (str == 0)
		return (fn_only(array, b_view));
	while ((str = (void *)lp_arg++[0]) != 0)
	{
		if (ft_42sh_cm_jobs_find(array, str, b_view) == 0)
			return ;
	}
}

void			ft_42sh_cm_jobs(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char			*str;
	register unsigned char			litter;
	register size_t					b_view;

	b_view = 0;
	while ((str = (void *)lp_arg[0]) != 0 && str++[0] == '-')
	{
		lp_arg++;
		if ((litter = str[0]) == 0 || (litter == '-' && str[1] == 0))
			break ;
		while ((litter = str++[0]) != 0 && (litter == 'p' || litter == 'l'))
			b_view = litter;
		if (litter != 0)
			return (ft_42sh_dsp_err_msg_add_n(array,
			WAR_PR_42SH""MSG_BAD_OPTION_TXT_42SH""PRTF_RESET"-",
			(void *)str - 1, ft_strlen_utf8_litter(str - 1)));
	}
	fn_finish(array, lp_arg, str, b_view);
}
