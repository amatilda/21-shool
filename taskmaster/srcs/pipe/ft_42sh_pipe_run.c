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

static void			fn_default(void)
{
	register int				fd;

	fd = FD_MAX_SUPPORT_42SH;
	while (fd > FD_MAX_STANDART_42SH)
		close(fd--);
}

static void			fn_dup(register int *fds, register size_t count,
register size_t offset)
{
	register int		fd;

	fd = 0;
	while (count != 0)
	{
		if ((count & 0x1) != 0)
			dup2(fds[(fd << 1) + offset], fd);
		count = count >> 1;
		fd++;
	}
}

void				ft_42sh_pipe_run(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	register int				*fds;

	if (jobs->n == 0)
		return (fn_default());
	ft_42sh_pipe_close_fd(jobs);
	if ((jobs->b_fd_left | jobs->b_fd_right) == 0)
		return ;
	fds = &jobs->fds[0];
	fn_dup(fds, jobs->b_fd_left, PIPE_READ_42SH);
	fn_dup(fds, jobs->b_fd_right, PIPE_WRITE_42SH);
	ft_42sh_jobs_fd_close(jobs, 1);
	ft_42sh_jobs_fd_close_future(jobs);
	(void)array;
}
