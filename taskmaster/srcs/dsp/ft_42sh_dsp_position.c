/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dsp_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

uintmax_t		ft_42sh_dsp_position(void)
{
	register uintmax_t			out;
	register ssize_t			tempos;
	register unsigned char		*b;
	register unsigned char		*e;
	char						buff[30];

	write(FD_TERMINAL_42SH, "\x1b[6n", 4);
	b = (void *)buff;
	if ((tempos = read(FD_TERMINAL_42SH, b, (sizeof(buff) - 1))) <= 2)
		return (0);
	e = b + tempos;
	b += 2;
	e[0] = 0;
	out = ft_atoi((void *)b);
	out = out << (sizeof(uintmax_t) * 8 / 2);
	while (b < e && ((tempos = b[0]) >= 0x30 && tempos <= 0x39))
		b++;
	if (b++ == e)
		return (0);
	if (((tempos = b[0]) < 0x30 || tempos > 0x39))
		return (0);
	out |= ft_atoi((void *)b);
	return (out);
}
