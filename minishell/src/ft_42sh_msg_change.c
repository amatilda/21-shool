/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_msg_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_while(register t_in_42sh *list, register size_t offset)
{
	while (list != 0)
	{
		list->count_litter += offset;
		list->count_litter_current += offset;
		list = list->next;
	}
}

void			ft_42sh_msg_change(register t_main_42sh *array,
register char litter, char litter_prev)
{
	register size_t		offset;

	if (litter_prev == litter)
		return ;
	array->dquote = litter;
	if (litter == '"')
	{
		offset = PRE_MSG_DQUOTE_LITTER_42SH - array->msg.pre_msg_litter;
		array->msg.pre_msg = PRE_MSG_DQUOTE_42SH;
		array->msg.pre_msg_litter = PRE_MSG_DQUOTE_LITTER_42SH;
	}
	else if (litter == '\'')
	{
		offset = PRE_MSG_QUOTE_LITTER_42SH - array->msg.pre_msg_litter;
		array->msg.pre_msg = PRE_MSG_QUOTE_42SH;
		array->msg.pre_msg_litter = PRE_MSG_QUOTE_LITTER_42SH;
	}
	else
	{
		offset = PRE_MSG_LITTER_42SH - array->msg.pre_msg_litter;
		array->msg.pre_msg = PRE_MSG_42SH;
		array->msg.pre_msg_litter = PRE_MSG_LITTER_42SH;
	}
	fn_while(array->in.in_first, offset);
}
