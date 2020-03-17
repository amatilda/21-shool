/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe_finish.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exe.h"

static size_t	fn_finish(register t_main_42sh *array,
register t_jobs_42sh *jobs, t_jobs_42sh *jobs_cl)
{
	if (ioctl(array->fd, TIOCSPGRP, &array->pr.pid_main) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	if (ioctl(array->fd, TIOCSETA, &array->tty_change) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	if (array->b_quest_exit == 0 && (ft_42sh_dsp_position(array) & 0xFFFFFFFF) != 1)
		ft_write_buffer_str_zero(&array->out, MSG_PIPE_NOT_N_42SH);
	ft_42sh_jobs_free_list_count(array, jobs_cl);
	return (1);
	(void)jobs;
}

size_t			ft_42sh_exe_wait_script(register t_main_42sh *array,
register t_jobs_42sh *jobs, t_jobs_42sh *jobs_cl, register size_t b_test)
{
	int							stat_loc;

	if ((b_test & AUTO_TYPE_RUN_42SH) != 0)
	{
		if (ioctl(array->fd, TIOCSPGRP, &array->pr.pid_main) == -1)
			ft_42sh_exit(E_IOTL_CODE_42SH);
		if (ioctl(array->fd, TIOCSETA, &array->tty_change) == -1)
			ft_42sh_exit(E_IOTL_CODE_42SH);
		ft_42sh_jobs_free_list_count(array, jobs_cl);
		return (1);
	}
	while (waitpid(0, &stat_loc, WUNTRACED) != -1)
		;
	return (fn_finish(array, jobs, jobs_cl));
}
