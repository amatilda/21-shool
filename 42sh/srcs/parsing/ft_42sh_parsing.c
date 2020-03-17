/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_parsing.h"

static void			fn_init_list(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t				count;
	register unsigned char		*b;
	register t_in_42sh			*new;
	register t_in_42sh			*prev;

	b = (void *)list->lp_b;
	count = list->count;
	while (count != 0 && b++[0] <= 0x20)
		count--;
	if (count != 0 || list->spl_slesh != 0)
	{
		if (list->next == 0)
			ft_42sh_list_in_create(array, BUFFER_READ_42SH);
		else
		{
			new = ft_42sh_list_in_create_dup_full(array, list);
			list = array->in.in_last;
			new->next = list;
			prev = list->prev;
			list->prev = new;
			prev->next = new;
			new->prev = prev;
		}
	}
}

void				ft_42sh_parsing_grup(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char litter)
{
	register unsigned char		*e;
	register unsigned char		*b;

	if (litter == PARSING_FALTURE_42SH)
		return ;
	b = (void *)list->lp_b;
	e = b + list->count;
	array->dq.hrdoc_next_lp = b;
	array->dq.hrdoc_start_lp = b;
	array->pr.jobs_last = 0;
	ft_42sh_parsing_while(array, list, b, e);
	ft_42sh_dq_unalias_split_re(array, list);
}

void				ft_42sh_parsing(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char litter)
{
	register t_in_42sh			*parser;

	if ((parser = array->dq.in_dquote) != 0)
	{
		array->dq.in_dquote = 0;
		ft_42sh_parsing_grup(array, parser, litter);
	}
	else
	{
		ft_42sh_dq_alias_spl(array, list);
		ft_42sh_parsing_grup(array, list, litter);
		fn_init_list(array, list);
	}
	ft_42sh_list_in_last(array);
	ft_42sh_list_in_dup_restore(array);
	ft_42sh_list_in_limit(array);
	if (array->b_quest_exit == 0)
		ft_42sh_dsp_start(array);
	ft_42sh_jobs_clean(array);
}
