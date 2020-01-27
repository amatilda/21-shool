/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_pipe.h"

static void		fn_to_file(register t_pipe_42sh *pipe,
register char *buff, register int fd_write, register int fd_read)
{
	register ssize_t		tempos;

	if ((pipe->b_flag & PIPE_CLOSE_FD_42SH) != 0 && pipe->fd_1 == fd_write)
		return ;
	while ((tempos = read(fd_read, buff, BUFFER_OUT_42SH)) > 0)
		write(fd_write, buff, tempos);
}

static void		fn_to_hrdc(register t_pipe_42sh *pipe, register int fd_write)
{
	register t_slesh_42sh			**spl;
	register t_slesh_42sh			**spl_end;
	register char					*b;
	register size_t					tempos;

	if ((pipe->b_flag & PIPE_CLOSE_FD_42SH) != 0 && pipe->fd_1 == fd_write)
		return ;
	spl = pipe->lp_heredok_spl;
	spl_end = pipe->lp_heredok_spl_end;
	b = pipe->lp_heredok_b;
	while (spl < spl_end)
	{
		if ((tempos = spl++[0]->count) != 0)
			write(fd_write, b, tempos);
		write(fd_write, "\n", 1);
		b += tempos + 2;
	}
}

static void		fn_search(register t_pipe_42sh *pipe,
register t_pipe_42sh *pipe_end, register int fd_write,
register t_pipe_search_in_42sh *in)
{
	register size_t			b_flag;
	register size_t			tempos;

	tempos = 0;
	while (pipe < pipe_end)
	{
		if (((b_flag = pipe->b_flag) & PIPE_CLOSE_42SH) == 0 &&
		pipe_end->fd_2 == pipe->fd_1)
		{
			if ((b_flag & PIPE_AND_42SH) == 0)
			{
				tempos = 1;
				if ((b_flag & (PIPE_LEFT2_42SH ^ PIPE_LEFT_42SH)) != 0)
					fn_to_hrdc(pipe, fd_write);
				else
					fn_to_file(pipe, in->b, fd_write, pipe->fd_2);
			}
			else if ((pipe->b_flag & PIPE_CLOSE_FD_42SH) != 0)
				fn_search(in->pipe, pipe, fd_write, in);
		}
		pipe++;
	}
	if (tempos == 0)
		fn_to_file(pipe, in->b, fd_write, pipe_end->fd_2);
}

static void		fn_while(register t_pipe_42sh *pipe_end,
register int fd, register int fd_write, register t_pipe_search_in_42sh *in)
{
	register t_pipe_42sh	*pipe;
	register size_t			b_flag;

	pipe = in->pipe;
	while (pipe < pipe_end)
	{
		if (((b_flag = pipe->b_flag) & PIPE_CLOSE_42SH) == 0 &&
		fd == pipe->fd_1)
		{
			if ((b_flag & PIPE_AND_42SH) == 0)
			{
				if ((b_flag & (PIPE_LEFT2_42SH ^ PIPE_LEFT_42SH)) != 0)
					fn_to_hrdc(pipe, fd_write);
				else
					fn_to_file(pipe, in->b, fd_write, pipe->fd_2);
			}
			else if ((pipe->b_flag & PIPE_CLOSE_FD_42SH) != 0)
				fn_search(in->pipe, pipe, fd_write, in);
		}
		pipe++;
	}
}

void			ft_42sh_pipe_left(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	register size_t			count;
	register int			fd;
	t_pipe_search_in_42sh	in;

	count = jobs->b_fd_left;
	fd = 0;
	in.pipe = &jobs->pipe[0];
	in.b = array->buff_out;
	in.b_fd_left = jobs->b_fd_left;
	while (count != 0)
	{
		if ((count & 0x1) != 0)
		{
			if (fork() == 0)
			{
				array->pr.b_child = 1;
				ft_42sh_pipe_close_fd_left(jobs);
				fn_while(&jobs->pipe[jobs->n], fd,
				jobs->fds[(fd << 1) + PIPE_WRITE_42SH], &in);
				ft_42sh_cm_exit(array, 0);
			}
		}
		count = count >> 1;
		fd++;
	}
}
