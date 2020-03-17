/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pattern_interval.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pattern.h"

unsigned char			*ft_42sh_pattern_interval_end(register unsigned
char *b_ptt, register unsigned char *e_ptt)
{
	register unsigned char			*tmp;
	register unsigned char			litter;

	tmp = b_ptt;
	while (b_ptt < e_ptt && (litter = b_ptt[0]) != ']')
		b_ptt++;
	if (litter != ']')
		return (tmp);
	return (b_ptt);
}

size_t					ft_42sh_pattern_interval(unsigned char **out,
unsigned char **out_ptt, register unsigned char *e_ptt)
{
	register unsigned char			*b_ptt;
	register uintmax_t				cmp_lit;

	b_ptt = *out_ptt;
	e_ptt = ft_42sh_pattern_interval_end(b_ptt, e_ptt);
	cmp_lit = ft_utf8_decode(*out);
	*out = *out + (cmp_lit >> (sizeof(cmp_lit) * 4));
	if (b_ptt == e_ptt)
	{
		if (cmp_lit == (((uintmax_t)1) << (sizeof(uintmax_t) * 4) | '['))
			return (1);
		return (0);
	}
	*out_ptt = e_ptt + 1;
	return (ft_42sh_pattern_interval_while(cmp_lit, b_ptt, e_ptt));
}
