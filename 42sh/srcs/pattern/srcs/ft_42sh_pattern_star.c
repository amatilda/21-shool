/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pattern_star.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_pattern.h"

size_t				ft_42sh_pattern_star(register unsigned char *b,
register unsigned char *e, register unsigned char *b_ptt,
register unsigned char *e_ptt)
{
	register uintmax_t				litter;

	while (b_ptt < e_ptt && (uint32_t)(litter = ft_utf8_decode(b_ptt) == '*'))
		b_ptt += (litter >> (sizeof(litter) * 4));
	while (b < e)
	{
		if (ft_42sh_pattern(b, e, b_ptt, e_ptt) != 0)
			return (1);
		litter = ft_utf8_decode(b_ptt);
		b += (litter >> (sizeof(litter) * 4));
	}
	return (0);
}
