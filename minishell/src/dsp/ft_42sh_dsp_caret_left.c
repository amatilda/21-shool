/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dsp_caret_left.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_write_line(register t_main_42sh *array,
register size_t n, register size_t count, register t_in_42sh *list)
{
	char						buff[sizeof(uintmax_t) * 3];
	register char				*tmp;
	register t_write_buff		*out;

	if (list != 0 && list->lp_b + list->count > (tmp = list->lp_current + 1)
	&& tmp[0] == '\n')
	{
		tmp = (char *)--list->slesh_current;
		n = list->spl_slesh[(size_t)tmp]->count_litter;
		n += (tmp == 0) ? array->msg.pre_msg_litter : 0;
		n = n % array->ws.ws_col;
		count++;
	}
	ft_write_buffer_str_zero((out = &array->out), "\xD");
	if (count != 0)
	{
		ft_write_buffer_str_zero(out, "\x1b[");
		ft_write_buffer_str(out, buff, ft_itoa(buff, count, 10, ITOA_LOWER));
		ft_write_buffer_str_zero(out, "A");
	}
	if (n == 0)
		return ;
	ft_write_buffer_str_zero(out, "\x1b[");
	ft_write_buffer_str(out, buff, ft_itoa(buff, n, 10, ITOA_LOWER));
	ft_write_buffer_str_zero(out, "C");
}

static size_t	fn_slesh_pre(register t_main_42sh *array,
register t_in_42sh *list, register t_slesh_42sh **spl_tmp,
register t_slesh_42sh **spl_slesh)
{
	register size_t				tempos;

	tempos = array->msg.pre_msg_litter;
	while (spl_tmp <= spl_slesh)
		tempos += spl_tmp++[0]->count_litter;
	return (list->count_litter_current - tempos);
}

static size_t	fn_slesh_finish(register size_t count_litter,
register size_t count, register size_t ws_col,
register size_t tempos)
{
	if (count_litter > (tempos = tempos % ws_col))
	{
		count++;
		count_litter -= tempos;
	}
	count += count_litter / ws_col;
	return (count);
}

static void		fn_slesh(register t_main_42sh *array,
register t_in_42sh *list, register size_t count_litter,
register t_slesh_42sh **spl_slesh)
{
	register size_t				count;
	register size_t				tempos;
	register size_t				ws_col;
	register size_t				i;

	i = (size_t)spl_slesh;
	spl_slesh = &spl_slesh[list->slesh_current];
	tempos = fn_slesh_pre(array, list, (t_slesh_42sh **)i, spl_slesh);
	ws_col = array->ws.ws_col;
	tempos += spl_slesh--[0]->count_litter;
	list->count_litter_current -= count_litter;
	count = (tempos == 0 && count_litter != 0) ? 1 : 0;
	i = 0;
	while (count_litter > tempos)
	{
		count_litter -= tempos;
		count += tempos / ws_col + (tempos % ws_col != 0 ? 1 : 0);
		tempos = spl_slesh--[0]->count_litter;
		i++;
	}
	if ((list->slesh_current -= i) == 0)
		tempos += array->msg.pre_msg_litter;
	count = fn_slesh_finish(count_litter, count, ws_col, tempos);
	fn_write_line(array, (tempos - count_litter) % ws_col, count, list);
}

void			ft_42sh_dsp_caret_left(register t_main_42sh *array,
register t_in_42sh *list, register size_t count_litter, register size_t count)
{
	register t_slesh_42sh		**spl_slesh;
	register size_t				tempos;
	register size_t				ws_col;

	if (count == 0)
		return ;
	list->lp_current -= count;
	if ((spl_slesh = list->spl_slesh) != 0)
		return (fn_slesh(array, list, count_litter, spl_slesh));
	ws_col = array->ws.ws_col;
	if (count_litter > (tempos = list->count_litter_current % ws_col))
	{
		tempos = count_litter - tempos;
		count = tempos / ws_col;
		count += tempos % ws_col != 0 ? 1 : 0;
	}
	else
		count = 0;
	fn_write_line(array, (list->count_litter_current -= count_litter) % ws_col,
	count, 0);
}
