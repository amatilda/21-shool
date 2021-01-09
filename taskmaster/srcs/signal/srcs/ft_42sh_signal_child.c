/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_signal_child.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_signal.h"

static void		fn_while(register t_main_42sh *array,
register pid_t pid, int stat_loc)
{
	register t_jobs_42sh		*jobs;
	register size_t				b_test;

	jobs = array->pr.jb.first;
	b_test = 0;
	while (jobs != 0)
	{
		if (jobs->pid == pid)
		{
			if ((jobs->b_type & AUTO_TYPE_RUN_42SH) != 0)
			{
				array->pr.count_runing--;
				b_test = AUTO_TYPE_RUN_42SH;
				jobs->b_type = jobs->b_type ^ AUTO_TYPE_RUN_42SH;
			}
			if (WIFSTOPPED(stat_loc) == 0)
				jobs->pid = 0;
			jobs->stat_loc = stat_loc;
			ft_42sh_signal_child_msg(array, jobs, b_test);
			return ;
		}
		if (ft_42sh_signal_child_test_pipe(jobs, pid, stat_loc) == 0)
			return ;
		jobs = jobs->next;
	}
}

static size_t	fn_test_status(register t_jobs_42sh *jobs, register pid_t pid,
int stat_loc)
{
	if (jobs == 0)
		return (1);
	while (0xFF)
	{
		if (jobs->pid == pid)
		{
			if (WIFSTOPPED(stat_loc) == 0)
				jobs->pid = 0;
			jobs->stat_loc = stat_loc;
			return (0);
		}
		if (ft_42sh_signal_child_test_pipe(jobs, pid, stat_loc) == 0)
			return (0);
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
	return (1);
}

static void		fn_test_event(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	while (0xFF)
	{
		if (jobs->pid != 0 && WIFSTOPPED(jobs->stat_loc) == 0)
			return ;
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
	if (write(array->pr.even_fds[PIPE_WRITE_42SH], "0", 1) == -1)
		ft_42sh_exit(E_PIPE_CODE_42SH, __FILE__, __func__, __LINE__);
}

void			ft_42sh_signal_child(int signo)
{
	register t_jobs_42sh		*tmp;
	register t_main_42sh		*array;
	register pid_t				pid;
	int							stat_loc;

	array = g_lp_array;
	while ((pid = waitpid(-1, &stat_loc, WNOHANG | WUNTRACED)) > 0)
	{
		if (array->pr.pid_not_fork == pid)
		{
			if (write(array->pr.even_fds[PIPE_WRITE_42SH], "0", 1) == -1)
				ft_42sh_exit(E_PIPE_CODE_42SH, __FILE__, __func__, __LINE__);
			continue ;
		}
		if (fn_test_status((tmp = array->pr.jobs_current), pid, stat_loc) == 0)
		{
			fn_test_event(array, tmp);
			continue ;
		}
		fn_while(array, pid, stat_loc);
	}
	(void)signo;
}
