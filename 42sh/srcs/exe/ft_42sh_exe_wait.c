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

#include "includes/ft_42sh_exe.h"

static void		fn_status(register t_main_42sh *array,
t_jobs_42sh *jobs_cl, int stat_loc)
{
	if ((jobs_cl->b_type & AUTO_TYPE_EXE_42SH) != 0 || (jobs_cl->b_type & AUTO_TYPE_RUN_42SH) != 0)
	{
		if (WIFEXITED(stat_loc) != 0)
			stat_loc = WEXITSTATUS(stat_loc);
		else
		{
			if (WIFSIGNALED(stat_loc) != 0)
				stat_loc = 128 + WTERMSIG(stat_loc);
			else if (WIFSTOPPED(stat_loc) != 0)
				stat_loc = 128 + WSTOPSIG(stat_loc);
			else
				stat_loc = 128;
		}
	}
	array->env.exit_status->number = (unsigned char)stat_loc;
}

static size_t	fn_finish(register t_main_42sh *array,
register t_jobs_42sh *jobs, t_jobs_42sh *jobs_cl, register size_t b_test)
{
	if ((b_test & JOBS_SUSPEND_42SH) != 0)
	{
		array->b_read = 1;
		array->tty_change.c_cc[VMIN] = 0;
		array->tty_change.c_cc[VTIME] = 1;
	}
	if (ioctl(array->fd, TIOCSPGRP, &array->pr.pid_main) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	if (ioctl(array->fd, TIOCSETA, &array->tty_change) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH);
	if (array->b_quest_exit == 0 && (ft_42sh_dsp_position(array) & 0xFFFFFFFF) != 1)
		ft_write_buffer_str_zero(&array->out, MSG_PIPE_NOT_N_42SH);
	if ((b_test & JOBS_MSG_42SH) != 0)
		ft_42sh_jobs_msg(array, jobs, JOBS_MSG_PROC_42SH);
	fn_status(array, jobs_cl, jobs_cl->stat_loc);
	if ((b_test & JOBS_SUSPEND_42SH) == 0)
		ft_42sh_jobs_free_list_count(array, jobs_cl);
	return (((b_test & JOBS_STOP_42SH) != 0) ? 0 : 1);
}

static size_t	fn_test(register t_jobs_42sh *jobs, int stat_loc)
{
	register size_t					b_test;

	b_test = 0;
	while (0xFF)
	{
		if (jobs->pid_view != 0)
		{
			stat_loc = jobs->stat_loc;
			if (WIFSIGNALED(stat_loc) != 0)
			{
				if ((stat_loc = WTERMSIG(stat_loc)) == SIGINT)
					b_test = b_test | JOBS_STOP_42SH;
				else if (stat_loc != SIGPIPE)
					b_test = b_test | JOBS_MSG_42SH;
			}
			else if (WIFSTOPPED(stat_loc) != 0)
			{
				b_test = b_test | JOBS_SUSPEND_42SH | JOBS_MSG_42SH;
				jobs->pid = jobs->pid_view;
			}
		}
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
	return (b_test);
}

size_t			ft_42sh_exe_wait2(register t_main_42sh *array,
register t_jobs_42sh *jobs, t_jobs_42sh *jobs_cl)
{
	register t_jobs_42sh		*tmp;
	register pid_t				pid;
	int							stat_loc;

	tmp = jobs;
	while (0xFF)
	{
		if (tmp->pid != 0)
		{
			waitpid((pid = array->pr.even_child), &stat_loc, WCONTINUED);
			kill(pid, SIGSTOP);
			break ;
		}
		if ((tmp = tmp->next) == 0 || tmp->count == 1)
			break ;
	}
	array->pr.jobs_current = 0;
	return (fn_finish(array, jobs, jobs_cl, fn_test(jobs, 0)));
}

static void		fn_wait(register t_jobs_42sh *jobs)
{
	register size_t				count;
	register int				fd;
	register pid_t				pid;
	int							stat_loc;

	while (0xFF)
	{
		count = jobs->b_pipe_fd;
		fd = 0;
		while (count != 0)
		{
			if ((count & 0x1) != 0)
				if ((pid = jobs->pipe_pid[fd]) != 0 &&
				waitpid(pid, &stat_loc, WUNTRACED) != -1)
					if (WIFSTOPPED(stat_loc) == 0)
						jobs->pipe_pid[fd] = 0;
			count = count >> 1;
			fd++;
		}
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
}

size_t			ft_42sh_exe_wait(register t_main_42sh *array,
register t_jobs_42sh *jobs, t_jobs_42sh *jobs_cl)
{
	register t_jobs_42sh		*tmp;
	int							stat_loc;

	tmp = jobs;
	while (0xFF)
	{
		if (tmp->pid != 0 && waitpid(tmp->pid, &stat_loc, WUNTRACED) != -1)
			tmp->stat_loc = stat_loc;
		if ((tmp = tmp->next) == 0 || tmp->count == 1)
			break ;
	}
	fn_wait(jobs);
	array->pr.jobs_current = 0;
	return (fn_finish(array, jobs, jobs_cl, fn_test(jobs, 0)));
}
