/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/10/14 23:52:24 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	fn_stub(char *s, size_t temp)
{
	if (temp >= 0x800)
	{
		s[0] = (char)(temp >> 0xC) | 0xE0;
		s[1] = (char)((temp >> 0x6) & 0x3F) | 0x80;
		s[2] = (char)((temp & 0x3F) | 0x80);
		return (3);
	}
	s[0] = (char)(temp >> 0x6) | 0xC0;
	s[1] = (char)((temp & 0x3F) | 0x80);
	return (2);
}

int			ft_wctomb(char *s, wchar_t wchar)
{
	size_t	temp;

	if (!s)
		return (0);
	temp = wchar;
	if (temp > 0x10FFFF)
		return (-1);
	else if (temp <= 0x7F)
	{
		s[0] = (char)temp;
		return (1);
	}
	else if (temp >= 0x10000)
	{
		s[0] = (char)(temp >> 0x12) | 0xF0;
		s[1] = (char)((temp >> 0xC) & 0x3F) | 0x80;
		s[2] = (char)((temp >> 0x6) & 0x3F) | 0x80;
		s[3] = (char)((temp & 0x3F) | 0x80);
		return (4);
	}
	return (fn_stub(s, temp));
}
