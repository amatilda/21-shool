/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_litter.c                               :+:      :+:    :+:   */
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
	ft_write_buffer_str(out, current, count + count_add);
	list->count_litter_current += count_litter;
	list->lp_current += count;
	list->slesh_current = list->slesh_max;
	ft_write_buffer_str_zero(out, " \x1b[1D");
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
}

static void			fn_offset_litter(register t_main_42sh *array,
register t_in_42sh *list, register char *current, register size_t count)
{
	register char		*tmp;
	register char		*end;

	if (list->count_litter == list->count_litter_current)
		return ;
	tmp = list->lp_b + list->count - 1;
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
	register t_slesh_42sh		**spl_slesh;
	register size_t				tempos;

	if ((list->count + count) > list->max)
	{
		if ((new = malloc((list->max += BUFFER_READ_42SH))) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		old = list->lp_b;
		ft_memcpy(new, old, list->count);
		list->lp_b = new;
		list->lp_current = new + (list->lp_current - old);
		free(old);
	}
	if ((spl_slesh = list->spl_slesh) == 0)
		return ;
	tempos = list->slesh_current;
	spl_slesh[tempos]->count_litter++;
	spl_slesh[tempos]->count += count;
}

void				ft_42sh_key_litter(register t_main_42sh *array,
register t_in_42sh *list, uint_fast32_t litter, register size_t count)
{
	register char		*current;
	register size_t		tempos;

	ft_42sh_list_in_dup(list);
	fn_overlow(list, count);
	current = list->lp_current;
	fn_offset_litter(array, list, current, count);
	list->lp_current += count;
	list->count += count;
	list->count_litter++;
	list->count_litter_current++;
	tempos = count;
	while (tempos-- != 0)
		current[tempos] = ((char *)&litter)[tempos];
	fn_offset_caret(array, list, current, count);
}
