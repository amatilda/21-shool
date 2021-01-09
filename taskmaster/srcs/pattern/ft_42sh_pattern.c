/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pattern.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_pattern.h"

static unsigned char		*fn_next(unsigned char *b,
register uintmax_t litter, register size_t count)
{
	if ((uint32_t)litter == '?')
		b += (ft_utf8_decode(b) >> (sizeof(litter) * 4));
	else if (litter == ft_utf8_decode(b))
		b += count;
	else
		return (0);
	return (b);
}

static size_t				fn_finish(unsigned char *b, unsigned char *e,
unsigned char *b_ptt, unsigned char *e_ptt)
{
	if (b_ptt != e_ptt || b != e)
		return (0);
	return (1);
}

static size_t				fn_stub(unsigned char **out,
unsigned char **out_ptt, register unsigned char *e_ptt,
register uintmax_t litter)
{
	if ((uint32_t)litter == '\\')
	{
		if (ft_42sh_pattern_slesh(out, out_ptt, e_ptt) == 0)
			return (0);
		return (1);
	}
	else if ((uint32_t)litter == '[')
	{
		if (ft_42sh_pattern_interval(out, out_ptt, e_ptt) == 0)
			return (0);
		return (1);
	}
	return (1);
}

size_t						ft_42sh_pattern(unsigned char *b, unsigned char *e,
unsigned char *b_ptt, unsigned char *e_ptt)
{
	register uintmax_t				litter;
	register size_t					count;

	if (b_ptt >= e_ptt)
		return (1);
	while (b_ptt < e_ptt && b < e)
	{
		litter = ft_utf8_decode(b_ptt);
		count = (litter >> (sizeof(litter) * 4));
		b_ptt += count;
		if ((uint32_t)litter == '\\' || (uint32_t)litter == '[')
		{
			if (fn_stub(&b, &b_ptt, e_ptt, litter) == 0)
				return (0);
		}
		else if ((uint32_t)litter == '*')
			return (ft_42sh_pattern_star(b, e, b_ptt, e_ptt));
		else if ((b = fn_next(b, litter, count)) == 0)
			return (0);
	}
	return (fn_finish(b, e, b_ptt, e_ptt));
}
