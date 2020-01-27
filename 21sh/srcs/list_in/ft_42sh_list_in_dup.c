/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_dup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void					ft_42sh_list_in_dup(register t_in_42sh *list)
{
	register char		*dup;
	register size_t		max;

	if (list->max_dup != 0 || list->next == 0)
		return ;
	max = list->max;
	if ((dup = ft_malloc(max)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_memcpy(dup, list->lp_b, list->count);
	list->lp_b_dup = dup;
	list->max_dup = max;
	list->count_dup = list->count;
	list->count_litter_dup = list->count_litter;
	list->count_litter_current_dup = list->count_litter_current;
	list->slesh_max_dup = list->slesh_max;
	list->spl_slesh_dup =
	ft_42sh_dq_split_dup(list->spl_slesh, list->slesh_max + 1);
}

static void				fn_set_restore(register t_in_42sh *list,
register size_t max)
{
	register char		**tmp;

	ft_free(list->lp_b);
	list->max_dup = 0;
	list->max = max;
	list->lp_b = list->lp_b_dup;
	list->count = list->count_dup;
	list->count_litter = list->count_litter_dup;
	list->count_litter_current = list->count_litter_current_dup;
	list->slesh_max = list->slesh_max_dup;
	list->slesh_current = list->slesh_max_dup;
	if ((tmp = (char **)list->spl_slesh) != 0)
	{
		ft_strsplit_free(tmp);
		list->spl_slesh = 0;
	}
	list->spl_slesh = list->spl_slesh_dup;
}

void					ft_42sh_list_in_dup_restore(register t_main_42sh *array)
{
	register t_in_42sh	*list;
	register size_t		max;

	list = array->in.in_last;
	while (list != 0)
	{
		if ((max = list->max_dup) != 0)
			fn_set_restore(list, max);
		list = list->prev;
	}
}
