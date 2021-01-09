/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_jobs.h"

static void	fn_exp_set(register t_exp_set_42sh *exp_set)
{
	register void				*tmp;

	while (exp_set != 0)
	{
		tmp = (void *)exp_set;
		exp_set = exp_set->next;
		ft_free(tmp);
	}
}

static void	fn_hrdc(register t_jobs_42sh *jobs)
{
	register t_pipe_42sh		*pipe;
	register size_t				n;

	n = jobs->n;
	pipe = &jobs->pipe[0];
	while (n-- != 0)
	{
		if ((pipe->b_heredok & JOBS_HRDC_42SH) != 0)
			ft_free(pipe->lp_heredok_b);
		pipe++;
	}
}

void		ft_42sh_jobs_free(register t_jobs_42sh *jobs)
{
	register void				*tmp;

	fn_exp_set(jobs->exp_set);
	fn_exp_set(jobs->exps_set);
	if ((tmp = (void *)jobs->lp_arg) != 0)
		ft_strsplit_free((char **)tmp);
	if ((((jobs->b_type & AUTO_TYPE_FUN_42SH) == 0 ||
	(jobs->b_type & AUTO_TYPE_ERROR_42SH) != 0) && (tmp = jobs->path) != 0))
		ft_free(tmp);
	if ((tmp = jobs->cmd) != 0)
		ft_free(tmp);
	fn_hrdc(jobs);
	ft_free(jobs);
}
