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

void			ft_42sh_exe_grup_child(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	if (array->pr.pid_grup == 0)
	{
		if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
		{
			if ((jobs->b_type & AUTO_TYPE_RUN_42SH) != 0)
				setpgid(0, 0);
			return ;
		}
		setpgid(0, 0);
		if ((jobs->b_type & AUTO_TYPE_RUN_42SH) == 0)
			ioctl(array->fd, TIOCSPGRP, &array->pr.pid_grup);
	}
	else
		setpgid(0, array->pr.pid_grup);
}

void			ft_42sh_exe_grup(register t_main_42sh *array,
register t_jobs_42sh *jobs, register pid_t pid)
{
	jobs->pid = pid;
	jobs->pid_view = pid;
	if (array->pr.pid_grup == 0)
	{
		if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
		{
			pid = array->pr.pid_main;
			if ((jobs->b_type & AUTO_TYPE_RUN_42SH) != 0)
				setpgid(pid, pid);
			array->pr.pid_grup = pid;
			return ;
		}
		array->pr.pid_grup = pid;
		jobs->pid_grp = pid;
		setpgid(pid, pid);
		if ((jobs->b_type & AUTO_TYPE_RUN_42SH) == 0)
			ioctl(array->fd, TIOCSPGRP, &array->pr.pid_grup);
	}
	else
		setpgid(pid, array->pr.pid_grup);
	if ((jobs->b_type & AUTO_TYPE_RUN_42SH) != 0)
		array->pr.count_runing++;
}
