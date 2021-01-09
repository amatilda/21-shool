/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_find.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_pipe.h"

size_t				ft_42sh_pipe_find_count(register t_pipe_42sh *pipe_b,
register t_pipe_42sh *pipe_e, register int fd)
{
	register size_t			count;

	count = 0;
	while (pipe_b < pipe_e)
	{
		if ((pipe_b->b_flag & PIPE_CLOSE_42SH) == 0 && pipe_b->fd_1 == fd)
		{
			if ((pipe_b->b_flag & (PIPE_LEFT2_42SH ^ PIPE_LEFT_42SH)) != 0)
				count++;
			count++;
		}
		pipe_b++;
	}
	return (count);
}

static int			fn_set(register t_pipe_42sh *pipe_b,
register t_pipe_42sh *pipe_e, register int fd)
{
	register t_pipe_42sh *pipe_tmp;

	pipe_tmp = pipe_b;
	while (pipe_b < pipe_e)
	{
		if ((pipe_b->b_flag & PIPE_CLOSE_42SH) == 0 && pipe_b->fd_1 == fd)
			break ;
		pipe_b++;
	}
	if (pipe_b->fd_2 < FD_TERMINAL_42SH)
		return (fn_set(pipe_tmp, pipe_b, pipe_b->fd_2));
	return (pipe_b->fd_2);
}

void				ft_42sh_pipe_find(register t_main_42sh *array,
register t_jobs_42sh *jobs, register int *fds, register int fd)
{
	register t_pipe_42sh	*pipe_b;
	register t_pipe_42sh	*pipe_e;

	pipe_b = &jobs->pipe[0];
	pipe_e = &jobs->pipe[jobs->n];
	if (ft_42sh_pipe_find_count(pipe_b, pipe_e, fd) != 1)
	{
		if (pipe(fds) != 0)
			ft_42sh_exit(E_PIPE_CODE_42SH, __FILE__, __func__, __LINE__);
		return ;
	}
	fd = fn_set(pipe_b, pipe_e, fd);
	if ((fds[PIPE_READ_42SH] = dup(fd)) == -1)
		ft_42sh_exit(E_DUP_CODE_42SH, __FILE__, __func__, __LINE__);
	if ((fds[PIPE_WRITE_42SH] = dup(fd)) == -1)
		ft_42sh_exit(E_DUP_CODE_42SH, __FILE__, __func__, __LINE__);
	(void)array;
}
