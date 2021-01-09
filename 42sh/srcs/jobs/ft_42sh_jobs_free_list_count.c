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

#include "includes/ft_42sh_jobs.h"

void			ft_42sh_jobs_free_all(register t_main_42sh *array)
{
	register t_jobs_42sh		*jobs;
	register t_jobs_42sh		*tmp;

	ft_42sh_jobs_clean(array);
	if ((jobs = array->pr.jb.first) == 0)
		return ;
	while (jobs != 0)
	{
		tmp = jobs;
		jobs = jobs->next;
		ft_42sh_jobs_free(tmp);
	}
	array->pr.jb.first = 0;
	array->pr.jb_id.first = 0;
}

void			ft_42sh_jobs_clean(register t_main_42sh *array)
{
	register t_jobs_42sh		*jobs;
	register t_jobs_42sh		*tmp;

	if ((jobs = array->pr.jobs_cut) == 0)
		return ;
	array->pr.jobs_cut = 0;
	while (jobs != 0)
	{
		tmp = jobs;
		jobs = jobs->next;
		ft_42sh_jobs_free(tmp);
	}
}

void			ft_42sh_jobs_free_list_count(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	register t_jobs_42sh		*tmp;

	jobs = ft_42sh_jobs_cut(array, jobs);
	while (jobs != 0)
	{
		tmp = jobs;
		jobs = jobs->next;
		ft_42sh_jobs_free(tmp);
	}
}

void			ft_42sh_jobs_free_list_count_err(register t_main_42sh *array,
register t_jobs_42sh *jobs)
{
	register t_jobs_42sh		*tmp;

	if ((unsigned int)jobs->fd_pipe > PIPE_42SH)
		close(jobs->fd_pipe);
	jobs = ft_42sh_jobs_cut(array, jobs);
	while (jobs != 0)
	{
		tmp = jobs;
		jobs = jobs->next;
		ft_42sh_jobs_fd_close(tmp, 0);
		ft_42sh_jobs_free(tmp);
	}
}
