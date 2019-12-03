/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_sub_litter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void			fn_offset(register t_main_42sh *array,
register t_in_42sh *list, register char *offset, register char *current)
{
	register t_write_buff		*out;
	register char				*end;
	register size_t				count;
	register size_t				count_litter;

	end = list->lp_b + list->count;
	list->count = list->count - (current - offset);
	while (current < end)
		offset++[0] = current++[0];
	out = &array->out;
	array->tab.b_view = 0;
	count = list->count - (list->lp_current - list->lp_b);
	count_litter = list->count_litter - list->count_litter_current;
	ft_write_buffer_str_zero(out, "\x1b[J");
	ft_write_buffer_str(out, list->lp_current, count);
	list->count_litter_current += count_litter;
	list->lp_current += count;
	list->slesh_current = list->slesh_max;
	ft_write_buffer_str_zero(out, " \x1b[1D");
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
}

static void			fn_slesh(register t_in_42sh *list,
register t_slesh_42sh **spl, register size_t slesh_current)
{
	register t_slesh_42sh		*spl_slesh;

	if (list->slesh_max-- == 1)
	{
		list->spl_slesh = 0;
		return (ft_strsplit_free((char **)spl));
	}
	spl = &spl[slesh_current];
	spl_slesh = spl[1];
	spl[0]->count_litter += spl_slesh->count_litter;
	spl[0]->count += spl_slesh->count;
	free(spl_slesh);
	spl += 2;
	while ((spl_slesh = spl[0]) != 0)
	{
		spl[-1] = spl_slesh;
		spl++;
	}
	spl[-1] = 0;
}

static void			fn_slesh_correct(register t_in_42sh *list,
register size_t n)
{
	register t_slesh_42sh		**spl;

	if ((spl = list->spl_slesh) != 0)
	{
		spl = &spl[list->slesh_current];
		spl[0]->count -= n;
		spl[0]->count_litter--;
	}
	list->count_litter--;
}

void				ft_42sh_key_backspace(register t_main_42sh *array,
register t_in_42sh *list)
{
	register char		*current;
	register char		*offset;
	register char		litter;

	if (list->lp_b == (current = list->lp_current))
		return ;
	ft_42sh_list_in_dup(list);
	offset = current;
	while (((litter = offset--[-1]) & 0x80) != 0 && (litter & 0x40) == 0)
		;
	if (litter == '\n')
	{
		ft_42sh_dsp_caret_left(array, list, 0, current - --offset);
		fn_slesh(list, list->spl_slesh, list->slesh_current);
	}
	else
	{
		list->lp_current = offset;
		ft_write_buffer_str_zero(&array->out, "\b");
		fn_slesh_correct(list, current - offset);
		list->count_litter_current--;
	}
	fn_offset(array, list, offset, current);
}

void				ft_42sh_key_delete(register t_main_42sh *array,
register t_in_42sh *list)
{
	register char		*current;
	register char		*tmp;
	register char		*offset;
	register char		litter;

	tmp = list->lp_b + list->count;
	if (tmp == (current = list->lp_current))
		return ;
	ft_42sh_list_in_dup(list);
	offset = current;
	if (((litter = offset++[0]) & 0x80) != 0)
		while (((litter = offset[0]) & 0x80) != 0 && (litter & 0x40) == 0)
			offset++;
	if (tmp != offset && offset[0] == '\n')
	{
		offset++;
		fn_slesh(list, list->spl_slesh, list->slesh_current);
	}
	else
		fn_slesh_correct(list, offset - current);
	fn_offset(array, list, current, offset);
}
