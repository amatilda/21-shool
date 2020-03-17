/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre_close.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

static void	fn_close(register t_pipe_42sh *pipe, register size_t b_flag)
{
	pipe->b_flag = PIPE_CLOSE_42SH;
	if ((b_flag & PIPE_AND_42SH) != 0 ||
	(b_flag & (PIPE_LEFT2_42SH ^ PIPE_LEFT_42SH)) != 0)
		return ;
	close(pipe->fd_2);
	pipe->fd_2 = 0;
}

void		ft_42sh_pipe_pre_close(register t_jobs_42sh *jobs,
register t_pipe_42sh *pipe_end)
{
	register int				fd;
	register size_t				tempos;
	register t_pipe_42sh		*pipe;
	register size_t				b_flag;

	pipe = &jobs->pipe[0];
	fd = pipe_end->fd_1;
	tempos = 1 << fd;
	if ((jobs->b_fd_left & tempos) != 0)
		jobs->b_fd_left ^= tempos;
	if ((jobs->b_fd_right & tempos) != 0)
		jobs->b_fd_right ^= tempos;
	jobs->b_flag_close |= tempos;
	while (pipe < pipe_end)
	{
		if (((b_flag = pipe->b_flag) & PIPE_CLOSE_42SH) == 0 &&
		pipe->fd_1 == fd)
			fn_close(pipe, b_flag);
		pipe++;
	}
}
