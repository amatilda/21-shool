/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dsp_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_42sh_dsp_clear_auto(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t				count;
	register size_t				count_litter;

	if (array->lp_auto->b_view == 0)
		return ;
	array->lp_auto->b_view = 0;
	count = list->lp_b + list->count - list->lp_current;
	count_litter = list->count_litter - list->count_litter_current;
	ft_42sh_dsp_caret_right(array, list, count_litter, count);
	ft_write_buffer_str_zero(&array->out, "\x1b[J");
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
}

void			ft_42sh_dsp_clear_select(register t_main_42sh *array,
register t_in_42sh *list)
{
	register char				*b;
	register size_t				count;
	register size_t				count_litter;
	register size_t				slesh;

	if ((b = (void *)array->slc.b) == 0)
		return ;
	count = (char *)array->slc.e - b;
	count_litter = array->slc.count_litter;
	array->slc.b = 0;
	if (b == list->lp_current)
		ft_42sh_dsp_caret_right(array, list, count_litter, count);
	else
		b = 0;
	slesh = list->slesh_current;
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
	ft_write_buffer_str(&array->out, list->lp_current, count);
	list->lp_current += count;
	list->slesh_current = slesh;
	list->count_litter_current += count_litter;
	if (b != 0)
		ft_42sh_dsp_caret_left(array, list, count_litter, count);
}
