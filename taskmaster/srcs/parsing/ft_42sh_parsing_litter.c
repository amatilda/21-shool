/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_litter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

size_t	ft_42sh_parsing_litter(register const char *s)
{
	register size_t			count;
	register char			litter;

	count = 0;
	while ((litter = s++[0]) != 0)
	{
		count++;
		if (((litter = s++[0]) & 0x80) != 0)
		{
			while (((litter = litter << 1) & 0x80) != 0)
				s++;
		}
		else if (litter == '\n')
			count -= 2;
	}
	return (count);
}

size_t	ft_42sh_parsing_litter_n(register const char *s, register const char *e)
{
	register size_t			count;
	register char			litter;

	count = 0;
	while (s < e)
	{
		count++;
		if (((litter = s++[0]) & 0x80) != 0)
		{
			while (((litter = litter << 1) & 0x80) != 0)
				s++;
		}
		else if (litter == '\n')
			count -= 2;
	}
	return (count);
}
