/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_exp.h"

void			*ft_42sh_exp_name(register unsigned char *b,
register unsigned char *e)
{
	register uintmax_t				out;
	register unsigned char			litter;

	if (b == e || ((litter = b[0]) >= 0x30 && litter <= 0x39))
		return (b);
	while (b < e)
	{
		if (b[0] == '_')
		{
			b++;
			continue;
		}
		out = ft_utf8_decode((void *)b);
		if (ft_unicode_alpha((uint32_t)out) == 0)
			return (b);
		b += out >> (sizeof(uintmax_t) * 8 / 2);
	}
	return (b);
}

void			*ft_42sh_exp_name_special(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char			litter;

	if (b == e)
		return (b);
	if ((litter = b[0]) == '?' || litter == '$' || litter == '!')
		return (b + 1);
	return (ft_42sh_exp_name(b, e));
}

void			*ft_42sh_exp_test_exp(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char			*tmp;

	tmp = ft_42sh_exp_name(b, e);
	if (tmp == e)
		return (0);
	if (b[0] == '=' || tmp[0] != '=')
		return (0);
	return (tmp + 1);
}
