/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_msg_signal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_jobs.h"

static size_t		fn_signal(int stat_loc)
{
	if (WIFSIGNALED(stat_loc) != 0)
		return (WTERMSIG(stat_loc));
	else if (WIFSTOPPED(stat_loc) != 0)
		return (WSTOPSIG(stat_loc));
	return (0);
}

t_jobs_42sh			*ft_42sh_jobs_msg_signal(register t_main_42sh *array,
register t_write_buff *out, register t_jobs_42sh *jobs, register size_t b_test)
{
	int							stat_loc;
	register size_t				tempos;

	stat_loc = jobs->stat_loc;
	if ((tempos = fn_signal(stat_loc)) > SIGUSR2)
		tempos = 0;
	if ((b_test & JOBS_MSG_CONTINUED_42SH) != 0)
		ft_write_buffer_str_zero(out, MSG_JOBS_CONTINUED_42SH);
	else
		ft_write_buffer_str_zero(out, array->pr.lp_msg_sgnl[tempos]);
	while (0xFF)
	{
		ft_write_buffer_str_zero(out, (void *)jobs->cmd);
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			return (0);
		if ((b_test & JOBS_MSG_ID_PID_42SH) != 0)
			break ;
		if (jobs->pid_view == 0 || (jobs->b_type & AUTO_TYPE_RUN_42SH) != 0 ||
		tempos != fn_signal(jobs->stat_loc))
			break ;
	}
	return (jobs);
}
