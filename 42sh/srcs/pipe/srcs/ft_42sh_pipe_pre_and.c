/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre_and.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

static size_t	fn_while_left(register t_pipe_42sh *pipe,
register t_pipe_42sh *pipe_end, register int fd_1, register int fd_2)
{
	register size_t				count;
	register size_t				b_flag;

	count = 0;
	while (pipe < pipe_end)
	{
		if (((b_flag = pipe->b_flag) & PIPE_LEFT_42SH) != 0)
		{
			if (pipe->fd_1 == fd_1 && pipe->fd_2 == fd_2)
			{
				if ((b_flag & PIPE_REPLASE_42SH) != 0)
					return (1);
				break ;
			}
			if ((b_flag & PIPE_CLOSE_42SH) == 0 && pipe->fd_1 == fd_2)
			{
				count++;
				pipe->fd_1 = fd_1;
			}
		}
		pipe++;
	}
	return (count);
}

void			ft_42sh_pipe_pre_and_left(register t_jobs_42sh *jobs,
register t_pipe_42sh *pipe_end)
{
	register size_t				count;
	register int				fd_2;

	fd_2 = pipe_end->fd_2;
	count = fn_while_left(&jobs->pipe[0], pipe_end, pipe_end->fd_1, fd_2);
	if (count != 0)
		pipe_end->b_flag = PIPE_CLOSE_42SH | PIPE_REPLASE_42SH | PIPE_LEFT_42SH;
	else
	{
		pipe_end->fd_2 = dup(fd_2);
		pipe_end->b_flag = PIPE_LEFT_42SH;
	}
}


static size_t	fn_search(register t_pipe_42sh *pipe,
register t_pipe_42sh *pipe_end, register int fd)
{
	register t_pipe_42sh	*pipe_tmp;
	register size_t			b_flag;
	register size_t			tempos;

	tempos = 0;
	pipe_tmp = pipe;
	while (pipe < pipe_end)
	{
		if (((b_flag = pipe->b_flag) & PIPE_CLOSE_42SH) == 0 &&
		fd == pipe->fd_1)
		{
			if ((b_flag & PIPE_AND_42SH) == 0)
				return (1);
			else
				tempos = fn_search(pipe_tmp, pipe, pipe->fd_2) + 1;
		}
		pipe++;
	}
	if (tempos == 0 && pipe_end->fd_2 <= PIPE_MAX_SUPPORT_FD_42SH)
		pipe_end->fd_2 = dup(pipe_end->fd_2);
	return (tempos);
}

void			ft_42sh_pipe_pre_and_right(register t_jobs_42sh *jobs,
register t_pipe_42sh *pipe, register t_pipe_42sh *pipe_end)
{
	register size_t			b_flag;
	register t_pipe_42sh	*pipe_tmp;
	register size_t			count;
	register int			fd;

	count = jobs->b_fd_right;
	fd = 0;
	while (count != 0)
	{
		if ((count & 0x1) != 0)
		{
			pipe_tmp = pipe;
			while (pipe_tmp < pipe_end)
			{
				if (((b_flag = pipe_tmp->b_flag) & PIPE_CLOSE_42SH) == 0 &&
				fd == pipe_tmp->fd_1)
					if ((b_flag & PIPE_AND_42SH) != 0)
						fn_search(pipe, pipe_tmp, pipe_tmp->fd_2);
				pipe_tmp++;
			}
		}
		count = count >> 1;
		fd++;
	}
}