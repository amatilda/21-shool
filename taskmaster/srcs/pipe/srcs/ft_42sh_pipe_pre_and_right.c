/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre_and_right.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

static size_t		fn_search_ret(register t_pipe_42sh *pipe_end,
register size_t tempos)
{
	if (tempos == 0 && pipe_end->fd_2 <= FD_MAX_SUPPORT_42SH)
		if ((ssize_t)(pipe_end->fd_2 = dup(pipe_end->fd_2)) == -1)
			return (-1);
	return (tempos);
}

static size_t		fn_search(register t_pipe_42sh *pipe,
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
			{
				if ((ssize_t)(tempos = fn_search(pipe_tmp,
				pipe, pipe->fd_2)) == -1)
					return (-1);
				tempos = 1;
			}
		}
		pipe++;
	}
	return (fn_search_ret(pipe_end, tempos));
}

static t_pipe_42sh	*fn_while(register t_pipe_42sh *pipe,
register t_pipe_42sh *pipe_tmp, register int fd)
{
	register size_t			b_flag;

	if (((b_flag = pipe_tmp->b_flag) & PIPE_CLOSE_42SH) == 0 &&
	fd == pipe_tmp->fd_1)
		if ((b_flag & PIPE_AND_42SH) != 0)
			if ((ssize_t)fn_search(pipe, pipe_tmp, pipe_tmp->fd_2) == -1)
				return (0);
	pipe_tmp++;
	return (pipe_tmp);
}

size_t				ft_42sh_pipe_pre_and_right(register t_jobs_42sh *jobs,
register t_pipe_42sh *pipe, register t_pipe_42sh *pipe_end)
{
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
				if ((pipe_tmp = fn_while(pipe, pipe_tmp, fd)) == 0)
					return (0);
		}
		count = count >> 1;
		fd++;
	}
	return (1);
}
