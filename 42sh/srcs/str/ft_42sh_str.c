/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void			fn_offset_caret(register t_main_42sh *array,
register t_in_42sh *list, register char *current, register size_t count_add)
{
	register t_write_buff		*out;
	register size_t				count;
	register size_t				count_litter;

	out = &array->out;
	count = list->count - (list->lp_current - list->lp_b);
	count_litter = list->count_litter - list->count_litter_current;
	ft_write_buffer_str_zero(out, "\x1b[J");
	ft_write_buffer(out);
	ft_write_buffer_str(out, current, count + count_add);
	ft_write_buffer(out);
	list->count_litter_current += count_litter;
	list->lp_current += count;
	list->slesh_current = list->slesh_max;
	ft_write_buffer_str_zero(out, " \x1b[1D");
	ft_write_buffer(out);
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
}

static void			fn_offset_litter(register t_main_42sh *array,
register t_in_42sh *list, register char *current, register size_t count)
{
	register char		*tmp;
	register char		*end;

	tmp = list->lp_b + list->count;
	if (current == tmp)
		return ;
	tmp--;
	end = tmp + count;
	while (tmp >= current)
	{
		end[0] = tmp[0];
		end--;
		tmp--;
	}
	ft_write_buffer_str_zero(&array->out, "\x1b[1@");
}

static void			fn_overlow(register t_in_42sh *list, register size_t count)
{
	register char				*new;
	register char				*old;
	register size_t				tempos;

	tempos = (list->count + count + (BUFFER_READ_42SH - 1)) & -BUFFER_READ_42SH;
	if (tempos != list->max)
	{
		list->max = tempos;
		if ((new = ft_malloc(tempos)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
		old = list->lp_b;
		ft_memcpy(new, old, list->count);
		list->lp_b = new;
		list->lp_current = new + (list->lp_current - old);
		ft_free(old);
	}
}

static void			fn_slesh(register t_in_42sh *list,
register size_t count, register size_t count_litter)
{
	register t_slesh_42sh		**spl_slesh;
	register size_t				tempos;

	if (count == 2 && count_litter == 0)
	{
		if ((spl_slesh = list->spl_slesh) != 0)
			ft_42sh_dq_split_add_empty(list, spl_slesh);
		else
		{
			list->slesh_current = 1;
			ft_42sh_dq_split(list, 1);
		}
		return ;
	}
	list->count_litter += count_litter;
	list->count_litter_current += count_litter;
	if ((spl_slesh = list->spl_slesh) == 0)
		return ;
	tempos = list->slesh_current;
	spl_slesh = &spl_slesh[tempos];
	spl_slesh[0]->count_litter += count_litter;
	spl_slesh[0]->count += count;
}

void				ft_42sh_str(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *litter,
t_add_litter_42sh *in)
{
	register size_t		count;
	register size_t		count_litter;
	register char		*current;

	if ((count = in->count) == 0)
		return ;
	count_litter = in->count_litter;
	ft_42sh_list_in_dup(list);
	fn_overlow(list, count);
	current = list->lp_current;
	fn_offset_litter(array, list, current, count);
	list->lp_current += count;
	list->count += count;
	ft_memcpy(current, litter, count);
	fn_slesh(list, count, count_litter);
	fn_offset_caret(array, list, current, count);
}
