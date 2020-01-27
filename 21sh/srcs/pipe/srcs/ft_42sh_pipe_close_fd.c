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

static void	fn_close(register int fd, register int *fds)
{
	close(fd);
	close(fds[PIPE_READ_42SH]);
	close(fds[PIPE_WRITE_42SH]);
}

void		ft_42sh_pipe_close_fd_left(register t_jobs_42sh *jobs)
{
	register t_pipe_42sh		*pipe;
	register t_pipe_42sh		*pipe_end;
	register int				*fds;
	register size_t				b_flag;
	register size_t				fd;

	fd = 0;
	while (fd <= PIPE_MAX_SUPPORT_FD_42SH)
		close(fd++);
	ft_42sh_jobs_fd_close_future(jobs);
	pipe = &jobs->pipe[0];
	pipe_end = &(jobs->pipe[jobs->n]);
	fds = &jobs->fds[0];
	while (pipe < pipe_end)
	{
		if (((b_flag = pipe->b_flag) & PIPE_CLOSE_42SH) == 0)
		{
			fd = (pipe->fd_1 << 1);
			if ((b_flag & PIPE_RIGHT_42SH) != 0)
				fn_close(pipe->fd_2, &fds[fd]);
			else if ((b_flag & PIPE_LEFT_42SH) != 0)
				close(fds[fd + PIPE_READ_42SH]);
		}
		pipe++;
	}
}

void		ft_42sh_pipe_close_fd_right(register t_jobs_42sh *jobs)
{
	register t_pipe_42sh		*pipe;
	register t_pipe_42sh		*pipe_end;
	register int				*fds;
	register size_t				b_flag;
	register size_t				fd;

	fd = 0;
	while (fd <= PIPE_MAX_SUPPORT_FD_42SH)
		close(fd++);
	ft_42sh_jobs_fd_close_future(jobs);
	pipe = &jobs->pipe[0];
	pipe_end = &(jobs->pipe[jobs->n]);
	fds = &jobs->fds[0];
	while (pipe < pipe_end)
	{
		if (((b_flag = pipe->b_flag) & PIPE_CLOSE_42SH) == 0)
		{
			fd = (pipe->fd_1 << 1);
			if ((b_flag & PIPE_LEFT_42SH) != 0)
				fn_close(pipe->fd_2, &fds[fd]);
			else if ((b_flag & PIPE_RIGHT_42SH) != 0)
				close(fds[fd + PIPE_WRITE_42SH]);
		}
		pipe++;
	}
}
