/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void				fn_zero_create(register t_in_42sh *list)
{
	list->max_dup = 0;
	list->count = 0;
	list->next = 0;
	list->prev = 0;
	list->spl_slesh = 0;
}

t_in_42sh				*ft_42sh_list_in_create(register t_main_42sh *array,
register size_t max)
{
	register t_in_42sh	*list;
	register t_in_42sh	*tempos;

	list = malloc(sizeof(t_in_42sh));
	if ((tempos = malloc(max)) == 0 || list == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	list->lp_current = (char *)tempos;
	list->lp_b = (char *)tempos;
	list->max = max;
	max = array->msg.pre_msg_litter;
	list->count_litter = max;
	list->count_litter_current = max;
	fn_zero_create(list);
	array->in.in_count++;
	if ((tempos = array->in.in_last) != 0)
	{
		tempos->next = list;
		list->prev = tempos;
	}
	array->in.in_current = list;
	array->in.in_last = list;
	return (list);
}

void					ft_42sh_list_in_free(register t_in_42sh *list)
{
	register void		**tmp;

	if ((tmp = (void **)list->spl_slesh) != 0)
		ft_strsplit_free((char **)tmp);
	if ((tmp = (void **)list->spl_slesh_dup) != 0)
		ft_strsplit_free((char **)tmp);
	free(list->lp_b);
	free(list);
}

void					ft_42sh_list_in_dup(register t_in_42sh *list)
{
	register char		*dup;
	register size_t		max;

	if (list->max_dup != 0 || list->next == 0)
		return ;
	max = list->max;
	if ((dup = malloc(max)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_memcpy(dup, list->lp_b, list->count);
	list->lp_b_dup = dup;
	list->max_dup = max;
	list->count_dup = list->count;
	list->count_litter_dup = list->count_litter;
	list->count_litter_current_dup = list->count_litter_current;
	list->slesh_max_dup = list->slesh_max;
	list->spl_slesh_dup =
	ft_42s_dq_split_dup(list->spl_slesh, list->slesh_max + 1);
}

void					ft_42sh_list_in_deffault(register t_main_42sh *array)
{
	register void			**tmp;
	register size_t			count;
	register t_in_42sh		*list;

	list = array->in.in_last;
	array->in.in_current = list;
	list->lp_current = list->lp_b;
	list->count = 0;
	count = array->msg.pre_msg_litter;
	list->count_litter = count;
	list->count_litter_current = count;
	if ((tmp = (void **)list->spl_slesh) != 0)
	{
		ft_strsplit_free((char **)tmp);
		list->spl_slesh = 0;
	}
}
