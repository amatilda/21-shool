/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_dsp_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static size_t		fn_set(size_t max_cmd, register size_t x, size_t *y)
{
	if (x == 0)
		x++;
	if (x > max_cmd)
	{
		*y = 1;
		x = max_cmd;
	}
	else
		*y = max_cmd / x + 1;
	return (x);
}

size_t				ft_42sh_auto_dsp_cmd_raw(register t_main_42sh *array,
register size_t max_litter, register size_t max_cmd)
{
	register size_t				x;
	size_t						y;

	max_litter += 2;
	x = fn_set(max_cmd, array->ws.ws_col / max_litter, &y);
	if (x == 1 && max_litter > array->ws.ws_col)
		return (max_cmd + max_cmd * (max_litter / array->ws.ws_col) + 1);
	return (y);
}

static void			fn_x(t_main_42sh *array, t_all_cmd_42sh **spl,
size_t max_litter, size_t tempos)
{
	register t_all_cmd_42sh		*list;

	list = spl[tempos];
	ft_write_buffer_str(&array->out, list->std.lp_key, list->std.key_count);
	if (array->lp_auto == &array->auto_file)
	{
		ft_write_buffer_char(&array->out, list->add_litter, 1);
		max_litter--;
	}
	ft_write_buffer_char(&array->out, ' ', max_litter - list->std.key_litter);
}

size_t				ft_42sh_auto_dsp_cmd(t_main_42sh *array, size_t max_litter,
t_all_cmd_42sh **spl, size_t max_cmd)
{
	register size_t				tempos;
	register size_t				x;
	size_t						y;
	register size_t				i_y;
	register size_t				i_x;

	max_litter += 2;
	x = fn_set(max_cmd, array->ws.ws_col / max_litter, &y);
	ft_write_buffer_str_zero(&array->out, "\x1b[J");
	i_y = 0;
	while (i_y < y)
	{
		ft_write_buffer_str_zero(&array->out, "\n");
		i_x = 0;
		while (i_x < x && max_cmd > (tempos = i_y + i_x++ * y))
			fn_x(array, spl, max_litter, tempos);
		i_y++;
	}
	if (x == 1 && max_litter > array->ws.ws_col)
		return (max_cmd + max_cmd * (max_litter / array->ws.ws_col) + 1);
	return (y);
}
