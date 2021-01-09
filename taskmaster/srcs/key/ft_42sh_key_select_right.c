/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_select_right.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_right(register t_main_42sh *array,
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
	if (b_action != 0)
		ft_write_buffer_str_zero(out, PRTF_RESET);
	ft_42sh_key_right(array, list);
}

static void		fn_unselect(register t_main_42sh *array,
register t_in_42sh *list, register void *current, register void *end)
{
	if (end != current + 1 && ((char *)current)[1] == '\n')
	{
		ft_42sh_key_right(array, list);
		array->slc.b = (void *)list->lp_current;
		return ;
	}
	fn_right(array, list, current, 0);
	if (--array->slc.count_litter == 0)
		array->slc.b = 0;
	else
		array->slc.b = (void *)list->lp_current;
}

void			ft_42sh_select_right(register t_main_42sh *array,
register t_in_42sh *list)
{
	register void				*current;
	register void				*tmp;
	register void				*end;

	current = list->lp_current;
	if ((end = list->lp_b + list->count) == current)
		return ;
	if ((tmp = array->slc.b) == 0)
	{
		array->slc.count_litter = 0;
		array->slc.b = current;
	}
	else if (tmp >= current)
		return (fn_unselect(array, list, current, end));
	if (end != current + 1 && ((char *)current)[1] == '\n')
		ft_42sh_key_right(array, list);
	else
	{
		array->slc.count_litter++;
		fn_right(array, list, current, 1);
	}
	array->slc.e = (void *)list->lp_current;
}
