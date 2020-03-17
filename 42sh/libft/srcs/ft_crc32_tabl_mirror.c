/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crc32_tabl_mirror.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:45:36 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/06 21:16:19 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

void	ft_crc32_tabl_mirror(register uint32_t *lp, uint_fast8_t count_table,
register uint32_t polinom)
{
	register uint_fast8_t			big;
	register uint_fast16_t			i;
	register uint_fast16_t			count;
	register uint32_t				tempos;
	register uint32_t				value;

	big = 0;
	while (big++ < count_table)
	{
		i = 0;
		while (i <= 0xFF)
		{
			count = big << 3;
			value = i;
			while (count-- > 0)
			{
				tempos = value;
				value = value >> 1;
				if ((tempos & 1) != 0)
					value = value ^ polinom;
			}
			lp[i++] = value;
		}
		lp = lp + i;
	}
}
