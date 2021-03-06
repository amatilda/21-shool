/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_create.c                           :+:      :+:    :+:   */
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

	if ((list = ft_malloc(sizeof(t_in_42sh))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	if ((tempos = ft_malloc(max)) == 0)
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
	if (list->max_dup != 0 && (tmp = (void **)list->spl_slesh_dup) != 0)
		ft_strsplit_free((char **)tmp);
	ft_free(list->lp_b);
	ft_free(list);
}
