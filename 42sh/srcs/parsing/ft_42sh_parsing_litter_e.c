/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_litter_e.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

size_t				ft_42sh_parsing_litter_e_v(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		litter;

	if (b == e)
		return (0);
	litter = b[0];
	if (litter == ';' || litter == '\n')
		return (litter);
	if ((litter == '&' || litter == '|') && b + 1 < e && b[1] == litter)
		return ((litter << 8) | litter);
	if (litter == '&')
		return (litter);
	return (0);
}

void				*ft_42sh_parsing_litter_e_l(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		litter;

	if (b == e)
		return (b);
	litter = b[0];
	if (litter == ';' || litter == '\n')
		return (b + 1);
	if ((litter == '&' || litter == '|') && b + 1 < e && b[1] == litter)
		return (b + 2);
	if (litter == '&')
		return (b + 1);
	return (b);
}

unsigned char		ft_42sh_parsing_litter_e(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		litter;

	if (b == e)
		return (0);
	litter = b[0];
	if (litter == ';' || litter == '\n')
		return (0);
	if ((litter == '&' || litter == '|') && b + 1 < e && b[1] == litter)
		return (0);
	if (litter == '&')
		return (0);
	return (litter);
}
