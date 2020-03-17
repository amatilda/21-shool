/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_close_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

void		ft_42sh_pipe_close_fd(register t_jobs_42sh *jobs)
{
	register int				fd;
	register size_t				count;
	register size_t				tempos;

	count = jobs->b_fd_left | jobs->b_fd_right;
	if (((tempos = jobs->b_flag_close) & (1 << STDIN_FILENO)) != 0)
		close(STDIN_FILENO);
	if ((tempos & (1 << STDOUT_FILENO)) != 0)
		close(STDOUT_FILENO);
	if ((tempos & (1 << STDERR_FILENO)) != 0)
		close(STDERR_FILENO);
	fd = PIPE_MAX_STANDART_FD_42SH + 1;
	count = count >> (PIPE_MAX_STANDART_FD_42SH + 1);
	while (count != 0)
	{
		if ((count & 0x1) == 0)
			close(fd);
		count = count >> 1;
		fd++;
	}
	if (fd <= PIPE_MAX_STANDART_FD_42SH)
		fd = PIPE_MAX_STANDART_FD_42SH + 1;
	while (fd <= PIPE_MAX_SUPPORT_FD_42SH)
		close(fd++);
}

static void	fn_close_pipe(register int *fds, register size_t count)
{
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

static void	fn_pre(register t_jobs_42sh *jobs)
{
	register size_t				fd;

	fd = 0;
	while (fd <= PIPE_MAX_SUPPORT_FD_42SH)
		close(fd++);
	ft_42sh_jobs_fd_close_future(jobs);
}

void		ft_42sh_pipe_close_fd_left(register t_jobs_42sh *jobs)
{
	register t_pipe_42sh		*pipe;
	register t_pipe_42sh		*pipe_end;
	register size_t				b_flag;
	register int				*fds;
	register size_t				fd;

	fn_pre(jobs);
	pipe = &jobs->pipe[0];
	pipe_end = &(jobs->pipe[jobs->n]);
	fds = &jobs->fds[0];
	while (pipe < pipe_end)
	{
		if (((b_flag = pipe->b_flag) & PIPE_RIGHT_42SH) != 0)
			close(pipe->fd_2);
		else if ((b_flag & PIPE_LEFT_42SH) != 0 &&
		(jobs->b_fd_left & (1 << (fd = pipe->fd_1))) != 0)
		{
			close(fds[(fd << 1) + PIPE_READ_42SH]);
			jobs->b_fd_left ^= (1 << fd);
		}
		pipe++;
	}
	fn_close_pipe(fds, jobs->b_fd_right | jobs->b_fd_left);
}

void		ft_42sh_pipe_close_fd_right(register t_jobs_42sh *jobs)
{
	register t_pipe_42sh		*pipe;
	register t_pipe_42sh		*pipe_end;
	register int				*fds;
	register size_t				b_flag;

	fn_pre(jobs);
	pipe = &jobs->pipe[0];
	pipe_end = &(jobs->pipe[jobs->n]);
	while (pipe < pipe_end)
	{
		if (((b_flag = pipe->b_flag) & PIPE_LEFT_42SH) != 0 &&
		(b_flag & (PIPE_LEFT2_42SH ^ PIPE_LEFT_42SH)) == 0)
			close(pipe->fd_2);
		pipe++;
	}
	fn_close_pipe((fds = &jobs->fds[0]), jobs->b_fd_left);
	b_flag = jobs->b_fd_right;
	while (b_flag != 0)
	{
		if ((b_flag & 0x1) != 0)
			close(fds[PIPE_WRITE_42SH]);
		b_flag = b_flag >> 1;
		fds += 2;
	}
}
