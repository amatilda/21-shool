/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:08:33 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/20 21:48:18 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static uint_fast8_t	fn_validate_block(register char *lp_in,
	register uint_fast8_t i)
{
	register uint_fast8_t	tmp;

	tmp = 0;
	if (i <= 14 && lp_in[i + 5] == '#')
		tmp++;
	if (i >= 4 && lp_in[i - 5] == '#')
		tmp++;
	if (i >= 1 && lp_in[i - 1] == '#')
		tmp++;
	if (i <= 19 && lp_in[i + 1] == '#')
		tmp++;
	if (tmp > 3 || tmp == 0)
		return (9);
	return (tmp);
}

static int			fn_while(register t_fillit *fill, register char *lp_figur,
	register char *lp_in, register uint_fast8_t count)
{
	register uint_fast8_t	i;
	register uint_fast8_t	tempos;

	i = 0;
	fill->contact_c = 0;
	while (i < 20)
	{
		if (lp_in[i] == '#')
		{
			if (count++ > 3)
				return (0);
			tempos = i / 5;
			lp_figur[0] = i - tempos * 5;
			lp_figur[1] = tempos;
			lp_figur += 2;
			fill->contact_c += fn_validate_block(lp_in, i);
		}
		else if (lp_in[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void			fn_pre_reversi(register t_fillit *fill)
{
	register size_t tmp;

	tmp = 2;
	fill->alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	ft_memset(fill->in, '.', BUFF_SIZE);
	while (tmp < 79)
	{
		fill->tettrin_c_tmp = 0;
		fill->sqr_line = tmp;
		fill->sqrt_i = tmp * tmp + tmp;
		if (fn_bruteforce(fill, 0, 0, 0) != 0)
			break ;
		tmp++;
	}
	while (tmp < fill->sqrt_i)
	{
		fill->in[tmp] = '\n';
		tmp += fill->sqr_line + 1;
	}
	write(1, fill->in, fill->sqrt_i);
}

int					fn_validate(register t_fillit *fill, register char *lp_in)
{
	register char			*lp_figur;

	lp_figur = fill->x_y;
	fill->tmp = 0;
	while (fill->tmp < fill->tettrin_c)
	{
		if (lp_in[4] != '\n' || lp_in[9] != '\n' || lp_in[14] != '\n' ||
			lp_in[19] != '\n')
			return (0);
		lp_in[4] = '.';
		lp_in[9] = '.';
		lp_in[14] = '.';
		lp_in[19] = '.';
		if (fn_while(fill, lp_figur, lp_in, 0) == 0)
			return (0);
		if ((fill->contact_c != 6 && fill->contact_c != 8) ||
			(fill->tmp + 1 < fill->tettrin_c && lp_in[20] != '\n'))
			return (0);
		lp_figur += 8;
		lp_in += 21;
		fill->tmp++;
	}
	fn_pre_reversi(fill);
	return (1);
}
