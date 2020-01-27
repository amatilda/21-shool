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

#include <stddef.h>

static void		*fn_write_big(register void *b, register void *e,
register size_t c)
{
	register size_t				set;
	register size_t				i;

	i = 0;
	set = (unsigned char)c;
	while (i++ < (sizeof(size_t) - 1))
		set = set << sizeof(size_t) | (unsigned char)c;
	while (((size_t)b & (sizeof(size_t) * 2 - 1)) != 0)
	{
		*(unsigned char*)b = c;
		b++;
	}
	while ((b + sizeof(size_t) * 2) <= e)
	{
		*((size_t*)b) = set;
		*((size_t*)b + 1) = set;
		b += sizeof(size_t) * 2;
	}
	if (b > e)
		b -= sizeof(size_t) * 2;
	return (b);
}

void			*ft_memset(register void *b, register int c, size_t len)
{
	void					*out;
	register void			*e;

	out = b;
	e = b + len;
	if (len >= sizeof(size_t) * 8 - 1)
		b = fn_write_big(b, e, c);
	while (b < e)
	{
		*(unsigned char*)b = c;
		b++;
	}
	return (out);
}
