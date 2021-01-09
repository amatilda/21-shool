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
		if (list->max_dup != 0)
		{
			list->count_litter_dup += offset;
			list->count_litter_current_dup += offset;
		}
		list = list->next;
	}
}

static size_t	fn_set_add(register t_main_42sh *array)
{
	register size_t		offset;

	offset = PRE_MSG_LITTER_42SH - array->msg.pre_msg_litter;
	array->msg.pre_msg = PRTF_BOLT""MSG_42SH""PRTF_RESET;
	array->msg.pre_msg_litter = PRE_MSG_LITTER_42SH;
	return (offset);
}

static size_t	fn_set(register t_main_42sh *array,
register unsigned char litter)
{
	register size_t		offset;

	if (litter == '<')
	{
		offset = array->msg.hrdc_lit - array->msg.pre_msg_litter;
		array->msg.pre_msg = array->msg.hrdc;
		array->msg.pre_msg_litter = array->msg.hrdc_lit;
	}
	else if (litter == '}' || litter == ')')
	{
		offset = PRE_MSG_SUB_LITTER_42SH - array->msg.pre_msg_litter;
		array->msg.pre_msg = PRTF_BOLT""MSG_SUB_42SH""PRTF_RESET;
		array->msg.pre_msg_litter = PRE_MSG_SUB_LITTER_42SH;
	}
	else if (litter == '&' || litter == '|')
	{
		offset = PRE_MSG_CMD_LITTER_42SH - array->msg.pre_msg_litter;
		array->msg.pre_msg = PRTF_BOLT""MSG_CMD_42SH""PRTF_RESET;
		array->msg.pre_msg_litter = PRE_MSG_CMD_LITTER_42SH;
	}
	else
		offset = fn_set_add(array);
	return (offset);
}

void			ft_42sh_msg_change(register t_main_42sh *array,
register unsigned char litter, unsigned char litter_prev)
{
	register size_t		offset;

	if (litter_prev == litter)
		return ;
	array->dq.dquote = litter;
	if (litter == '"')
	{
		offset = PRE_MSG_DQUOTE_LITTER_42SH - array->msg.pre_msg_litter;
		array->msg.pre_msg = PRTF_BOLT""MSG_DQUOTE_42SH""PRTF_RESET;
		array->msg.pre_msg_litter = PRE_MSG_DQUOTE_LITTER_42SH;
	}
	else if (litter == '\'')
	{
		offset = PRE_MSG_QUOTE_LITTER_42SH - array->msg.pre_msg_litter;
		array->msg.pre_msg = PRTF_BOLT""MSG_QUOTE_42SH""PRTF_RESET;
		array->msg.pre_msg_litter = PRE_MSG_QUOTE_LITTER_42SH;
	}
	else
		offset = fn_set(array, litter);
	fn_while(array->in.in_first, offset);
}
