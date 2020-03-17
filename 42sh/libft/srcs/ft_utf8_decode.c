/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_decode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:45:36 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/06 21:16:19 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

static uintmax_t	fn_final(register uint32_t unicode,
register size_t n)
{
	register uintmax_t			out;

	out = n;
	out = out << (sizeof(uintmax_t) * 8 / 2);
	return (out | unicode);
}

uintmax_t			ft_utf8_decode(register const unsigned char *b)
{
	register uint32_t				unicode;
	register unsigned char			litter;
	register size_t					n;

	n = 1;
	if (((litter = b[0]) & 0x80) != 0)
		while (((litter = litter << 1) & 0x80) != 0)
			n++;
	if (n == 1)
		unicode = litter;
	else if (n == 2)
		unicode = (litter >> n) * 0x40 + (b[1] ^ 0x80);
	else if (n == 3)
		unicode = (litter >> n) * 0x1000 + (b[1] ^ 0x80) * 0x40 +
		(b[2] ^ 0x80);
	else if (n == 4)
		unicode = (litter >> n) * 0x10000 + (b[1] ^ 0x80) * 0x1000 +
		(b[2] ^ 0x80) * 0x40 + (b[3] ^ 0x80);
	else
		unicode = '?';
	return (fn_final(unicode, n));
}
