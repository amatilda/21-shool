/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:50:46 by jkrypto           #+#    #+#             */
/*   Updated: 2019/09/20 21:52:21 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fn_test_stub(register t_fillit *fill, register char *figur,
	register int_fast8_t x_i, register int_fast8_t y_i)
{
	fill->x_2 = x_i + figur[2];
	fill->x_3 = x_i + figur[4];
	fill->x_4 = x_i + figur[6];
	fill->y_2 = y_i + figur[3];
	fill->y_3 = y_i + figur[5];
	fill->y_4 = y_i + figur[7];
}

static int	fn_test(register t_fillit *fill, register uint_fast8_t i,
	register int_fast8_t x_i, register int_fast8_t y_i)
{
	register char			*figur;
	register int_fast8_t	tempos;

	figur = (char *)(fill->x_y + fill->tettrin_c_tmp * 8);
	x_i -= figur[0];
	y_i -= figur[1];
	fn_test_stub(fill, figur, x_i, y_i);
	tempos = fill->sqr_line;
	if (fill->y_2 >= tempos || fill->y_3 >= tempos || fill->y_4 >= tempos ||
		fill->x_2 >= tempos || fill->x_3 >= tempos || fill->x_4 >= tempos ||
		fill->x_2 < 0 || fill->x_3 < 0 || fill->x_4 < 0)
		return (0);
	figur = fill->in;
	fill->x_2 += tempos * fill->y_2 + fill->y_2;
	fill->x_3 += tempos * fill->y_3 + fill->y_3;
	fill->x_4 += tempos * fill->y_4 + fill->y_4;
	if (figur[fill->x_2] != '.' || figur[fill->x_3] != '.'
		|| figur[fill->x_4] != '.')
		return (0);
	tempos = fill->alphabet[fill->tettrin_c_tmp];
	figur[i] = tempos;
	figur[fill->x_2] = tempos;
	figur[fill->x_3] = tempos;
	figur[fill->x_4] = tempos;
	return (1);
}

static int	fn_bruteforce_stub(register t_fillit *fill, register uint_fast8_t i)
{
	int_fast8_t		x_2;
	int_fast8_t		x_3;
	int_fast8_t		x_4;

	x_2 = fill->x_2;
	x_3 = fill->x_3;
	x_4 = fill->x_4;
	if (++fill->tettrin_c_tmp == fill->tettrin_c)
		return (1);
	else if (fn_bruteforce(fill, 0, 0, 0) != 0)
		return (1);
	fill->tettrin_c_tmp--;
	fill->in[i] = '.';
	fill->in[x_2] = '.';
	fill->in[x_3] = '.';
	fill->in[x_4] = '.';
	return (0);
}

int			fn_bruteforce(register t_fillit *fill, register uint_fast8_t i,
	register int_fast8_t x_i, register int_fast8_t y_i)
{
	while (i < fill->sqrt_i)
	{
		if (x_i < fill->sqr_line)
		{
			if (fill->in[i] == '.' && fn_test(fill, i, x_i, y_i) != 0
				&& fn_bruteforce_stub(fill, i) != 0)
				return (1);
		}
		else
		{
			x_i = -1;
			y_i++;
		}
		x_i++;
		i++;
	}
	return (0);
}
