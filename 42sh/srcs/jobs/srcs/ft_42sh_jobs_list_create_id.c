/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_list_create_id.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_jobs.h"

static void		fn_set_first(register t_main_42sh *array,
register t_jobs_42sh *out, register t_jobs_42sh *jobs, register size_t count)
{
	register t_jobs_42sh			*prev_id;

	if ((prev_id = jobs->prev_id) == 0)
		array->pr.jb_id.first = out;
	else
	{
		out->prev_id = prev_id;
		prev_id->next_id = out;
	}
	out->next_id = jobs;
	jobs->prev_id = out;
	out->id = count;
}

static void		fn_set_last(register t_main_42sh *array,
register t_jobs_42sh *out, register size_t count)
{
	register t_jobs_42sh			*last;

	last = array->pr.jb_id.last;
	array->pr.jb_id.last = out;
	last->next_id = out;
	out->prev_id = last;
	out->id = count;
}

void			ft_42sh_jobs_list_create_id(register t_main_42sh *array,
register t_jobs_42sh *out, register size_t count)
{
	register t_jobs_42sh				*jobs;
	register size_t						tempos;

	if ((out->count = count) != 1)
		return ;
	if ((jobs = array->pr.jb_id.first) == 0)
	{
		array->pr.jb_id.first = out;
		array->pr.jb_id.last = out;
		out->id = 1;
		return ;
	}
	count = 0;
	while (jobs != 0)
	{
		if ((tempos = jobs->id) != 0)
			if (tempos > ++count)
				return (fn_set_first(array, out, jobs, count));
		jobs = jobs->next_id;
	}
	fn_set_last(array, out, count + 1);
}
