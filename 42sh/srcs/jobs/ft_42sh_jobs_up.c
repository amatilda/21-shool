/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_up.c                                  :+:      :+:    :+:   */
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

void				ft_42sh_jobs_up(register t_main_42sh *array,
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
	if (last == (tmp = array->pr.jb.last))
		return ;
	fn_set(array, jobs->prev, last->next);
	tmp->next = jobs;
	jobs->prev = tmp;
	array->pr.jb.last = jobs;
	last->next = 0;
}
