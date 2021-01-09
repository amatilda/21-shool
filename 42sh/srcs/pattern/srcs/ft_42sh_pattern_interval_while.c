/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pattern_interval_while.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pattern.h"

static size_t		fn_ret(uint_fast8_t ret, uint_fast8_t b_test)
{
	if (b_test == 0)
		return (ret);
	if (ret == 0)
		return (1);
	return (0);
}

static size_t		fn_test_interval(register uint32_t cmp_lit,
register uint32_t fr_lit, register uint32_t tw_lit)
{
	if (fr_lit > tw_lit)
		return (1);
	if (cmp_lit >= fr_lit && cmp_lit <= tw_lit)
		return (0);
	return (1);
}

static size_t		fn_while(register uint32_t cmp_lit,
register unsigned char *b_ptt, register unsigned char *e_ptt,
uint_fast8_t b_test)
{
	register uintmax_t				fr_lit;
	register uintmax_t				tw_lit;

	while (b_ptt < e_ptt)
	{
		fr_lit = ft_utf8_decode(b_ptt);
		b_ptt = b_ptt + (fr_lit >> (sizeof(fr_lit) * 4));
		if (b_ptt + 1 < e_ptt && b_ptt[0] == '-')
		{
			b_ptt++;
			tw_lit = ft_utf8_decode(b_ptt);
			if (fn_test_interval(cmp_lit, fr_lit, tw_lit) == 0)
				return (fn_ret(1, b_test));
			b_ptt = b_ptt + (tw_lit >> (sizeof(tw_lit) * 4));
		}
		else if ((uint32_t)fr_lit == cmp_lit)
			return (fn_ret(1, b_test));
	}
	return (fn_ret(0, b_test));
}

size_t				ft_42sh_pattern_interval_while(register uint32_t cmp_lit,
register unsigned char *b_ptt, register unsigned char *e_ptt)
{
	register uintmax_t				litter;
	uint_fast8_t					b_test;

	if (((litter = b_ptt[0]) == '^' || litter == '!'))
	{
		b_ptt++;
		b_test = 1;
	}
	else
		b_test = 0;
	return (fn_while(cmp_lit, b_ptt, e_ptt, b_test));
}
