/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dsp_caret_right.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_write_line(register t_write_buff *out,
register size_t count_litter, register size_t count,
register t_in_42sh *list)
{
	char						buff[sizeof(uintmax_t) * 3];

	if (list != 0 && list->lp_current[-1] == '\n')
	{
		list->slesh_current++;
		count_litter = 0;
		count++;
	}
	ft_write_buffer_str_zero(out, "\xD");
	if (count != 0)
	{
		ft_write_buffer_str_zero(out, "\x1b[");
		ft_write_buffer_str(out, buff, ft_itoa(buff, count, 10, ITOA_LOWER));
		ft_write_buffer_str_zero(out, "B");
	}
	if (count_litter != 0)
	{
		ft_write_buffer_str_zero(out, "\x1b[");
		ft_write_buffer_str(out, buff, ft_itoa(buff, count_litter,
		10, ITOA_LOWER));
		ft_write_buffer_str_zero(out, "C");
	}
}

static size_t	fn_slesh_pre(register t_main_42sh *array,
register t_in_42sh *list, register t_slesh_42sh **spl_tmp,
register t_slesh_42sh **spl_slesh)
{
	register size_t				tempos;

	tempos = array->msg.pre_msg_litter;
	while (spl_tmp <= spl_slesh)
		tempos += spl_tmp++[0]->count_litter;
	return ((spl_slesh[0]->count_litter -
	(tempos - list->count_litter_current)));
}

static void		fn_slesh(register t_main_42sh *array,
register t_in_42sh *list, register size_t count_litter,
register t_slesh_42sh **spl_slesh)
{
	register size_t				count;
	register size_t				tempos;
	register size_t				ws_col;

	count = (size_t)spl_slesh;
	spl_slesh = &spl_slesh[list->slesh_current];
	count = fn_slesh_pre(array, list, (t_slesh_42sh **)count, spl_slesh);
	tempos = spl_slesh++[0]->count_litter - count;
	if (list->slesh_current == 0)
		count += array->msg.pre_msg_litter;
	ws_col = array->ws.ws_col;
	count = count % ws_col;
	count_litter += count;
	tempos += count;
	count = 0;
	while (count_litter > tempos)
	{
		count_litter -= tempos;
		count += tempos / ws_col + 1;
		tempos = spl_slesh++[0]->count_litter;
		list->slesh_current++;
	}
	count += count_litter / ws_col;
	fn_write_line(&array->out, count_litter % ws_col, count, list);
}

void			ft_42sh_dsp_caret_right(register t_main_42sh *array,
register t_in_42sh *list, register size_t count_litter, register size_t count)
{
	register t_slesh_42sh		**spl_slesh;
	register size_t				tempos;
	register size_t				ws_col;

	if (count == 0)
		return ;
	list->lp_current += count;
	if ((spl_slesh = list->spl_slesh) != 0)
	{
		fn_slesh(array, list, count_litter, spl_slesh);
		list->count_litter_current += count_litter;
		return ;
	}
	ws_col = array->ws.ws_col;
	tempos = ws_col - (list->count_litter_current % ws_col);
	if (count_litter >= tempos)
		count = (count_litter - tempos) / ws_col + 1;
	else
		count = 0;
	fn_write_line(&array->out,
	(list->count_litter_current += count_litter) % ws_col, count, 0);
}
