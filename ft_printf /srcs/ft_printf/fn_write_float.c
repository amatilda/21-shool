/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_write_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/10 18:57:42 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../incs/libft.h"

static void		fn_pre_stub(register t_my *my, register int16_t e_save,
		register uint64_t mantissa)
{
	int	count;

	count = 0;
	my->flt.float_sing = mantissa >> (63 - e_save);
	mantissa = mantissa << (e_save + 1);
	while (mantissa && (mantissa & 0x8000000000000000) == 0)
	{
		mantissa = mantissa << 1;
		count++;
	}
	mantissa = mantissa >> (e_save + 1);
	while (mantissa && (mantissa & 1) == 0)
		mantissa = mantissa >> 1;
	my->flt.float_fract = mantissa;
	my->flt.float_fract_e += count;
}

static void		fn_pre(register t_my *my, register int16_t e_save,
		register uint64_t mantissa)
{
	int	count;

	count = 0;
	if (e_save < 0)
	{
		e_save = ~e_save + 1;
		my->flt.float_fract_e = e_save - 1;
		while (mantissa && (mantissa & 0x8000000000000000) == 0)
		{
			mantissa = mantissa << 1;
			count++;
		}
		while (mantissa && (mantissa & 1) == 0)
			mantissa = mantissa >> 1;
		my->flt.float_fract = mantissa;
		my->flt.float_fract_e += count;
	}
	else if (e_save >= 63)
	{
		my->flt.float_sing = mantissa;
		my->flt.float_sing_e = e_save - 63;
	}
	else
		fn_pre_stub(my, e_save, mantissa);
}

static t_lnbr	parse_sing(register t_my *my)
{
	char			buff[65];
	size_t			len;
	register t_lnbr	res;

	len = ft_itoa(buff, my->flt.float_sing, 2, 0);
	res = ft_numzero(my->flt.float_sing_e + len);
	buff[len] = '\0';
	ft_strcpy(res.num, buff);
	res = ft_parse_sing(res);
	return (res);
}

static t_lnbr	parse_fract(register t_my *my)
{
	char			buff[65];
	size_t			i;
	size_t			len;
	register t_lnbr	res;

	i = my->flt.float_fract_e - 1;
	len = ft_itoa(buff, my->flt.float_fract, 2, 0);
	res = ft_numzero(len + my->flt.float_fract_e);
	buff[len] = '\0';
	while (++i < len + my->flt.float_fract_e)
		res.num[i] = buff[i - my->flt.float_fract_e];
	res = ft_parse_fract(res);
	return (res);
}

void			fn_write_float(register t_my *my)
{
	t_lnbr	res;
	t_lnbr	sing;
	t_lnbr	fract;

	my->flt.float_sing = 0;
	my->flt.float_sing_e = 0;
	my->flt.float_fract = 0;
	my->flt.float_fract_e = 0;
	fn_pre(my, my->flt.e_save, my->flt.t_val.t_mant.mantissa);
	sing = parse_sing(my);
	fract = parse_fract(my);
	res = ft_round(sing, fract, my->opt.max);
	fn_str_copy(my, res.num, res.len);
}
