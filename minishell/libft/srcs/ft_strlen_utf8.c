/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:45:36 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/06 21:16:19 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen_utf8(register const char *s)
{
	register size_t			count;
	register char			litter;

	count = 0;
	while ((litter = s++[0]) != 0)
	{
		count++;
		if ((litter & 0x80) != 0)
		{
			while (((litter = s[0]) & 0x80) != 0 && (litter & 0x40) == 0)
				s++;
		}
	}
	return (count);
}
