/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_free_list_count.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_set(register t_main_42sh *array,
register t_jobs_42sh *jobs, register t_jobs_42sh *last)
{
	if (last == 0 && jobs == 0)
		array->pr.jb.first = 0;
	else if (jobs == 0)
	{
		array->pr.jb.first = last;
		last->prev = 0;
	}
	else if (last == 0)
	{
		array->pr.jb.last = jobs;
		jobs->next = 0;
	}
	else
	{
		jobs->next = last;
		last->prev = jobs;
	}
}

static void		fn_free(register t_jobs_42sh *jobs)
{
	register void				*tmp;

	ft_strsplit_free(jobs->lp_arg);
	if (jobs->b_type == AUTO_TYPE_EXE && (tmp = jobs->path) != 0)
		free(tmp);
	ft_free(jobs);
}

void			ft_42sh_jobs_free_list_count(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	register t_jobs_42sh		*tmp;
	register t_jobs_42sh		*last;
	register size_t				count;

	last = jobs->next;
	count = jobs->count;
	while (count-- > 0)
	{
		tmp = jobs;
		jobs = jobs->prev;
		fn_free(tmp);
	}
	fn_set(array, jobs, last);
}

void			ft_42sh_jobs_free_list_count_err(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	register t_jobs_42sh		*tmp;
	register t_jobs_42sh		*last;
	register size_t				count;

	last = jobs->next;
	count = jobs->count;
	if ((unsigned int)jobs->fd_pipe > PIPE_42SH)
		close(jobs->fd_pipe);
	while (count-- > 0)
	{
		tmp = jobs;
		jobs = jobs->prev;
		ft_42sh_jobs_fd_close(tmp, 0);
		fn_free(tmp);
	}
	fn_set(array, jobs, last);
}
