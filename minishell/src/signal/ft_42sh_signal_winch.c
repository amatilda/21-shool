/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_signal_winch.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void			fn_auto_view(register t_main_42sh *array,
register t_in_42sh *list, register t_write_buff *out)
{
	register size_t				tempos;
	register size_t				count;
	register size_t				count_litter;

	count_litter = list->count_litter - list->count_litter_current;
	count = list->lp_b + list->count - list->lp_current;
	list->count_litter_current += count_litter;
	list->lp_current += count;
	list->slesh_current = list->slesh_max;
	ft_42sh_dsp_data(array, list->count_litter_current);
	ft_42sh_dsp_data(array, array->pwd.path_litter);
	ft_write_buffer_str_zero(out, "\xD\x1b[2A\n\x1b[J");
	ft_42sh_dsp_start(array);
	ft_write_buffer_str(out, list->lp_b, list->count);
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
	if ((tempos = array->tab.b_view) == AUTO_CMD_42SH)
		ft_42sh_key_tab(array, list);
}

void				ft_42sh_signal_winch(int signo)
{
	register t_main_42sh	*array;
	register t_in_42sh		*list;
	register t_write_buff	*out;

	array = g_lp_array;
	array->b_signo = 1;
	out = &array->out;
	list = array->in.in_current;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &array->ws);
	if (array->tab.b_view != 0)
		fn_auto_view(array, list, out);
	ft_write_buffer(out);
	array->b_signo = 0;
	(void)signo;
}
