/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_jobs_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

static t_jobs_42sh	*fn_finish(register t_jobs_42sh *jobs)
{
	register size_t				count;

	if (jobs == 0)
		return (0);
	count = jobs->count;
	while (count-- > 1)
		jobs = jobs->prev;
	return (jobs);
}

static t_jobs_42sh	*fn_find_str(register t_main_42sh *array,
register unsigned char *str, register size_t offset)
{
	register t_jobs_42sh		*jobs;
	register size_t				n;

	jobs = array->pr.jobs_current != 0 ? array->pr.jobs_current->prev :
	array->pr.jb.last;
	n = ft_strlen((void *)str);
	while (jobs != 0 &&
	ft_strncmp((void *)jobs->cmd + offset, (void *)str, n) != 0)
		jobs = jobs->prev;
	return (jobs);
}

static t_jobs_42sh	*fn_find(register t_main_42sh *array,
register unsigned char *str)
{
	register t_jobs_42sh		*jobs;
	register unsigned char		litter;
	register size_t				offset;

	if (array->pr.jb.first == 0)
		return (0);
	if ((litter = str[0]) == 0)
		jobs = array->pr.jobs_current != 0 ? array->pr.jobs_current->prev :
		array->pr.jb.last;
	else
	{
		offset = (litter == '?') ? 1 : 0;
		jobs = fn_find_str(array, str + offset, offset);
	}
	return (fn_finish(jobs));
}

t_jobs_42sh			*ft_42sh_cm_jobs_str(register t_main_42sh *array,
register unsigned char *str, register size_t b_view)
{
	register t_jobs_42sh		*jobs;

	if ((jobs = fn_find(array, str)) == 0)
		return (0);
	if ((b_view & JOBS_MSG_JOBS_42SH) != 0)
	{
		if (jobs == array->pr.jobs_plus)
			b_view = b_view | JOBS_MSG_PLUS_42SH;
		else if (jobs == array->pr.jobs_minus)
			b_view = b_view | JOBS_MSG_MINUS_42SH;
		ft_42sh_jobs_msg(array, jobs, b_view);
	}
	return (jobs);
}
