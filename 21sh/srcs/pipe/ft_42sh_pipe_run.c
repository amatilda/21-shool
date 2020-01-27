/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_run.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_pipe.h"

static void			fn_close(register t_jobs_42sh *jobs)
{
	register t_pipe_42sh		*pipe;
	register size_t				count;
	register int				fd;

	if ((count = jobs->n) == 0)
		return ;
	pipe = &jobs->pipe[0];
	while (count-- > 0)
	{
		if ((fd = pipe->fd_2) > PIPE_MAX_SUPPORT_FD_42SH)
		{
			pipe->fd_2 = 0;
			close(fd);
		}
		pipe++;
	}
}

static void			fn_full(register t_jobs_42sh *jobs)
{
	if ((jobs = jobs->next) == 0 || jobs->count == 1)
		return ;
	while (0xFF)
	{
		fn_close(jobs);
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
}

static void			fn_dup(register t_pipe_42sh *pipe,
register t_pipe_42sh *pipe_end, register int *fds, register size_t b_fd)
{
	register int				fd_1;
	register size_t				b_flag;

	while (pipe < pipe_end)
	{
		if (((b_flag = pipe->b_flag) & PIPE_CLOSE_42SH) == 0)
		{
			fd_1 = pipe->fd_1;
			if ((b_fd & (1 << fd_1)) != 0)
			{
				b_fd ^= 1 << fd_1;
				if ((b_flag & PIPE_RIGHT_42SH) != 0)
					dup2(fds[(b_flag = fd_1 << 1) + PIPE_WRITE_42SH], fd_1);
				else if ((b_flag & PIPE_LEFT_42SH) != 0)
					dup2(fds[(b_flag = fd_1 << 1) + PIPE_READ_42SH], fd_1);
			}
		}
		pipe++;
	}
}

void				ft_42sh_pipe_run(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	register size_t				b_fd;

	if (jobs->n == 0)
		return ;
	ft_42sh_pipe_close_fd(jobs);
	if ((b_fd = (jobs->b_fd_left | jobs->b_fd_right)) == 0)
		return ;
	fn_dup(&jobs->pipe[0], &jobs->pipe[jobs->n], &jobs->fds[0], b_fd);
	ft_42sh_jobs_fd_close(jobs, 1);
	ft_42sh_jobs_fd_close_future(jobs);
	return ;
	fn_full(jobs);
	(void)array;
}
