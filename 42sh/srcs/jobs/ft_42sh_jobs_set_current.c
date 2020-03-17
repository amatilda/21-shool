/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_set_current.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static t_jobs_42sh	*fn_test(register t_main_42sh *array)
{
	register t_jobs_42sh		*jobs;

	if (array->pr.jb.first == 0)
		return (0);
	if ((jobs = array->pr.jobs_current) == 0)
		return (array->pr.jb.last);
	return (jobs->prev);
}

void			ft_42sh_jobs_set_current(register t_main_42sh *array)
{
	register size_t				count;
	register t_jobs_42sh		*jobs;

	if ((jobs = fn_test(array)) == 0)
	{
		array->pr.jobs_minus = 0;
		array->pr.jobs_plus = 0;
		return ;
	}
	count = jobs->count;
	while (count-- > 1)
		jobs = jobs->prev;
	array->pr.jobs_plus = jobs;
	if ((jobs = jobs->prev) == 0)
	{
		array->pr.jobs_minus = 0;
		return ;
	}
	count = jobs->count;
	while (count-- > 1)
		jobs = jobs->prev;
	array->pr.jobs_minus = jobs;
}
