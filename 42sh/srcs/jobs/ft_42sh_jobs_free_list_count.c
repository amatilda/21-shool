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

static void		fn_free(register t_jobs_42sh *jobs)
{
	register void				*tmp;
	register t_exp_set_42sh		*exp_set;

	exp_set = jobs->exp_set;
	while (exp_set != 0)
	{
		tmp = (void *)exp_set;
		exp_set = exp_set->next;
		ft_free(tmp);
	}
	if ((tmp = (void *)jobs->lp_arg) != 0)
		ft_strsplit_free((char **)tmp);
	if (((jobs->b_type & AUTO_TYPE_FUN_42SH) == 0 && (tmp = jobs->path) != 0))
		ft_free(tmp);
	if ((tmp = jobs->cmd) != 0)
		ft_free(tmp);
	ft_free(jobs);
}

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
		fn_free(tmp);
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
		fn_free(tmp);
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
		fn_free(tmp);
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
		fn_free(tmp);
	}
}
