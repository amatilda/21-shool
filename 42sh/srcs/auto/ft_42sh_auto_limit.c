/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_limit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void					fn_dsp_limit(register t_main_42sh *array,
register t_in_42sh *list, register size_t cmd_count)
{
	register t_write_buff		*out;
	register size_t				count;
	register size_t				count_litter;
	register size_t				tempos;
	char						buff[sizeof(uintmax_t) * 3];

	out = &array->out;
	count_litter = list->count_litter - list->count_litter_current;
	count = list->lp_b + list->count - list->lp_current;
	tempos = list->slesh_current;
	ft_42sh_dsp_caret_right(array, list, count_litter, count);
	ft_write_buffer_str_zero(out, MSG_TAB_LIMIT_42SH);
	ft_write_buffer_str(out, buff,
	(cmd_count = ft_itoa(buff, cmd_count, 10, ITOA_LOWER)));
	ft_write_buffer_str_zero(out, MSG_TAB_LIM_A_42SH);
	ft_write_buffer_str_zero(out, "\x7");
	array->lp_auto->b_limit = cmd_count + MSG_TAB_LIM_L_42SH;
	list->count_litter_current -= count_litter;
	list->lp_current -= count;
	list->slesh_current = tempos;
}

static void					fn_new_star(register t_main_42sh *array,
register size_t max_litter, register t_all_cmd_42sh **spl,
register size_t max_cmd)
{
	register t_write_buff		*out;
	register t_in_42sh			*list;
	register size_t				count;
	register size_t				count_litter;

	list = array->in.in_current;
	out = &array->out;
	ft_42sh_auto_dsp_cmd(array, max_litter, spl, max_cmd);
	ft_write_buffer_str_zero(out, "\n");
	ft_42sh_dsp_start(array);
	ft_write_buffer_str(out, list->lp_b, list->count);
	count_litter = list->count_litter - list->count_litter_current;
	count = list->lp_b + list->count - list->lp_current;
	list->count_litter_current += count_litter;
	list->lp_current += count;
	list->slesh_current = list->slesh_max;
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
	array->lp_auto->b_view = 0;
}

static void					fn_finish(register t_main_42sh *array,
register size_t max_litter, register t_all_cmd_42sh **spl,
register size_t max_cmd)
{
	register size_t				tempos;
	register t_in_42sh			*list;
	register size_t				count;
	register size_t				count_litter;

	list = array->in.in_current;
	count = list->lp_b + list->count - list->lp_current;
	count_litter = list->count_litter - list->count_litter_current;
	ft_42sh_dsp_caret_right(array, list, count_litter, count);
	tempos = ft_42sh_auto_dsp_cmd(array, max_litter, spl, max_cmd);
	ft_42sh_dsp_raw(array, tempos);
	ft_42sh_dsp_default_line(array, list);
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
	array->lp_auto->b_view = 1;
	array->lp_auto->view_raw = tempos;
}

static void					fn_clean(register t_main_42sh *array,
register t_in_42sh *list, register size_t tempos)
{
	register size_t				count;
	register size_t				count_litter;

	array->lp_auto->b_limit = 0;
	count_litter = list->count_litter - list->count_litter_current;
	count = list->lp_b + list->count - list->lp_current;
	list->count_litter_current += count_litter;
	list->lp_current += count;
	list->slesh_current = list->slesh_max;
	ft_42sh_dsp_data(array, tempos);
	ft_write_buffer_str_zero(&array->out, "\xD\x1b[J\x1b[1A");
	ft_42sh_dsp_default_line(array, list);
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
}

void						ft_42sh_auto_limit(register t_main_42sh *array,
register size_t max_litter, register t_all_cmd_42sh **spl,
register size_t max_cmd)
{
	register size_t				tempos;
	register t_in_42sh			*list;

	list = array->in.in_current;
	if ((tempos = array->lp_auto->b_limit) != 0)
	{
		fn_clean(array, list, tempos);
		if (array->litter[0] != 'y')
			return ;
	}
	else if (array->lp_auto->b_view == 0 && max_cmd > TAB_LIMIT_42SH)
		return (fn_dsp_limit(array, list, max_cmd));
	tempos = ft_42sh_auto_dsp_cmd_raw(array, max_litter, max_cmd);
	if (array->b_signo != 0 && tempos == array->lp_auto->view_raw)
		return ;
	if (array->lp_auto->b_auto != 0 && array->b_signo == 0)
		return (ft_42sh_auto_dsp_next_cmd_pre(array, list));
	array->lp_auto->b_auto = 1;
	array->lp_auto->auto_spl = spl;
	array->lp_auto->auto_cmd = max_cmd;
	if ((tempos + 4) >= array->ws.ws_row)
		return (fn_new_star(array, max_litter, spl, max_cmd));
	fn_finish(array, max_litter, spl, max_cmd);
}
