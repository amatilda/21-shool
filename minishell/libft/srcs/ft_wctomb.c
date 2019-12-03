/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	fn_stub(register char *str, register size_t tmp)
{
	if (tmp >= 0x800)
	{
		str[0] = (char)(tmp >> 0xC) | 0xE0;
		str[1] = (char)((tmp >> 0x6) & 0x3F) | 0x80;
		str[2] = (char)((tmp & 0x3F) | 0x80);
		return (3);
	}
	str[0] = (char)(tmp >> 0x6) | 0xC0;
	str[1] = (char)((tmp & 0x3F) | 0x80);
	return (2);
}

int			ft_wctomb(char *s, wchar_t wchar)
{
	register size_t		tmp;
	register char		*str;

	str = s;
	if (str == 0)
		return (0);
	tmp = wchar;
	if (tmp > 0x10FFFF)
		return (-1);
	else if (tmp <= 0x7F)
	{
		str[0] = (char)tmp;
		return (1);
	}
	else if (tmp >= 0x10000)
	{
		str[0] = (char)(tmp >> 0x12) | 0xF0;
		str[1] = (char)((tmp >> 0xC) & 0x3F) | 0x80;
		str[2] = (char)((tmp >> 0x6) & 0x3F) | 0x80;
		str[3] = (char)((tmp & 0x3F) | 0x80);
		return (4);
	}
	return (fn_stub(s, tmp));
}
