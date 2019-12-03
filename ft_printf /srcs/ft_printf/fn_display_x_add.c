/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_display_x_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:36:15 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

size_t	fn_stub_count(register t_my *my, register size_t count)
{
	if (my->opt.max == 0 && my->arg_itoa == 0)
	{
		if (my->opt.base == 10)
			count = 0;
		else if (my->opt.base != 8)
		{
			my->opt.letter = 0;
			count = 0;
		}
		else if (my->opt.b_prefix == 0 && my->opt.base == 8)
		{
			my->opt.letter = 0;
			count = 0;
		}
	}
	return (count);
}

void	fn_stub_signed(register t_my *my)
{
	if (my->opt.b_sub[3] || my->opt.b_sub[4])
		my->arg_itoa = (ssize_t)my->arg_itoa;
	else if (my->opt.b_sub[sizeof(STR_SUB)])
		my->arg_itoa = (long long)my->arg_itoa;
	else if (my->opt.b_sub[1])
		my->arg_itoa = (long)my->arg_itoa;
	else if (my->opt.b_sub[0])
		my->arg_itoa = (short)my->arg_itoa;
	else if (my->opt.b_sub[sizeof(STR_SUB) + 1])
		my->arg_itoa = (signed char)my->arg_itoa;
	else
		my->arg_itoa = (signed int)my->arg_itoa;
}

int		fn_stub_finish(register t_my *my)
{
	my->opt.min = my->opt.min > my->tmp ? my->opt.min - my->tmp : 0;
	my->tmp += my->opt.min;
	if (my->tmp >= INT_MAX)
		return (0);
	else if (my->out + my->count >= INT_MAX - my->tmp)
		return (0);
	return (1);
}

int		fn_stub_finish_00(register t_my *my, register char *buffer,
		register size_t count)
{
	if (my->opt.max)
	{
		my->tmp = my->opt.min;
		my->opt.min = my->opt.max;
		fn_sp(my, (my->opt.b_max_over) ? 0x20 : 0x30);
		my->opt.min = my->tmp;
	}
	fn_str_copy(my, buffer, count);
	if (my->opt.min)
		fn_sp(my, ' ');
	return (1);
}
