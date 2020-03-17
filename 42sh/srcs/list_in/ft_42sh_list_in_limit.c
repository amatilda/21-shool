/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_limit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		ft_42sh_list_in_limit(register t_main_42sh *array)
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
