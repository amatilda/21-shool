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
	ft_memset(list, 0xFF, sizeof(t_in_42sh));
	list->max_dup = 0;
	list->count = 0;
	list->next = 0;
	list->prev = 0;
	list->spl_slesh = 0;
}

static void				fn_set(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_in_42sh	*tempos;

	tempos = array->in.in_last;
	tempos->next = list;
	list->prev = tempos;
}

t_in_42sh				*ft_42sh_list_in_create(register t_main_42sh *array,
register size_t max)
{
	register t_in_42sh	*list;
	register t_in_42sh	*tempos;

	if ((list = ft_malloc(sizeof(t_in_42sh))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	if ((tempos = ft_malloc(max)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	fn_zero_create(list);
	list->lp_current = (char *)tempos;
	list->lp_b = (char *)tempos;
	list->max = max;
	max = array->msg.pre_msg_litter;
	list->count_litter = max;
	list->count_litter_current = max;
	array->in.in_count++;
	if (array->in.in_first != 0)
		fn_set(array, list);
	else
		array->in.in_first = list;
	array->in.in_current = list;
	array->in.in_last = list;
	return (list);
}
