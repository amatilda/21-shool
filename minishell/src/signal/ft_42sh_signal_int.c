/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_signal_int.c                               :+:      :+:    :+:   */
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

	if ((tempos = array->tab.b_limit) == 0)
		return ;
	array->tab.b_limit = 0;
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
register t_write_buff *out)
{
	ft_42sh_key_end(array, array->in.in_current);
	ft_42sh_list_in_deffault(array);
	if (array->dquote != 0)
	{
		ft_42sh_msg_change(array, 0, array->dquote);
		ft_42sh_list_in_free(array->in_dquote);
		array->in_dquote = 0;
		array->dquote = 0;
	}
	array->tab.b_view = 0;
	array->tab.b_auto = 0;
	ft_write_buffer_str_zero(out, "\n\x1b[J");
	ft_42sh_dsp_start(array);
	ft_write_buffer(out);
}

void			ft_42sh_signal_int(int signo)
{
	register t_main_42sh		*array;
	register t_write_buff		*out;
	register t_in_42sh			*list;

	if ((array = g_lp_array)->pr.pid != 0)
		exit(E_CODE_42SH);
	if (array->pr.b_main_suspend != 0)
		return ;
	out = &array->out;
	list = array->in.in_current;
	fn_limit(array, list, out);
	fn_finish(array, out);
	(void)signo;
}
