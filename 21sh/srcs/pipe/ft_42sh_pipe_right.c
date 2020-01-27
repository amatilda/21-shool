/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_right.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_pipe.h"

static void		fn_to_file(register t_pipe_42sh *pipe,
register int fd_read, register t_pipe_search_in_42sh *in)
{
	if ((pipe->b_flag & PIPE_CLOSE_FD_42SH) != 0 && pipe->fd_1 == fd_read)
		return ;
	write(pipe->fd_2, in->b, in->count);
}

static void		fn_search(register t_pipe_42sh *pipe,
register t_pipe_42sh *pipe_end, register int fd,
register t_pipe_search_in_42sh *in)
{
	register size_t			b_flag;
	register size_t			tempos;

	if ((pipe_end->b_flag & PIPE_CLOSE_FD_42SH) != 0)
		return ;
	tempos = 0;
	while (pipe < pipe_end)
	{
		if (((b_flag = pipe->b_flag) & PIPE_CLOSE_42SH) == 0 &&
		fd == pipe->fd_1)
		{
			if ((b_flag & PIPE_AND_42SH) == 0)
			{
				tempos = 1;
				write(pipe->fd_2, in->b, in->count);
			}
			else
				fn_search(in->pipe, pipe, pipe->fd_2, in);
		}
		pipe++;
	}
	if (tempos == 0)
		write(fd, in->b, in->count);
}

static void		fn_while(register t_pipe_42sh *pipe_end,
register int fd, register int fd_read, register t_pipe_search_in_42sh *in)
{
	register t_pipe_42sh	*pipe;
	register size_t			b_flag;

	while ((in->count = read(fd_read, in->b, BUFFER_OUT_42SH)) > 0)
	{
		pipe = in->pipe;
		while (pipe < pipe_end)
		{
			if (((b_flag = pipe->b_flag) & PIPE_CLOSE_42SH) == 0 &&
			fd == pipe->fd_1)
			{
				if ((b_flag & PIPE_AND_42SH) == 0)
					fn_to_file(pipe, fd_read, in);
				else
					fn_search(in->pipe, pipe, pipe->fd_2, in);
			}
			pipe++;
		}
	}
}

void			ft_42sh_pipe_right(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	register size_t			count;
	register int			fd;
	t_pipe_search_in_42sh	in;

	count = jobs->b_fd_right;
	fd = 0;
	in.pipe = &jobs->pipe[0];
	in.b = array->buff_out;
	in.b_fd_right = jobs->b_fd_right;
	while (count != 0)
	{
		if ((count & 0x1) != 0)
		{
			if (fork() == 0)
			{
				array->pr.b_child = 1;
				ft_42sh_pipe_close_fd_right(jobs);
				fn_while(&jobs->pipe[jobs->n], fd,
				jobs->fds[(fd << 1) + PIPE_READ_42SH], &in);
				ft_42sh_cm_exit(array, 0);
			}
		}
		count = count >> 1;
		fd++;
	}
}
