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

static size_t	fn_search(register t_pipe_42sh *pipe,
register t_pipe_42sh *pipe_end, register int fd,
register t_pipe_search_in_42sh *in)
{
	register size_t			b_flag;
	register size_t			tempos;

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
				tempos = fn_search(in->pipe, pipe, pipe->fd_2, in) + 1;
		}
		pipe++;
	}
	if (tempos == 0)
		write(pipe_end->fd_2, in->b, in->count);
	return (tempos);
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
					write(pipe->fd_2, in->b, in->count);
				else
					fn_search(in->pipe, pipe, pipe->fd_2, in);
			}
			pipe++;
		}
	}
}

static size_t	fn_fork(register t_main_42sh *array,
register t_jobs_42sh *jobs, register int fd, t_pipe_search_in_42sh *in)
{
	register pid_t			pid;

	if (ft_42sh_pipe_find_count(&jobs->pipe[0], &jobs->pipe[jobs->n], fd) == 1)
		return (1);
	if ((pid = fork()) == 0)
	{
		ft_42sh_signal_default(array, jobs);
		setpgid(0, array->pr.pid_fork);
		ft_42sh_pipe_close_fd_right(array, jobs);
		ft_42sh_jobs_fd_close_future(jobs);
		fn_while(&jobs->pipe[jobs->n], fd,
		jobs->fds[(fd << 1) + PIPE_READ_42SH], in);
		ft_42sh_cm_exit_fun(array, E_CODE_42SH);
	}
	else if (pid < 0)
		return (0);
	setpgid(pid, array->pr.pid_fork);
	jobs->pipe_pid[fd] = pid;
	return (1);
}

size_t			ft_42sh_pipe_right(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	register size_t			count;
	register int			fd;
	t_pipe_search_in_42sh	in;

	count = jobs->b_fd_right;
	fd = 0;
	jobs->b_pipe_fd |= count;
	in.array = array;
	in.pipe = &jobs->pipe[0];
	in.b = array->buff_out;
	in.b_fd_right = jobs->b_fd_right;
	while (count != 0)
	{
		if ((count & 0x1) != 0)
			if (fn_fork(array, jobs, fd, &in) == 0)
				return (0);
		count = count >> 1;
		fd++;
	}
	return (1);
}
