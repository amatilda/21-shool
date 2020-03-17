/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe_fun_run.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exe.h"

static void		fn_set_close(register t_main_42sh *array,
register t_jobs_42sh *jobs, register int *fds)
{
	register size_t					tempos;
	register size_t					b_close;

	if (((b_close = jobs->b_fd_right) & (1 << STDOUT_FILENO)) != 0)
		array->out.fd = fds[(STDOUT_FILENO << 1) + PIPE_WRITE_42SH];
	if ((b_close & (1 << STDERR_FILENO)) != 0)
		array->err.fd = fds[(STDERR_FILENO << 1) + PIPE_WRITE_42SH];
	b_close |= jobs->b_fd_left |
	((1 << STDIN_FILENO) | (1 << STDOUT_FILENO) | (1 << STDERR_FILENO));
	if (((tempos = jobs->b_flag_close) & (1 << STDIN_FILENO)) != 0)
		b_close ^= (1 << STDIN_FILENO);
	if ((tempos & (1 << STDOUT_FILENO)) != 0)
		b_close ^= (1 << STDOUT_FILENO);
	if ((tempos & (1 << STDERR_FILENO)) != 0)
		b_close ^= (1 << STDERR_FILENO);
	array->b_fd_close = b_close;
}

void			ft_42sh_exe_fun_run(register t_main_42sh *array,
register t_jobs_42sh *jobs, char **lp_arg,
void (*f)(register t_main_42sh *array, register char **lp_arg))
{
	if (f != ft_42sh_cm_set)
		array->env.exit_status->number = STATUS_OK_42SH;
	array->out.fd = STDOUT_FILENO;
	if (jobs->n != 0)
		fn_set_close(array, jobs, &jobs->fds[0]);
	if (f != ft_42sh_cm_hash)
		array->b_hash = HASH_ALL_42SH;
	f(array, lp_arg);
	if (f != ft_42sh_exe_err)
		jobs->stat_loc = array->env.exit_status->number;
	else
	{
		array->env.exit_status->number = jobs->error;
		jobs->stat_loc = jobs->error;
	}
	ft_write_buffer(&array->out);
	ft_write_buffer(&array->err);
	if (jobs->n != 0)
	{
		array->b_fd_close = ((1 << STDIN_FILENO) | (1 << STDOUT_FILENO) |
		(1 << STDERR_FILENO));
		array->err.fd = STDERR_FILENO;
	}
	array->out.fd = STDIN_FILENO;
}
