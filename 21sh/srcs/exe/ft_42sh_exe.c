/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static size_t	fn_finish(register t_main_42sh *array,
register t_jobs_42sh *jobs, register size_t count)
{
	int							stat_loc;

	array->pr.b_main_suspend = 1;
	while (--count > 0)
		jobs = jobs->prev;
	while (jobs != 0)
	{
		if (jobs->pid != 0)
		{
			waitpid(jobs->pid, &stat_loc, 0);
			if (WIFSIGNALED(stat_loc) && WTERMSIG(stat_loc) == SIGINT)
			{
				tcsetattr(STDOUT_FILENO, TCSANOW, &array->tty_change);
				return (0);
			}
		}
		jobs = jobs->next;
	}
	array->pr.b_main_suspend = 0;
	tcsetattr(STDOUT_FILENO, TCSANOW, &array->tty_change);
	if ((ft_42sh_dsp_position() & 0xFFFFFFFF) != 1)
		ft_write_buffer_str_zero(&array->out, MSG_PIPE_NOT_N_42SH);
	return (1);
}

static void		fn_exe(register t_main_42sh *array,
register char **lp_arg, register t_jobs_42sh *jobs)
{
	register char				**env_spl;
	register pid_t				pid;

	if ((env_spl = array->env.lp_spl_env) == 0)
	{
		env_spl = ft_42sh_env_split(array->env.env.first,
		array->env.count_env);
		array->env.lp_spl_env = env_spl;
	}
	if ((pid = fork()) == 0)
	{
		array->pr.b_child = 1;
		tcsetattr(STDOUT_FILENO, TCSANOW, &array->tty);
		ft_42sh_pipe_run(array, jobs);
		if (jobs->path == 0)
			execve(lp_arg[0], lp_arg, env_spl);
		else
			execve(jobs->path, lp_arg, env_spl);
		ft_42sh_exit(E_EXE_CODE_42SH);
	}
	else if (pid < 0)
		return (ft_42sh_dsp_err_msg(array, MSG_FOOR_42SH));
	ft_42sh_pipe_left(array, jobs);
	ft_42sh_pipe_right(array, jobs);
	jobs->pid = pid;
}

static void		fn_while(register t_main_42sh *array,
register t_jobs_42sh *jobs, register size_t count)
{
	register char				**lp_arg;
	register int				*fds;

	while (--count > 0)
		jobs = jobs->prev;
	while (jobs != 0)
	{
		lp_arg = jobs->lp_arg;
		count = jobs->b_fd_left | jobs->b_fd_right;
		fds = &jobs->fds[0];
		while (count != 0)
		{
			if ((count & 0x1) != 0)
				if (pipe(fds) != 0)
					ft_42sh_exit(E_PIPE_CODE_42SH);
			count = count >> 1;
			fds += 2;
		}
		if (jobs->b_type == AUTO_TYPE_FUN)
			ft_42sh_pipe_fun(array, jobs, lp_arg, (void *)jobs->path);
		else
			fn_exe(array, lp_arg, jobs);
		ft_42sh_jobs_fd_close(jobs, 1);
		jobs = jobs->next;
	}
}

size_t			ft_42sh_exe(register t_main_42sh *array)
{
	register t_jobs_42sh		*jobs;
	register size_t				out;

	jobs = array->pr.jb.last;
	ft_write_buffer(&array->out);
	fn_while(array, jobs, jobs->count);
	out = fn_finish(array, jobs, jobs->count);
	ft_42sh_jobs_free_list_count(array, jobs);
	return (out);
}
