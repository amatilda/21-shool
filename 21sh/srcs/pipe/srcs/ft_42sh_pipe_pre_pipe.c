/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_pre_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pipe.h"

static t_pipe_42sh	*fn_first(register t_jobs_42sh *jobs,
register t_pipe_42sh *pipes)
{
	int						fds[2];

	if (pipe(fds) != 0)
		ft_42sh_exit(E_PIPE_CODE_42SH);
	pipes->b_flag = PIPE_RIGHT_42SH;
	pipes->fd_1 = STDOUT_FILENO;
	pipes->fd_2 = fds[PIPE_WRITE_42SH];
	jobs->fd_pipe = fds[PIPE_READ_42SH];
	jobs->b_fd_right = (1 << STDOUT_FILENO);
	pipes++;
	return (pipes);
}

static t_pipe_42sh	*fn_central(register t_jobs_42sh *jobs,
register t_jobs_42sh *last, register t_pipe_42sh *pipes)
{
	int						fds[2];

	if (pipe(fds) != 0)
		ft_42sh_exit(E_PIPE_CODE_42SH);
	pipes->b_flag = PIPE_LEFT_42SH;
	pipes->fd_1 = STDIN_FILENO;
	pipes->fd_2 = last->fd_pipe;
	last->fd_pipe = PIPE_42SH;
	pipes++;
	jobs->b_fd_left = (1 << STDIN_FILENO);
	pipes->b_flag = PIPE_RIGHT_42SH;
	pipes->fd_1 = STDOUT_FILENO;
	pipes->fd_2 = fds[PIPE_WRITE_42SH];
	jobs->fd_pipe = fds[PIPE_READ_42SH];
	jobs->b_fd_right = (1 << STDOUT_FILENO);
	pipes++;
	return (pipes);
}

t_pipe_42sh			*ft_42sh_pipe_pre_pipe(register t_jobs_42sh *jobs,
register t_pipe_42sh *pipes)
{
	register int				fd_pipe;
	register t_jobs_42sh		*last;

	last = jobs->prev;
	if ((fd_pipe = jobs->fd_pipe) == 0)
		return (pipes);
	else if (fd_pipe == PIPE_FIRST_42SH)
		return (fn_first(jobs, pipes));
	else if (fd_pipe == PIPE_CENTRAL_42SH)
		return (fn_central(jobs, last, pipes));
	pipes->b_flag = PIPE_LEFT_42SH;
	pipes->fd_1 = STDIN_FILENO;
	pipes->fd_2 = last->fd_pipe;
	last->fd_pipe = PIPE_42SH;
	jobs->b_fd_left = (1 << STDIN_FILENO);
	pipes++;
	return (pipes);
}
