/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		ft_42sh_dq_cut(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_in_42sh	*last;
	register t_in_42sh	*prev;

	ft_42sh_init_out(array, list, 1);
	last = array->in.in_last;
	prev = last->prev;
	array->in_dquote = prev;
	prev->slesh_max = 0;
	prev->count_litter -= array->msg.pre_msg_litter;
	prev = prev->prev;
	if (prev != 0)
		prev->next = last;
	else
		array->in.in_first = last;
	last->prev = prev;
}

void		ft_42sh_dq_paste(register t_main_42sh *array)
{
	register t_in_42sh	*last;
	register t_in_42sh	*prev;
	register t_in_42sh	*dquote;

	dquote = array->in_dquote;
	if (dquote->count == 0)
		return (ft_42sh_list_in_free(dquote));
	last = array->in.in_last;
	dquote->slesh_current = dquote->slesh_max;
	ft_42s_dq_split(dquote, dquote->slesh_max);
	dquote->lp_current = dquote->lp_b;
	dquote->count_litter_current = array->msg.pre_msg_litter;
	dquote->count_litter += array->msg.pre_msg_litter;
	prev = last->prev;
	if (prev != 0)
		prev->next = dquote;
	else
		array->in.in_first = dquote;
	last->prev = dquote;
	dquote->next = last;
	dquote->prev = prev;
	ft_42sh_list_in_deffault(array);
}
