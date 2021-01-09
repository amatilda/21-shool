/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_signal_child_pipe.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_signal.h"

size_t			ft_42sh_signal_child_test_pipe(register t_jobs_42sh *jobs,
register pid_t pid, int stat_loc)
{
	register size_t				count;
	register int				fd;

	count = jobs->b_pipe_fd;
	fd = 0;
	while (count != 0)
	{
		if ((count & 0x1) != 0 && pid == jobs->pipe_pid[fd])
		{
			if (WIFSTOPPED(stat_loc) == 0)
			{
				jobs->pipe_pid[fd] = 0;
				jobs->b_pipe_fd = jobs->b_pipe_fd ^ (1 << fd);
			}
			return (0);
		}
		count = count >> 1;
		fd++;
	}
	return (1);
}
