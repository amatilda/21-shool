/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe_fun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exe.h"

static size_t	fn_test_fork(register t_jobs_42sh *jobs,
void (*f)(register t_main_42sh *array, register char **lp_arg))
{
	register t_jobs_42sh		*tmp;

	if ((jobs->b_type & AUTO_TYPE_RUN_42SH) != 0)
		return (1);
	if (f == ft_42sh_exe_set || jobs->fd_pipe == 0)
		return (0);
	if ((tmp = jobs->next) == 0 || tmp->count == 1)
		return (0);
	return (1);
}

static void		not_fork(register t_main_42sh *array,
register t_jobs_42sh *jobs, char **lp_arg,
void (*f)(register t_main_42sh *array, register char **lp_arg))
{
	register void				*pwd;
	register t_jobs_42sh		*tmp;

	pwd = array->pwd.path.buff;
	ft_42sh_exe_fun_run(array, jobs, lp_arg, f);
	if (f == ft_42sh_cm_cd && jobs->fd_pipe != 0 && pwd != array->pwd.path.buff
	&& ((tmp = jobs->next) == 0 || tmp->count == 1))
	{
		ft_write_buffer_str_zero(&array->out, "(pwd now: ");
		ft_write_buffer_str_zero(&array->out, (void *)array->pwd.path_view);
		ft_write_buffer_str_zero(&array->out, ")\n");
		ft_write_buffer(&array->out);
	}
}

static void		fn_fork(register t_main_42sh *array,
register t_jobs_42sh *jobs, char **lp_arg,
void (*f)(register t_main_42sh *array, register char **lp_arg))
{
	array->b_location |= LOCATION_FORK_42SH;
	ft_42sh_signal_default();
	ft_42sh_exe_grup_child(array, jobs);
	ft_42sh_exe_fun_run(array, jobs, lp_arg, f);
	ft_42sh_cm_exit_fun(array, array->env.exit_status->number);
}

size_t			ft_42sh_exe_fun(register t_main_42sh *array,
register t_jobs_42sh *jobs, char **lp_arg,
void (*f)(register t_main_42sh *array, register char **lp_arg))
{
	register pid_t				pid;

	if (jobs->n != 0)
		if (ft_42sh_pipe_left(array, jobs) == 0 ||
		ft_42sh_pipe_right(array, jobs) == 0)
			return (ft_42sh_exe_err_foor(array, jobs));
	if (fn_test_fork(jobs, f) != 0)
	{
		if ((pid = fork()) == 0)
			fn_fork(array, jobs, lp_arg, f);
		else if (pid < 0)
			return (ft_42sh_exe_err_foor(array, jobs));
		ft_42sh_exe_grup(array, jobs, pid);
	}
	else
	{
		not_fork(array, jobs, lp_arg, f);
		if (jobs->stat_loc == STATUS_JOBS_STOP_42SH)
			return (0);
	}
	return (1);
}
