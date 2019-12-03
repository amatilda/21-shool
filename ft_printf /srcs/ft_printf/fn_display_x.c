/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:36:05 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static int	fn_finish(register t_my *my, register char *buffer,
		register size_t count)
{
	if (my->opt.letter && my->opt.min && my->opt.b_null && my->opt.b_max == 0)
	{
		fn_str_copy(my, &my->opt.letter, 1);
		my->opt.letter = 0;
	}
	if (my->opt.b_left == 0 && my->opt.b_max && my->opt.min)
		fn_sp(my, ' ');
	if (my->opt.b_left == 0 && my->opt.min &&
			(my->format == 'x' || my->format == 'X') && my->opt.b_null == 0)
		fn_sp(my, my->sp);
	if (my->opt.b_prefix && my->opt.base == 16 &&
			my->format != 'p' && my->format != 'P')
	{
		fn_str_copy(my, (my->format < 'a') ? "0X" : "0x", 2);
		my->opt.b_prefix = 0;
	}
	if (my->opt.b_left == 0 && my->opt.min)
		fn_sp(my, my->sp);
	if (my->opt.b_prefix && my->opt.base == 16)
		fn_str_copy(my, (my->format < 'a') ? "0X" : "0x", 2);
	if (my->opt.letter)
		fn_str_copy(my, &my->opt.letter, 1);
	return (fn_stub_finish_00(my, buffer, count));
}

static void	fn_stub1(register t_my *my, register char **buffer,
		register size_t *count)
{
	if (my->opt.minus && my->opt.b_space && my->opt.letter == 0)
		my->opt.letter = ' ';
	my->tmp = my->opt.letter ? 1 : 0;
	if (my->opt.b_prefix)
	{
		if (my->opt.base == 16)
			my->tmp += 2;
		else if (my->opt.base == 8 && my->arg_itoa)
		{
			*buffer = *buffer - 1;
			*count = *count + 1;
			if (*count == 4 && my->opt.b_grup)
			{
				*buffer[0] = ' ';
				*buffer = *buffer - 1;
				*count = *count + 1;
			}
			*buffer[0] = 0x30;
			my->opt.max -= my->opt.max > 0 ? 1 : 0;
		}
	}
}

static void	fn_stub0_0(register t_my *my)
{
	if (my->opt.minus)
		return (fn_stub_signed(my));
	if (my->opt.b_sub[3] || my->opt.b_sub[4])
		return ;
	else if (my->opt.b_sub[sizeof(STR_SUB)])
		my->arg_itoa = (unsigned long long)my->arg_itoa;
	else if (my->opt.b_sub[1])
		my->arg_itoa = (unsigned long)my->arg_itoa;
	else if (my->opt.b_sub[0])
		my->arg_itoa = (unsigned short)my->arg_itoa;
	else if (my->opt.b_sub[sizeof(STR_SUB) + 1])
		my->arg_itoa = (unsigned char)my->arg_itoa;
	else
		my->arg_itoa = (unsigned int)my->arg_itoa;
}

static int	fn_stub0(register t_my *my, register char *buffer)
{
	register uint_fast8_t	op;

	my->opt.base = (my->opt.base == 0) ? 16 : my->opt.base;
	op = (my->format < 'a') ? ITOA_UPPER : ITOA_LOWER;
	op = (my->opt.base != 16 && my->opt.b_grup) ? op | ITOA_GROUPED : op;
	op = (my->opt.minus && my->opt.b_plus) ? op | ITOA_PLUS : op;
	op = op | my->opt.minus;
	if (my->opt.b_sub[2])
		my->arg_itoa = va_arg(my->ap_line, uintmax_t);
	else
	{
		my->arg_itoa = va_arg(my->ap_line, size_t);
		fn_stub0_0(my);
	}
	if (my->arg_itoa == 0 && my->format != 'p' &&
			my->format != 'P' && my->opt.base != 8)
		my->opt.b_prefix = 0;
	return (ft_itoa(buffer, my->arg_itoa, my->opt.base, op));
}

int			fn_display_x(register t_my *my)
{
	char			str[sizeof(uintmax_t) * 10 + 2 + 2];
	char			*buffer;
	size_t			count;

	buffer = str + 2;
	count = fn_stub0(my, buffer);
	if (buffer[0] < 0x30)
	{
		my->opt.letter = buffer[0];
		buffer++;
		count--;
	}
	if (my->opt.b_max)
	{
		count = fn_stub_count(my, count);
		if (my->opt.max >= INT_MAX)
			return (0);
		my->opt.max = my->opt.max > count ? my->opt.max - count : 0;
	}
	fn_stub1(my, &buffer, &count);
	my->tmp += count + my->opt.max;
	if (fn_stub_finish(my) == 0)
		return (0);
	return (fn_finish(my, buffer, count));
}
