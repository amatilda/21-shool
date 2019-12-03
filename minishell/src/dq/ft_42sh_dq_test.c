/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char		ft_42sh_dq_test_slh(register char *b, register size_t n)
{
	register char		*lp_current;
	register size_t		tempos;

	lp_current = b + n - 1;
	tempos = 0;
	while (n-- != 0 && lp_current--[0] == '\\')
		tempos++;
	if ((tempos & 0x1) == 0)
		return (0);
	return ('\\');
}

char		ft_42sh_dq_test_dq(register char *b, register size_t n)
{
	register char		litter;
	register size_t		tempos;

	tempos = 0;
	while (tempos < n)
	{
		litter = b[tempos++];
		if (litter == '\\' && tempos < n)
			tempos++;
		else if ((litter == '"' || litter == '\''))
		{
			while (tempos < n)
			{
				if (litter == b[tempos] && b[tempos - 1] != '\\')
					break ;
				tempos++;
			}
			if (tempos == n)
				return (litter);
			tempos++;
		}
	}
	return (ft_42sh_dq_test_slh(b, n));
}

char		ft_42sh_dq_test(register char *b, register size_t n,
register char litter)
{
	register size_t		tempos;

	if (litter == '\\')
		return (ft_42sh_dq_test_dq(b, n));
	if (n == 0)
		return (litter);
	if (litter == b[0])
		return (ft_42sh_dq_test_dq(b + 1, n - 1));
	tempos = 0;
	while (tempos < n)
	{
		if (litter == b[tempos] && b[tempos - 1] != '\\')
			return (ft_42sh_dq_test_dq(b + tempos + 1, n - tempos - 1));
		tempos++;
	}
	return (litter);
}
