/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/10/14 23:45:01 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	*stub_0(void *b, int c, size_t len, register size_t i)
{
	while (i < len)
		*((unsigned char*)b + i++) = c;
	return (b);
}

void		*ft_memset(void *b, int c, size_t len)
{
	register char	*p;
	register size_t	i;
	register size_t	set;

	i = 0;
	set = (unsigned char)c;
	if (len >= sizeof(size_t) * 8 - 1)
	{
		while (i++ < sizeof(size_t) - 1)
			set = set << 8 | (unsigned char)c;
		i = 0;
		while (((size_t)(b + i) & (sizeof(size_t) * 2 - 1)) != 0)
			*((unsigned char*)b + i++) = c;
		p = b + i;
		while (i + sizeof(size_t) * 2 <= len)
		{
			*((size_t*)p) = set;
			*((size_t*)p + 1) = set;
			p += sizeof(size_t) * 2;
			i += sizeof(size_t) * 2;
		}
		if (i > len)
			i -= sizeof(size_t) * 2;
	}
	return (stub_0(b, c, len, i));
}
