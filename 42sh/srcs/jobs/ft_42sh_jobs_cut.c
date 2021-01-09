/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_cut.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void			fn_set(register t_main_42sh *array,
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

static void			fn_set_id(register t_main_42sh *array,
register t_jobs_42sh *jobs, register t_jobs_42sh *last)
{
	if (last == 0 && jobs == 0)
		array->pr.jb_id.first = 0;
	else if (jobs == 0)
	{
		array->pr.jb_id.first = last;
		last->prev_id = 0;
	}
	else if (last == 0)
	{
		array->pr.jb_id.last = jobs;
		jobs->next_id = 0;
	}
	else
	{
		jobs->next_id = last;
		last->prev_id = jobs;
	}
}

t_jobs_42sh			*ft_42sh_jobs_cut(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	register size_t				count;
	register t_jobs_42sh		*last;
	register t_jobs_42sh		*tmp;

	count = jobs->count;
	last = jobs;
	while (count-- > 1)
		jobs = jobs->prev;
	while ((tmp = last->next) != 0 && tmp->count != 1)
		last = tmp;
	fn_set(array, jobs->prev, last->next);
	fn_set_id(array, jobs->prev_id, jobs->next_id);
	last->next = 0;
	return (jobs);
}
