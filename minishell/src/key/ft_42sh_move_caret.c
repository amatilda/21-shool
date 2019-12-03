/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_move_caret.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void			fn_clear(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t				count;
	register size_t				count_litter;

	if (array->tab.b_view == 0)
		return ;
	array->tab.b_view = 0;
	count = list->lp_b + list->count - list->lp_current;
	count_litter = list->count_litter - list->count_litter_current;
	ft_42sh_dsp_caret_right(array, list, count_litter, count);
	ft_write_buffer_str_zero(&array->out, "\x1b[J");
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
}

void				ft_42sh_key_left(register t_main_42sh *array,
register t_in_42sh *list)
{
	register char				*current;
	register char				litter;

	if (list->lp_current == list->lp_b)
		return ;
	current = list->lp_current;
	while (((litter = current--[-1]) & 0x80) != 0 && (litter & 0x40) == 0)
		;
	if (litter == '\n')
		ft_42sh_dsp_caret_left(array, list, 0, list->lp_current - current + 1);
	else
		ft_42sh_dsp_caret_left(array, list, 1, list->lp_current - current);
	fn_clear(array, list);
}

void				ft_42sh_key_right(register t_main_42sh *array,
register t_in_42sh *list)
{
	register char		*current;
	register char		litter;

	if (list->count_litter_current == list->count_litter &&
	list->lp_b + list->count == list->lp_current)
		return ;
	current = list->lp_current;
	litter = current++[0];
	if ((litter & 0x80) != 0)
	{
		while (((litter = current[0]) & 0x80) != 0 && (litter & 0x40) == 0)
			current++;
	}
	if (litter == ' ' && list->lp_b + list->count != current &&
	current[0] == '\n')
		ft_42sh_dsp_caret_right(array, list, 0, current - list->lp_current + 1);
	else
		ft_42sh_dsp_caret_right(array, list, 1, current - list->lp_current);
	fn_clear(array, list);
}
