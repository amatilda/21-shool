/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_default.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void					ft_42sh_list_in_default(register t_main_42sh *array,
register t_in_42sh *list)
{
	register void			**tmp;
	register size_t			count;

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

void					ft_42sh_list_in_last(register t_main_42sh *array)
{
	register t_in_42sh		*list;

	list = array->in.in_last;
	array->in.in_current = list;
	ft_42sh_list_in_default(array, list);
}
