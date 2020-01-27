/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_str_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void			fn_offset(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_write_buff		*out;
	register size_t				count;
	register size_t				count_litter;

	out = &array->out;
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

static size_t		fn_slesh_pre(register t_main_42sh *array,
register t_in_42sh *list, register t_slesh_42sh **spl_slesh, size_t *offset)
{
	register t_slesh_42sh		**spl_tmp;
	register size_t				count;
	register size_t				count_litter;

	spl_tmp = list->spl_slesh;
	count = 0;
	count_litter = array->msg.pre_msg_litter;
	while (spl_tmp < spl_slesh)
	{
		count_litter += spl_tmp[0]->count_litter;
		count += spl_tmp++[0]->count + 2;
	}
	count_litter += spl_slesh[0]->count_litter;
	count += spl_slesh[0]->count;
	*offset = count_litter - list->count_litter_current;
	return (count - (list->lp_current - list->lp_b));
}

static void			fn_slesh(register t_in_42sh *list,
register t_slesh_42sh **spl_min, register t_slesh_42sh **spl_max)
{
	register t_slesh_42sh		**spl_tmp;
	register t_slesh_42sh		*spl_slesh;

	if (list->slesh_max == 0)
	{
		ft_strsplit_free((char **)list->spl_slesh);
		list->spl_slesh = 0;
		return ;
	}
	spl_tmp = spl_min;
	while (spl_tmp < spl_max)
		ft_free(spl_tmp++[0]);
	while ((spl_slesh = spl_max++[0]) != 0)
		spl_min++[0] = spl_slesh;
	spl_min[0] = 0;
}

static void			fn_slesh_correct(register t_main_42sh *array,
register t_in_42sh *list, register size_t count, register size_t count_litter)
{
	register t_slesh_42sh		**spl;
	register t_slesh_42sh		**spl_min;
	size_t						offset;
	register size_t				n;

	spl = &list->spl_slesh[list->slesh_current];
	if ((n = fn_slesh_pre(array, list, spl, &offset)) < count)
	{
		spl_min = spl;
		spl[0]->count -= n;
		count_litter -= offset;
		spl++[0]->count_litter -= offset;
		list->slesh_max--;
		while ((n += spl[0]->count + 2) < count)
		{
			count_litter -= spl++[0]->count_litter;
			list->slesh_max--;
		}
		spl_min[0]->count += (n - count);
		spl_min[0]->count_litter += (spl[0]->count_litter - count_litter);
		return (fn_slesh(list, spl_min + 1, spl + 1));
	}
	spl[0]->count -= count;
	spl[0]->count_litter -= count_litter;
}

void				ft_42sh_str_delete(register t_main_42sh *array,
register t_in_42sh *list, register char *e, register size_t count_litter)
{
	register char				*end;
	register size_t				count;
	register char				*current;
	register char				*b;

	ft_42sh_list_in_dup(list);
	if ((current = list->lp_current) > e)
	{
		b = e;
		e = current;
		ft_42sh_dsp_caret_left(array, list, count_litter, e - b);
	}
	else
		b = current;
	count = e - b;
	if (list->spl_slesh != 0)
		fn_slesh_correct(array, list, count, count_litter);
	list->count_litter -= count_litter;
	end = list->lp_b + list->count;
	list->count -= count;
	while (e < end)
		b++[0] = e++[0];
	fn_offset(array, list);
}
