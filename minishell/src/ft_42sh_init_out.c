/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_42sh_list_in_dup(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_in_42sh	*new;
	register char		*lp_b;

	if ((new = malloc(sizeof(t_in_42sh))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_memcpy(new, list, sizeof(t_in_42sh));
	if ((lp_b = malloc(list->max)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_memcpy(lp_b, list->lp_b, list->max);
	new->lp_b = lp_b;
	new->lp_current = lp_b + (list->lp_current - list->lp_b);
	list->spl_slesh = ft_42s_dq_split_dup(list->spl_slesh, list->slesh_max + 1);
	new->max_dup = 0;
	array->in.in_count++;
	list = array->in.in_last;
	new->next = list;
	lp_b = (char *)list->prev;
	list->prev = new;
	((t_in_42sh *)lp_b)->next = new;
	new->prev = (t_in_42sh *)lp_b;
}

static void		fn_dup_restore(register t_in_42sh *list)
{
	register size_t		max;
	register char		**tmp;

	while (list != 0)
	{
		if ((max = list->max_dup) != 0)
		{
			free(list->lp_b);
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
		list = list->prev;
	}
}

static void		fn_limit_list(register t_main_42sh *array)
{
	register size_t		count;
	register t_in_42sh	*list;
	register t_in_42sh	*tempos;

	count = array->in.in_count;
	if (count <= LIMIT_LIST_42SH)
		return ;
	list = array->in.in_first;
	while (count > LIMIT_LIST_42SH)
	{
		tempos = list;
		list = list->next;
		ft_42sh_list_in_free(tempos);
		count--;
	}
	list->prev = 0;
	array->in.in_first = list;
	array->in.in_count = count;
}

void			ft_42sh_init_out(register t_main_42sh *array,
register t_in_42sh *list, uint_fast8_t b_test)
{
	register size_t			count;
	register unsigned char	*tempos;

	tempos = (unsigned char *)list->lp_b;
	count = list->count;
	while (count != 0 && tempos++[0] <= 0x20)
		count--;
	if (count != 0 || b_test != 0 || list->spl_slesh != 0)
	{
		if (list->next == 0)
			ft_42sh_list_in_create(array, BUFFER_READ_42SH);
		else
			fn_42sh_list_in_dup(array, list);
	}
	ft_42sh_list_in_deffault(array);
	fn_dup_restore(list);
	fn_limit_list(array);
}
