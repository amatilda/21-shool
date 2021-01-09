/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_utf8_litter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:45:36 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/06 21:16:19 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

size_t	ft_strlen_utf8_litter(register void *s)
{
	register uint_fast8_t	litter;
	register size_t			count;

	if ((litter = ((unsigned char *)s)[0]) == 0)
		return (0);
	if ((litter & 0x80) == 0)
		return (1);
	count = 1;
	if ((litter & 0x40) != 0)
	{
		while (((litter = litter << 1) & 0x80) != 0)
			count++;
	}
	else
	{
		while (((litter = ((unsigned char *)s)[0]) & 0x40) == 0)
		{
			--s;
			count++;
		}
	}
	return (count);
}
