/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_jobs_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

static t_jobs_42sh	*fn_find(register t_main_42sh *array,
register size_t id)
{
	register t_jobs_42sh		*jobs;

	if (id == 0 || (jobs = array->pr.jb_id.first) == 0)
		return (0);
	while (jobs != 0)
	{
		if (jobs->id == id)
			break ;
		jobs = jobs->next_id;
	}
	if (jobs == array->pr.jobs_current)
		return (0);
	return (jobs);
}

t_jobs_42sh			*ft_42sh_cm_jobs_number(register t_main_42sh *array,
register unsigned char *str, register size_t b_view)
{
	register size_t				id;
	register t_jobs_42sh		*jobs;

	id = ft_atoi((void *)str);
	if ((jobs = fn_find(array, id)) == 0)
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
