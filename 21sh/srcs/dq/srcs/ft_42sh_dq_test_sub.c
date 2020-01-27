/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_sub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static unsigned char	fn_exp(unsigned char **out,
register unsigned char *e)
{
	register unsigned char		*b;
	register unsigned char		litter;

	b = *out;
	while (b < e)
	{
		litter = b++[0];
		if (litter == '}')
		{
			*out = b;
			return (0);
		}
		else if (litter == '"' || litter == '\'')
		{
			*out = b;
			if ((litter = ft_42sh_dq_test_dq(out, e, litter)) != 0)
				return (litter);
			b = *out;
		}
	}
	*out = b;
	return ('}');
}

unsigned char			ft_42sh_dq_test_sub(unsigned char **out,
register unsigned char *e, register unsigned char litter)
{
	if (litter == '{' && (litter = fn_exp(out, e)) != 0)
		return (litter);
	return (0);
}
