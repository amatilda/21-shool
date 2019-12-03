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

static int	fn_stub(char *s, size_t tmp)
{
	if (tmp >= 0x800)
	{
		s[0] = (char)(tmp >> 0xC) | 0xE0;
		s[1] = (char)((tmp >> 0x6) & 0x3F) | 0x80;
		s[2] = (char)((tmp & 0x3F) | 0x80);
		return (3);
	}
	s[0] = (char)(tmp >> 0x6) | 0xC0;
	s[1] = (char)((tmp & 0x3F) | 0x80);
	return (2);
}

int			ft_wctomb(char *s, wchar_t wchar)
{
	size_t	tmp;

	if (s == 0)
		return (0);
	tmp = wchar;
	if (tmp > 0x10FFFF)
		return (-1);
	else if (tmp <= 0x7F)
	{
		s[0] = (char)tmp;
		return (1);
	}
	else if (tmp >= 0x10000)
	{
		s[0] = (char)(tmp >> 0x12) | 0xF0;
		s[1] = (char)((tmp >> 0xC) & 0x3F) | 0x80;
		s[2] = (char)((tmp >> 0x6) & 0x3F) | 0x80;
		s[3] = (char)((tmp & 0x3F) | 0x80);
		return (4);
	}
	return (fn_stub(s, tmp));
}
