/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe_while.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exe.h"

static void			fn_exe_fork(register t_main_42sh *array,
register char **lp_arg, register t_jobs_42sh *jobs, int *fds)
{
	register char				**env_spl;
	register unsigned char		*path;

	ft_42sh_exe_fork(array, jobs, fds);
	ft_42sh_exe_set_(array, jobs->exp_set, EXP_TYPE_EVERIMENT_42SH);
	env_spl = ft_42sh_exp_split_env(array);
	ft_42sh_pipe_run(array, jobs);
	path = (void *)lp_arg[0];
	if (jobs->path == 0 && ft_42sh_pattern(path, path +
	ft_strlen((void *)path), (void *)MSG_SH_TEST_42SH,
	(void *)(MSG_SH_TEST_42SH + sizeof(MSG_SH_TEST_42SH) - 1)) != 0)
		ft_42sh_sh(array, jobs, env_spl, lp_arg);
	close(FD_TERMINAL_42SH);
	if (jobs->path == 0)
		execve(lp_arg[0], lp_arg, env_spl);
	else
		execve(jobs->path, lp_arg, env_spl);
	ft_42sh_exit(E_EXE_CODE_42SH, __FILE__, __func__, __LINE__);
}

static size_t		fn_exe(register t_main_42sh *array,
register char **lp_arg, register t_jobs_42sh *jobs)
{
	register pid_t				pid;
	int							fds[2];

	if (pipe(&fds[0]) != 0)
		ft_42sh_exit(E_PIPE_CODE_42SH, __FILE__, __func__, __LINE__);
	if ((pid = fork()) == 0)
		fn_exe_fork(array, lp_arg, jobs, &fds[0]);
	else if (pid < 0)
	{
		close(fds[PIPE_READ_42SH]);
		close(fds[PIPE_WRITE_42SH]);
		return (ft_42sh_exe_err_foor(array, jobs));
	}
	array->b_hash = HASH_ALL_42SH;
	ft_42sh_exe_grup(array, jobs, pid, &fds[0]);
	return (1);
}

static size_t		fn_run(register t_main_42sh *array,
register t_jobs_42sh *jobs, register char **lp_arg, register size_t b_test)
{
	jobs->b_type = jobs->b_type | b_test;
	ft_42sh_exe_set(array, (char **)jobs->exps_set);
	if (jobs->b_type == AUTO_TYPE_SET_42SH)
	{
		return (ft_42sh_exe_fun(array, jobs, (char **)jobs->exp_set,
		ft_42sh_exe_set));
	}
	else if (jobs->b_type == AUTO_TYPE_SET_RUN_42SH)
		return (ft_42sh_exe_fun(array, jobs, 0, ft_42sh_exe_set));
	else if ((jobs->b_type & AUTO_TYPE_ERROR_42SH) != 0)
	{
		return (ft_42sh_exe_fun(array, jobs, (char **)jobs->path,
		ft_42sh_exe_err));
	}
	else if ((jobs->b_type & AUTO_TYPE_FUN_42SH) != 0)
		return (ft_42sh_exe_fun(array, jobs, lp_arg + 1, (void *)jobs->path));
	else
		return (fn_exe(array, lp_arg, jobs));
}

static void			fn_pre(register t_main_42sh *array)
{
	array->pr.pid_fork = 0;
	if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
		array->pr.pid_grup = array->pr.pid_main;
	else
		array->pr.pid_grup = 0;
}

size_t				ft_42sh_exe_while(register t_main_42sh *array,
register t_jobs_42sh *jobs, register size_t b_test)
{
	register size_t				count;
	register int				*fds;
	register int				fd;

	fn_pre(array);
	while (0xFF)
	{
		count = jobs->b_fd_left | jobs->b_fd_right;
		fds = &jobs->fds[0];
		fd = 0;
		while (count != 0)
		{
			if ((count & 0x1) != 0)
				ft_42sh_pipe_find(array, jobs, fds, fd);
			count = count >> 1;
			fd++;
			fds += 2;
		}
		count = fn_run(array, jobs, jobs->lp_arg, b_test);
		ft_42sh_jobs_fd_close(jobs, 1);
		if (count == 0)
			return (jobs->stat_loc);
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			return (0);
	}
}
