/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_jobs_killgrp.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

void			ft_42sh_cm_jobs_killgrp(register t_jobs_42sh *jobs,
register int signo)
{
	register pid_t				pid;
	register size_t				count;

	count = jobs->count;
	while (count-- > 1)
		jobs = jobs->prev;
	while (0xFF)
	{
		if ((pid = jobs->pid_view) != 0)
		{
			kill(~pid + 1, signo);
			return ;
		}
		if ((jobs = jobs->next) == 0 || jobs->count == 1)
			return ;
	}
}
