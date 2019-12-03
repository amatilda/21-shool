/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_display_k.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:34:06 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static int	stub0(register t_my *my, register t_ft_str_time_in_out *in_out)
{
	while (my->f[0] != '}' && my->f[0] != 0)
		my->f++;
	if (my->f[0] == 0)
		return (0);
	my->f++;
	if (fn_str_time(in_out) == 0)
		return (0);
	my->opt.min = my->opt.min > in_out->count_out ?
		my->opt.min - in_out->count_out : 0;
	if (my->out + my->count >= INT_MAX - in_out->count_out - my->opt.min)
		return (0);
	if (my->opt.b_left == 0 && my->opt.min != 0)
		fn_sp(my, ' ');
	return (1);
}

int			fn_display_k(register t_my *my)
{
	char					str[21];
	time_t					unix_time;
	t_ft_str_time_in_out	in_out;

	if (my->f[0] != '{')
		return (0);
	my->f++;
	unix_time = va_arg(my->ap_line, time_t);
	ft_gmtime_r(&unix_time, &in_out.timeptr);
	in_out.s = str;
	in_out.f = my->f;
	in_out.opt = STR_TIME_STANDART;
	in_out.max = sizeof(str);
	if (stub0(my, &in_out) == 0)
		return (0);
	if (in_out.count_out != 0)
		fn_str_copy(my, str, in_out.count_out);
	if (my->opt.min != 0)
		fn_sp(my, ' ');
	return (1);
}
