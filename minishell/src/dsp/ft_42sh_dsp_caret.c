/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dsp_caret.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_42sh_dsp_default_line(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_write_buff		*out;
	register size_t				tempos;
	register t_slesh_42sh		**spl_slesh;
	char						buff[sizeof(uintmax_t) * 3];

	out = &array->out;
	if ((spl_slesh = list->spl_slesh) != 0)
		tempos = spl_slesh[list->slesh_current]->count_litter %
		array->ws.ws_col;
	else
		tempos = list->count_litter_current % array->ws.ws_col;
	ft_write_buffer_str_zero(out, "\xD");
	if (tempos == 0)
		return ;
	ft_write_buffer_str_zero(out, "\x1b[");
	ft_write_buffer_str(out, buff, ft_itoa(buff, tempos, 10, ITOA_LOWER));
	ft_write_buffer_str_zero(out, "C");
}

void			ft_42sh_dsp_raw(register t_main_42sh *array,
register size_t raw)
{
	register t_write_buff		*out;
	char						buff[sizeof(uintmax_t) * 3];

	if (raw == 0)
		return ;
	out = &array->out;
	ft_write_buffer_str_zero(out, "\x1b[");
	ft_write_buffer_str(out, buff, ft_itoa(buff, raw, 10, ITOA_LOWER));
	ft_write_buffer_str_zero(out, "A");
}

void			ft_42sh_dsp_data(register t_main_42sh *array,
register size_t count_litter)
{
	register t_write_buff		*out;
	register size_t				tempos;
	register size_t				ws_col;
	char						buff[sizeof(uintmax_t) * 3];

	if (count_litter == 0)
		return ;
	out = &array->out;
	ws_col = array->ws.ws_col;
	tempos = count_litter / ws_col;
	if (count_litter <= ws_col)
		tempos = 0;
	else if (tempos * ws_col == count_litter)
		tempos--;
	if (tempos != 0)
	{
		ft_write_buffer_str_zero(out, "\x1b[");
		ft_write_buffer_str(out, buff, ft_itoa(buff, tempos, 10, ITOA_LOWER));
		ft_write_buffer_str_zero(out, "A");
	}
}
