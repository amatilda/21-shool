/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_fd_close.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_close_pipe(register t_jobs_42sh *jobs)
{
	register size_t				count;
	register int				*fds;

	if ((count = jobs->b_fd_left | jobs->b_fd_right) == 0)
		return ;
	jobs->b_fd_left = 0;
	jobs->b_fd_right = 0;
	fds = (void *)&jobs->fds;
	while (count != 0)
	{
		if ((count & 0x1) != 0)
		{
			close(fds[PIPE_READ_42SH]);
			close(fds[PIPE_WRITE_42SH]);
		}
		count = count >> 1;
		fds += 2;
	}
}

void			ft_42sh_jobs_fd_close(register t_jobs_42sh *jobs,
uint_fast8_t b_pipe_close)
{
	register t_pipe_42sh		*pipe;
	register size_t				count;
	register int				fd;

	if ((count = jobs->n) == 0)
		return ;
	pipe = &jobs->pipe[0];
	while (count-- > 0)
	{
		if ((fd = pipe->fd_2) > FD_MAX_SUPPORT_42SH)
		{
			pipe->fd_2 = 0;
			close(fd);
		}
		pipe++;
	}
	if (b_pipe_close != 0)
		fn_close_pipe(jobs);
}

void			ft_42sh_jobs_fd_close_future(register t_jobs_42sh *jobs)
{
	if ((jobs = jobs->next) == 0 || jobs->count == 1)
		return ;
	while (0xFF)
	{
		ft_42sh_jobs_fd_close(jobs, 0);
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
}
