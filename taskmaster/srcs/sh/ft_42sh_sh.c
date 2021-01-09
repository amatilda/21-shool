/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_sh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_sh.h"

static void		*fn_set(register t_main_42sh *array,
register t_jobs_42sh *jobs, register char **lp_arg)
{
	register unsigned char		*path;
	register char				**tmp;

	jobs->lp_arg = 0;
	if ((tmp = array->sh.lp_arg) != 0)
		ft_strsplit_free(tmp);
	path = (void *)lp_arg[0];
	array->sh.path = path;
	array->sh.count_path = ft_strlen((void *)path);
	array->sh.lp_arg = lp_arg;
	return (path);
}

void			ft_42sh_sh(register t_main_42sh *array,
register t_jobs_42sh *jobs, register char **env_spl, register char **lp_arg)
{
	register unsigned char		*b;
	register t_in_42sh			*list;
	register size_t				count;

	list = ft_42sh_sh_get(array, env_spl, fn_set(array, jobs, lp_arg), lp_arg);
	b = array->sh.lp_sh;
	ft_42sh_sh_standart(array, list, b, array->sh.lp_sh_e);
	ft_free(b);
	b = (void *)list->lp_b;
	if (ft_42sh_dq_test(array, list, b, b + list->count) != 0)
		ft_42sh_sh_exit(array, array->env.exit_status->number);
	if ((count = list->slesh_max) != 0)
		ft_42sh_dq_split(list, count);
	ft_42sh_parsing_grup(array, list, 0);
	ft_42sh_sh_exit(array, array->env.exit_status->number);
}