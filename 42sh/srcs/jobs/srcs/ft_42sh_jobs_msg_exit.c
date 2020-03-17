/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_msg_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_jobs.h"

static void			fn_code(register t_write_buff *out,
register t_jobs_42sh *jobs, register unsigned char number)
{
	char						buff[4];
	register size_t				tempos;

	if ((jobs->b_type & AUTO_TYPE_RUN_42SH) != 0)
	{
		ft_write_buffer_str_zero(out, MSG_JOBS_RUN_42SH);
		return ;
	}
	if (number == 0)
	{
		ft_write_buffer_str_zero(out, MSG_JOBS_DONE_42SH);
		return ;
	}
	ft_write_buffer_str_zero(out, MSG_JOBS_EXIT_42SH);
	tempos = ft_itoa(buff, number, 10, ITOA_LOWER);
	ft_write_buffer_char(out, ' ', 3 - tempos);
	ft_write_buffer_str(out, buff, tempos);
	ft_write_buffer_str_zero(out, MSG_JOBS_EXIT_ADD_42SH);
}

t_jobs_42sh			*ft_42sh_jobs_msg_exit(register t_write_buff *out,
register t_jobs_42sh *jobs, register size_t b_test)
{
	register size_t				tempos;

	tempos = (jobs->pid_view == 0 || (jobs->b_type & AUTO_TYPE_RUN_42SH) != 0)
	? jobs->stat_loc : (unsigned char)WEXITSTATUS(jobs->stat_loc);
	fn_code(out, jobs, tempos);
	while (0xFF)
	{
		ft_write_buffer_str_zero(out, (void *)jobs->cmd);
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			return (0);
		if ((b_test & JOBS_MSG_ID_PID_42SH) != 0)
			break ;
		if (jobs->pid_view == 0 || WIFEXITED(jobs->stat_loc) == 0 || tempos !=
		(jobs->pid_view == 0 || (jobs->b_type & AUTO_TYPE_RUN_42SH) != 0)
		? jobs->stat_loc : (unsigned char)WEXITSTATUS(jobs->stat_loc))
			break ;
	}
	return (jobs);
}
