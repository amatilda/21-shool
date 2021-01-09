/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pattern_slesh.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pattern.h"

size_t			ft_42sh_pattern_slesh(unsigned char **out,
unsigned char **out_ptt, register unsigned char *e_ptt)
{
	register unsigned char			*b_ptt;
	register uintmax_t				litter;

	b_ptt = *out_ptt;
	if (b_ptt < e_ptt)
	{
		litter = ft_utf8_decode(b_ptt);
		if ((uint32_t)litter == '\\' || (uint32_t)litter == '?' ||
		(uint32_t)litter == '[' || (uint32_t)litter == ']' ||
		(uint32_t)litter == '*' || (uint32_t)litter == '^' ||
		(uint32_t)litter == '!')
			*out_ptt = *out_ptt + 1;
		else
			litter = (((uintmax_t)1) << (sizeof(uintmax_t) * 4) | '\\');
	}
	else
		litter = (((uintmax_t)1) << (sizeof(uintmax_t) * 4) | '\\');
	if (litter != ft_utf8_decode(*out))
		return (0);
	*out = *out + 1;
	return (1);
}

size_t			ft_42sh_pattern_slesh_litter(register unsigned char *b_ptt,
register unsigned char *e_ptt, register uint32_t cmp_lit)
{
	register uintmax_t				litter;

	if (b_ptt < e_ptt)
	{
		litter = ft_utf8_decode(b_ptt);
		if ((uint32_t)litter == '\\' || (uint32_t)litter == '?' ||
		(uint32_t)litter == '[' || (uint32_t)litter == ']' ||
		(uint32_t)litter == '*' || (uint32_t)litter == '^' ||
		(uint32_t)litter == '!')
			;
		else
			litter = (((uintmax_t)1) << (sizeof(uintmax_t) * 4) | '\\');
	}
	else
		litter = (((uintmax_t)1) << (sizeof(uintmax_t) * 4) | '\\');
	if ((uint32_t)litter != cmp_lit)
		return (0);
	return (1);
}

void			ft_42sh_pattern_slesh_next(unsigned char **out_ptt,
register unsigned char *e_ptt)
{
	register unsigned char			*b_ptt;
	register uintmax_t				litter;

	b_ptt = *out_ptt;
	if (b_ptt < e_ptt)
	{
		litter = ft_utf8_decode(b_ptt);
		if ((uint32_t)litter == '\\' || (uint32_t)litter == '?' ||
		(uint32_t)litter == '[' || (uint32_t)litter == ']' ||
		(uint32_t)litter == '*' || (uint32_t)litter == '^' ||
		(uint32_t)litter == '!')
			*out_ptt = *out_ptt + 1;
	}
	return ;
}
