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

#include "../includes/ft_42sh_signal.h"

static void			fn_auto_view(register t_main_42sh *array,
register t_in_42sh *list, register t_write_buff *out)
{
	register size_t				count;
	register size_t				count_litter;

	count_litter = list->count_litter - list->count_litter_current;
	count = list->lp_b + list->count - list->lp_current;
	ft_42sh_str_full_home(array, list);
	ft_write_buffer_str_zero(out, "\xD\x1b[K\x1b[1A");
	ft_42sh_dsp_data(array, array->msg.pre_msg_litter);
	ft_write_buffer_str_zero(out, "\x1b[K");
	ft_42sh_dsp_data(array, array->pwd.sh_path_view.count_litter);
	ft_42sh_dsp_start(array);
	ft_write_buffer_str(out, list->lp_b, list->count);
	list->count_litter_current = list->count_litter;
	list->lp_current = list->lp_b + list->count;
	list->slesh_current = list->slesh_max;
	ft_42sh_dsp_caret_left(array, list, count_litter, count);
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
	if (ft_42sh_stub_ioctl(array, TIOCGWINSZ, &array->ws) == -1)
		ft_42sh_exit(E_IOTL_CODE_42SH, __FILE__, __func__, __LINE__);
	if (array->lp_auto->b_view != 0)
		fn_auto_view(array, list, out);
	ft_write_buffer(out);
	array->b_signo = 0;
	(void)signo;
}
