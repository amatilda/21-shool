/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:14:49 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/18 16:40:16 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

int					ft_error(const char *msg, ...)
{
	va_list			args;

	dprintf(fd().e, TASK_ERROR_COLOR);
	va_start(args, msg);
	vdprintf(fd().e, msg, args);
	va_end(args);
	dprintf(fd().e, "\n"TASK_RESET);
	return (msg ? -msg[0] : -128);
}

void				*my_memcpy(void *dst, const void *src, size_t n)
{
	register size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		*((char*)dst + i) = *((char*)src + i);
		i++;
	}
	return (dst);
}

void				*ft_memchr(const void *s, int c, size_t n)
{
	register size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)s + i) == (unsigned char)c)
			return ((void*)s + i);
		i++;
	}
	return (0);
}
