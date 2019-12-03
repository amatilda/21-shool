/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

unsigned char			ft_42sh_parsing_test_next(unsigned char **out,
register unsigned char *e, register unsigned char dquote)
{
	register unsigned char	litter;
	register unsigned char	*b;

	b = *out;
	if (b == e || ((litter = b[0]) == ';' && dquote == 0) || litter < 0x20)
		return (0);
	b++;
	if (litter == 0x20)
	{
		if (dquote == 0)
			litter = 0;
		else if (b < e && b[0] == '\n')
		{
			b++;
			litter = '\n';
		}
	}
	*out = b;
	return (litter);
}
