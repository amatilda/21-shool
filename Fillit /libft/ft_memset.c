/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	t_memset	mem;

	mem.i = 0;
	mem.set = (unsigned char)c;
	if (len >= sizeof(size_t) * 8 - 1)
	{
		while (mem.i++ < sizeof(size_t) - 1)
			mem.set = mem.set << 8 | (unsigned char)c;
		mem.i = 0;
		while (((size_t)(b + mem.i) & (sizeof(size_t) * 2 - 1)) != 0)
			*((unsigned char*)b + mem.i++) = c;
		mem.p = b + mem.i;
		while (mem.i + sizeof(size_t) * 2 <= len)
		{
			*((size_t*)mem.p) = mem.set;
			*((size_t*)mem.p + 1) = mem.set;
			mem.p += sizeof(size_t) * 2;
			mem.i += sizeof(size_t) * 2;
		}
		if (mem.i > len)
			mem.i -= sizeof(size_t) * 2;
	}
	while (mem.i < len)
		*((unsigned char*)b + mem.i++) = c;
	return (b);
}
