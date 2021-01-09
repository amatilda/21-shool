/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_signal_child_msg.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_signal.h"

static size_t		fn_flag(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	ft_42sh_jobs_set_current(array);
	if (jobs == array->pr.jobs_plus)
		return (JOBS_MSG_ID_42SH | JOBS_MSG_PLUS_42SH);
	else if (jobs == array->pr.jobs_minus)
		return (JOBS_MSG_ID_42SH | JOBS_MSG_MINUS_42SH);
	return (JOBS_MSG_ID_42SH);
}

static t_jobs_42sh	*fn_test(register t_jobs_42sh *jobs)
{
	register size_t				count;
	register t_jobs_42sh		*last;

	count = jobs->count;
	while (count-- > 1)
		jobs = jobs->prev;
	while (0xFF)
	{
		if (jobs->pid != 0 && WIFSTOPPED(jobs->stat_loc) == 0)
			return (0);
		last = jobs;
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			break ;
	}
	return (last);
}

static void			fn_cut(register t_main_42sh *array,
register t_jobs_42sh *jobs, register t_jobs_42sh *last)
{
	register t_jobs_42sh		*tmp;
	int							stat_loc;

	tmp = jobs;
	while (0xFF)
	{
		stat_loc = tmp->stat_loc;
		if (WIFSTOPPED(stat_loc) != 0 || WTERMSIG(stat_loc) == SIGCONT)
			return ;
		if ((tmp = tmp->next) == 0 || tmp->count == 1)
			break ;
	}
	ft_42sh_jobs_cut(array, jobs);
	tmp = array->pr.jobs_cut;
	array->pr.jobs_cut = jobs;
	last->next = tmp;
}

static void			fn_run_view(register t_main_42sh *array,
register t_jobs_42sh *jobs, register t_write_buff *out,
register size_t b_flag)
{
	array->pr.b_auto_view = 0;
	ft_42sh_jobs_msg(array, jobs, JOBS_MSG_ID_RUN_42SH);
	ft_42sh_jobs_msg(array, jobs, b_flag);
	ft_write_buffer(out);
}

void				ft_42sh_signal_child_msg(register t_main_42sh *array,
register t_jobs_42sh *jobs, register size_t b_test)
{
	register t_jobs_42sh		*last;
	register t_write_buff		*out;
	register size_t				count;
	register size_t				b_flag;

	if ((last = fn_test(jobs)) == 0)
		return ;
	count = jobs->count;
	while (count-- > 1)
		jobs = jobs->prev;
	b_flag = fn_flag(array, jobs);
	fn_cut(array, jobs, last);
	out = &array->out;
	if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
		return ;
	if (b_test == AUTO_TYPE_RUN_42SH && array->pr.b_auto_view != 0)
		return (fn_run_view(array, jobs, out, b_test));
	else if (array->pr.count_runing == 0)
		ft_write_buffer_str_zero(out, "\n");
	ft_42sh_jobs_msg(array, jobs, b_flag);
	if (array->pr.count_runing == 0)
		ft_42sh_signal_child_msg_start(array, out, array->in.in_current);
	ft_write_buffer(out);
}
