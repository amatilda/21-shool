/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_corection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_exp.h"

void		ft_42sh_exp_corection(register t_replase_in_42sh *in)
{
	register t_exp_set_42sh			*exps_set_tmp;

	((t_jobs_42sh *)in->array->pr.jb.last)->exps_loop = 0;
	if ((exps_set_tmp =
	((t_jobs_42sh *)in->array->pr.jb.last)->exps_set_tmp) == 0)
		return ;
	((t_jobs_42sh *)in->array->pr.jb.last)->exps_set_tmp = 0;
	if (((t_jobs_42sh *)in->array->pr.jb.last)->exps_set == 0)
		((t_jobs_42sh *)in->array->pr.jb.last)->exps_set = exps_set_tmp;
	else
		((t_jobs_42sh *)in->array->pr.jb.last)->exps_set_end->next =
		exps_set_tmp;
	while (exps_set_tmp->next != 0)
		exps_set_tmp = exps_set_tmp->next;
	((t_jobs_42sh *)in->array->pr.jb.last)->exps_set_end = exps_set_tmp;
}
