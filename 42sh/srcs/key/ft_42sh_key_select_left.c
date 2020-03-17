/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_select_left.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_left(register t_main_42sh *array,
register t_in_42sh *list, register char *current, uint_fast8_t b_action)
{
	register char				litter;
	register char				*tmp;
	register t_write_buff		*out;

	out = &array->out;
	tmp = current;
	if (((litter = tmp++[0]) & 0x80) != 0)
		while (((litter = litter << 1) & 0x80) != 0)
			tmp++;
	if (b_action != 0)
		ft_write_buffer_str_zero(out, PRTF_INVERT);
	ft_write_buffer_str(out, current, tmp - current);
	ft_42sh_key_right(array, list);
	if (b_action != 0)
		ft_write_buffer_str_zero(out, PRTF_RESET);
	ft_42sh_key_left(array, list);
}

static void		fn_unselect(register t_main_42sh *array,
register t_in_42sh *list, register void *b, register void *e)
{
	if (((char *)e)[-1] == '\n')
	{
		array->slc.e = b;
		return ;
	}
	if (--array->slc.count_litter == 0)
		array->slc.b = 0;
	else
		array->slc.e = b;
	return (fn_left(array, list, b, 0));
}

void			ft_42sh_select_left(register t_main_42sh *array,
register t_in_42sh *list)
{
	register void				*e;
	register void				*tmp;
	register void				*b;

	e = list->lp_current;
	if (ft_42sh_key_left(array, list) == 0)
		return ;
	b = list->lp_current;
	if ((tmp = array->slc.b) == 0)
	{
		array->slc.count_litter = 0;
		array->slc.e = e;
	}
	else if (tmp <= b)
		return (fn_unselect(array, list, b, e));
	array->slc.b = b;
	if (((char *)e)[-1] == '\n')
		return ;
	array->slc.count_litter++;
	fn_left(array, list, b, 1);
}
