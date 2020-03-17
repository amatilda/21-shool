/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_up_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_common(register t_main_42sh *array,
register t_in_42sh *list, register t_in_42sh *up_down)
{
	register t_write_buff	*out;
	register size_t			tempos;

	out = &array->out;
	ft_42sh_str_full_home(array, list);
	ft_write_buffer_str_zero(out, "\x1b[J");
	array->in.in_current = up_down;
	up_down->slesh_current = up_down->slesh_max;
	if ((tempos = up_down->count) != 0)
	{
		up_down->lp_current = up_down->lp_b + tempos;
		ft_write_buffer_str(out, up_down->lp_b, tempos);
		ft_write_buffer_str_zero(out, " \x1b[1D");
		up_down->count_litter_current = up_down->count_litter;
	}
}

void			ft_42sh_key_up(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_in_42sh	*up_down;

	if (ft_42sh_dsp_caret_raw_up(array, list) == 0)
		return ;
	if ((up_down = list->prev) == 0)
	{
		ft_write_buffer_str_zero(&array->out, "\x7");
		return ;
	}
	fn_common(array, list, up_down);
}

void			ft_42sh_key_down(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_in_42sh	*up_down;

	if (ft_42sh_dsp_caret_raw_down(array, list) == 0)
		return ;
	if ((up_down = list->next) == 0)
	{
		ft_write_buffer_str_zero(&array->out, "\x7");
		return ;
	}
	fn_common(array, list, up_down);
}
