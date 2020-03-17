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

static void		*fn_path(register t_main_42sh *array,
register unsigned char *path)
{
	register size_t					count;

	count =  ft_strlen((void *)path);
	array->sh.path = path;
	if ((array->sh.path = ft_strndup((void *)path, count)) == 0)
		ft_42sh_sh_exit(ft_42sh_sh_exit_zero_crit(array,
		MSG_SH_INVALID_MEMORY_42SH), STATUS_FALTURE_42SH);
	array->sh.count_path = count;
	return (path);
}

void			ft_42sh_sh(register t_main_42sh *array,
register unsigned char *path, register char **env_spl)
{
	register unsigned char		*b;
	register t_in_42sh			*list;
	register size_t				count;

	path = fn_path(array, path);
	list = ft_42sh_sh_get(array, env_spl, path);
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