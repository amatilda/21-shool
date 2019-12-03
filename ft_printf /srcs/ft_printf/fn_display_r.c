/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_display_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:34:56 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static void	fn_stub01(register t_my *my)
{
	my->stc->str_not[24] = "CAN";
	my->stc->str_not[25] = "EM";
	my->stc->str_not[26] = "SUB";
	my->stc->str_not[27] = "ESC";
	my->stc->str_not[28] = "FS";
	my->stc->str_not[29] = "GS";
	my->stc->str_not[30] = "RS";
	my->stc->str_not[31] = "US";
	my->stc->str_not[32] = "DEL";
}

static void	fn_stub00(register t_my *my)
{
	my->stc->str_not[0] = "NULL";
	my->stc->str_not[1] = "SON";
	my->stc->str_not[2] = "STX";
	my->stc->str_not[3] = "ETX";
	my->stc->str_not[4] = "EOT";
	my->stc->str_not[5] = "ACK";
	my->stc->str_not[6] = "ACK";
	my->stc->str_not[7] = "BEL";
	my->stc->str_not[8] = "BS";
	my->stc->str_not[9] = "HT";
	my->stc->str_not[10] = "LF";
	my->stc->str_not[11] = "VT";
	my->stc->str_not[12] = "FF";
	my->stc->str_not[13] = "CR";
	my->stc->str_not[14] = "SO";
	my->stc->str_not[15] = "SI";
	my->stc->str_not[16] = "DLE";
	my->stc->str_not[17] = "DC1";
	my->stc->str_not[18] = "DC2";
	my->stc->str_not[19] = "DC3";
	my->stc->str_not[20] = "DC4";
	my->stc->str_not[21] = "NAK";
	my->stc->str_not[22] = "SYN";
	my->stc->str_not[23] = "ETB";
	fn_stub01(my);
}

int			fn_display_r(register t_my *my)
{
	my->arg = (unsigned char)va_arg(my->ap_line, size_t);
	if (my->arg == 0x7f || my->arg > 0x1F)
	{
		my->format = my->arg;
		return (fn_display_unknown(my));
	}
	my->arg = (my->arg == 0x7F) ? 0x20 : my->arg;
	if (my->stc->str_not[0x20] == 0)
		fn_stub00(my);
	my->tmp = ft_strlen(my->stc->str_not[my->arg]);
	if (my->tmp >= INT_MAX)
		return (0);
	else if (my->out + my->count >= INT_MAX - my->tmp)
		return (0);
	if (my->opt.b_max == 0 || my->opt.max > my->tmp)
		my->opt.max = my->tmp;
	my->opt.min = my->opt.min > my->opt.max
		? my->opt.min - my->opt.max : 0;
	if (my->opt.b_left != 0)
		fn_str_copy(my, my->stc->str_not[my->arg], my->opt.max);
	if (my->opt.min != 0)
		fn_sp(my, my->sp);
	if (my->opt.b_left == 0)
		fn_str_copy(my, my->stc->str_not[my->arg], my->opt.max);
	return (1);
}
