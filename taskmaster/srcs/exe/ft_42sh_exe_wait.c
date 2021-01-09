/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe_wait.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_exe.h"

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

static size_t	ft_42sh_exe_wait_add(register t_main_42sh *array,
register t_jobs_42sh *jobs, t_jobs_42sh *jobs_cl)
{
	char						buff[1];
	register t_jobs_42sh		*tmp;

	tmp = jobs;
	while (0xFF)
	{
		if (tmp->pid_view != 0 || array->pr.pid_not_fork != 0)
		{
			if (read(array->pr.even_fds[PIPE_READ_42SH], buff, 1) == -1)
				ft_42sh_exit(E_PIPE_CODE_42SH, __FILE__, __func__, __LINE__);
			array->pr.pid_not_fork = 0;
			break ;
		}
		if ((tmp = tmp->next) == 0 || tmp->count == 1)
			break ;
	}
	array->pr.jobs_current = 0;
	return (ft_42sh_exe_wait_finish(array, jobs, jobs_cl, fn_test(jobs, 0)));
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
			if ((count & 0x1) != 0 && (pid = jobs->pipe_pid[fd]) != 0)
			{
				waitpid(pid, &stat_loc, WUNTRACED);
				if (WIFSTOPPED(stat_loc) == 0)
					jobs->pipe_pid[fd] = 0;
			}
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
	register pid_t				pid;
	register t_jobs_42sh		*tmp;

	if ((array->b_mode & MODE_SIGCHILD_42SH) != 0)
		return (ft_42sh_exe_wait_add(array, jobs, jobs_cl));
	tmp = jobs;
	while (0xFF)
	{
		if ((pid = tmp->pid) != 0)
			waitpid((pid = tmp->pid), &tmp->stat_loc, WUNTRACED);
		if ((tmp = tmp->next) == 0 || tmp->count == 1)
			break ;
	}
	if ((pid = array->pr.pid_not_fork) != 0)
	{
		waitpid(pid, &jobs_cl->stat_loc, WUNTRACED);
		array->pr.pid_not_fork = 0;
	}
	else
		fn_wait(jobs);
	array->pr.jobs_current = 0;
	return (ft_42sh_exe_wait_finish(array, jobs, jobs_cl, fn_test(jobs, 0)));
}
