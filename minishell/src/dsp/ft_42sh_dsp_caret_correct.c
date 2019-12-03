/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dsp_caret_correct.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_42sh_dsp_caret_left_correct(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_slesh_42sh		**spl_slesh;
	register t_write_buff		*out;
	register size_t				count_litter;
	register size_t				tempos;
	char						buff[sizeof(uintmax_t) * 3];

	if ((spl_slesh = list->spl_slesh) == 0 ||
	list->count_litter == list->count_litter_current ||
	list->lp_current[0] != '\n')
		return ;
	if ((tempos = list->slesh_current) == 0)
		return ;
	list->slesh_current--;
	count_litter = spl_slesh[--tempos]->count_litter;
	if (tempos == 0)
		count_litter += array->msg.pre_msg_litter;
	if ((count_litter = count_litter % array->ws.ws_col) == 0)
		return ;
	ft_write_buffer_str_zero((out = &array->out), "\x1b[1A");
	ft_write_buffer_str_zero(out, "\x1b[");
	ft_write_buffer_str(out, buff, ft_itoa(buff, count_litter,
	10, ITOA_LOWER));
	ft_write_buffer_str_zero(out, "C");
}
