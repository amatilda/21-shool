/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

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

void			ft_42sh_pipe_fun(register t_main_42sh *array,
register t_jobs_42sh *jobs, char **lp_arg,
void (*f)(register t_main_42sh *array, register char **lp_arg))
{
	if (jobs->n == 0)
		return (f(array, lp_arg + 1));
	fn_set_close(array, jobs, &jobs->fds[0]);
	f(array, lp_arg + 1);
	ft_write_buffer(&array->out);
	array->b_fd_close = ((1 << STDIN_FILENO) | (1 << STDOUT_FILENO) |
	(1 << STDERR_FILENO));
	array->out.fd = STDOUT_FILENO;
	array->err.fd = STDERR_FILENO;
	ft_42sh_pipe_left(array, jobs);
	ft_42sh_pipe_right(array, jobs);
}
