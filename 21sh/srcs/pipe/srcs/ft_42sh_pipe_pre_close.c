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

void		ft_42sh_pipe_pre_close(register t_jobs_42sh *jobs,
register t_pipe_42sh *pipe_end)
{
	register int				fd;
	register size_t				tempos;
	register t_pipe_42sh		*pipe;

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
		if (pipe->fd_1 == fd)
			pipe->b_flag |= PIPE_CLOSE_FD_42SH;
		pipe++;
	}
}
