/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre_finish.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

static size_t	fn_left(register t_main_42sh *array,
register t_jobs_42sh *jobs, register t_pipe_42sh *pipe, register size_t b_flag)
{
	register size_t				tempos;

	if ((jobs->b_fd_right & (tempos = 1 << pipe->fd_1)) != 0)
	{
		pipe->fd_1 += 0x30;
		ft_42sh_jobs_set_err_n(array, MSG_PIPE_EQV_42SH, &pipe->fd_1, 1);
		return (0);
	}
	jobs->b_fd_left |= tempos;
	if ((b_flag & PIPE_AND_42SH) != 0)
		ft_42sh_pipe_pre_and_left(jobs, pipe);
	return (1);
}

static size_t	fn_ringht(register t_main_42sh *array,
register t_jobs_42sh *jobs, register t_pipe_42sh *pipe, register size_t b_flag)
{
	if ((jobs->b_fd_left & (b_flag = 1 << pipe->fd_1)) != 0)
	{
		pipe->fd_1 += 0x30;
		ft_42sh_jobs_set_err_n(array, MSG_PIPE_EQV_42SH, &pipe->fd_1, 1);
		return (0);
	}
	jobs->b_fd_right |= b_flag;
	if ((jobs->b_flag_close & b_flag) != 0)
		jobs->b_flag_close ^= b_flag;
	return (1);
}

size_t			ft_42sh_pipe_pre_finish(register t_main_42sh *array,
register t_jobs_42sh *jobs, register t_pipe_42sh *pipe, register size_t b_flag)
{
	if ((b_flag & PIPE_CLOSE_42SH) != 0)
		ft_42sh_pipe_pre_close(jobs, pipe);
	else if ((b_flag & PIPE_LEFT_42SH) != 0)
		return (fn_left(array, jobs, pipe, b_flag));
	else if ((b_flag & PIPE_RIGHT_42SH) != 0)
		return (fn_ringht(array, jobs, pipe, b_flag));
	return (1);
	(void)array;
}
