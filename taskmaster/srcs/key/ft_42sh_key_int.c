/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_limit(register t_main_42sh *array,
register t_in_42sh *list, register t_write_buff *out)
{
	register size_t				tempos;
	register size_t				count;
	register size_t				count_litter;

	if ((tempos = array->lp_auto->b_limit) == 0)
		return ;
	array->lp_auto->b_limit = 0;
	count_litter = list->count_litter - list->count_litter_current;
	count = list->lp_b + list->count - list->lp_current;
	list->count_litter_current += count_litter;
	list->lp_current += count;
	list->slesh_current = list->slesh_max;
	ft_42sh_dsp_data(array, tempos);
	ft_write_buffer_str_zero(out, "\xD\x1b[J\x1b[1A");
	ft_42sh_dsp_default_line(array, list);
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
	ft_write_buffer(out);
}

static void		fn_finish(register t_main_42sh *array,
register t_in_42sh *list, register t_write_buff *out)
{
	register void			*tmp;

	ft_42sh_str_full_end(array, list);
	ft_42sh_list_in_last(array);
	if (array->dq.dquote != 0)
	{
		ft_42sh_dq_unalias(array, array->dq.in_dquote);
		ft_42sh_dq_paste(array);
		ft_42sh_msg_change(array, 0, array->dq.dquote);
		if ((tmp = array->dq.hrdoc_cmp_lp) != 0)
		{
			ft_free(tmp);
			array->dq.hrdoc_cmp_lp = 0;
		}
		array->dq.in_dquote = 0;
	}
	array->slc.b = 0;
	array->lp_auto->b_view = 0;
	array->lp_auto->b_auto = 0;
	ft_write_buffer_str_zero(out, "\n\x1b[J");
	ft_42sh_dsp_start(array);
	ft_write_buffer(out);
}

void			ft_42sh_key_int(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_write_buff		*out;

	out = &array->out;
	fn_limit(array, list, out);
	fn_finish(array, list, out);
	ft_42sh_auto_toogle(array);
}
