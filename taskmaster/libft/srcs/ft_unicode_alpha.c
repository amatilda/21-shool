/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:45:36 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/06 21:16:19 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

static size_t	fn_next_text(register uint32_t unicode)
{
	if (unicode <= 0x489)
		return (0);
	else if (unicode <= 0x556)
		return (1);
	return (0);
}

size_t			ft_unicode_alpha(register uint32_t unicode)
{
	if (unicode <= 0xBF)
	{
		if ((unicode >= 0x30 && unicode <= 0x39) || (unicode >= 0x41 &&
		unicode <= 0x5A) || (unicode >= 0x61 && unicode <= 0x7A))
			return (1);
	}
	else if (unicode <= 0x2AF)
	{
		if (unicode != 0xF7)
			return (1);
	}
	else if (unicode <= 0x036F)
		return (0);
	else if (unicode < 0x0388)
	{
		if (unicode <= 0x0373 || unicode == 0x0386 || unicode == 0x037F ||
		unicode == 0x0376 || unicode == 0x0377)
			return (1);
	}
	else if (unicode <= 0x481)
		return (1);
	else
		return (fn_next_text(unicode));
	return (0);
}
