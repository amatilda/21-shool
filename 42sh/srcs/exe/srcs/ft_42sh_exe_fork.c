/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exe.h"

void			ft_42sh_exe_fork(register t_main_42sh *array,
register t_jobs_42sh *jobs, int *fds)
{
	register pid_t				pid;

	array->b_location |= LOCATION_FORK_42SH;
	if (read(fds[PIPE_READ_42SH], &array->pr.pid_fork, sizeof(pid_t)) == -1)
		ft_42sh_exit(E_PIPE_CODE_42SH, __FILE__, __func__, __LINE__);
	ft_42sh_signal_default(array, jobs);
	close(fds[PIPE_READ_42SH]);
	close(fds[PIPE_WRITE_42SH]);
	if (ft_42sh_pipe_left(array, jobs) == 0 ||
	ft_42sh_pipe_right(array, jobs) == 0)
	{
		ft_42sh_dsp_err_msg(array, WAR_PR_42SH""MSG_FOOR_TXT_42SH""PRTF_RESET);
		exit(STATUS_FALTURE_42SH);
	}
	if ((array->b_mode & MODE_SIGCHILD_42SH) != 0)
	{
		close(array->pr.even_fds[PIPE_READ_42SH]);
		close(array->pr.even_fds[PIPE_WRITE_42SH]);
	}
	pid = array->pr.pid_grup;
	setpgid(0, pid);
	if (pid == 0)
		if ((jobs->b_type & AUTO_TYPE_RUN_42SH) == 0)
			ft_42sh_stub_ioctl(array, TIOCSPGRP, &array->pr.pid_fork);
}
