/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe_grup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exe.h"

void			ft_42sh_exe_grup(register t_main_42sh *array,
register t_jobs_42sh *jobs, pid_t pid, int *fds)
{
	jobs->pid = pid;
	jobs->pid_view = pid;
	if (array->pr.pid_grup == 0)
	{
		array->pr.pid_grup = pid;
		setpgid(pid, pid);
		if ((jobs->b_type & AUTO_TYPE_RUN_42SH) == 0)
			ft_42sh_stub_ioctl(array, TIOCSPGRP, &array->pr.pid_grup);
	}
	else
		setpgid(pid, array->pr.pid_grup);
	if ((jobs->b_type & AUTO_TYPE_RUN_42SH) != 0)
		array->pr.count_runing++;
	if (write(fds[PIPE_WRITE_42SH], &pid, sizeof(pid_t)) == -1)
		ft_42sh_exit(E_PIPE_CODE_42SH, __FILE__, __func__, __LINE__);
	close(fds[PIPE_READ_42SH]);
	close(fds[PIPE_WRITE_42SH]);
}
