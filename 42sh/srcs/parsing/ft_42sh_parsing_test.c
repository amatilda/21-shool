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

unsigned char		ft_42sh_parsing_test_pipe(register unsigned char *b,
register unsigned char *e, unsigned char old)
{
	register unsigned char				litter;

	if (b == e)
		return (0);
	if ((litter = b[0]) == '&' && b + 1 < e && (b[1] == '>' || b[1] == '<'))
		return (2);
	if (litter == '|' && b + 1 < e && b[1] == '|')
		return (0);
	if (litter == '|' || litter == '>' || litter == '<')
		return (1);
	if (old == 0x20 && ++b < e)
	{
		if (litter >= 0x30 && litter <= 0x39)
		{
			if (((old = b[0]) == '<') || old == '>')
				return (2);
			else if (old == '&' && ++b < e &&
			(((old = b[0]) == '<') || old == '>'))
				return (3);
		}
	}
	return (0);
}

unsigned char		ft_42sh_parsing_test_next(unsigned char **out,
register unsigned char *e, register unsigned char dquote, unsigned char old)
{
	register unsigned char	litter;
	register unsigned char	*b;

	b = *out;
	if (b == e)
		return (0);
	litter = b[0];
	if (dquote == 0)
		if ((ft_42sh_parsing_litter_e(b, e) == 0 || litter == 0x20) ||
		(ft_42sh_parsing_test_pipe(b, e, old) != 0))
			return (0);
	b++;
	*out = b;
	return (litter);
}
