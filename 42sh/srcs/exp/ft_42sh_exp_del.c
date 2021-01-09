/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_exp.h"

static void		fn_set(register t_past_sort_42sh *root,
register t_env_42sh *list, register t_env_42sh *prev,
register t_env_42sh *next)
{
	if (prev != 0 && next != 0)
	{
		prev->std.next = (void *)next;
		next->std.prev = (void *)prev;
	}
	else if (prev != 0)
		prev->std.next = 0;
	else if (next != 0)
		next->std.prev = 0;
	if (next == 0 && list == root->last)
		root->last = prev;
	if (prev == 0 && list == root->first)
		root->first = next;
	if (list == root->center)
	{
		if (prev != 0)
			root->center = prev;
		else
			root->center = next;
	}
}

void			ft_42sh_exp_del(register t_main_42sh *array,
register t_past_sort_42sh *root, register t_env_42sh *list)
{
	fn_set(root, list, (void *)list->std.prev, (void *)list->std.next);
	ft_42sh_exp_spc_del(array, (void *)list->std.lp_key, list->std.key_count);
	if ((list->b_type & EXP_TYPE_EVERIMENT_42SH) != 0)
		array->env.count_env--;
	else
		array->env.count_local--;
	ft_42sh_exp_spc_correction(array, list);
	ft_free(list);
}
