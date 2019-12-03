/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 21:58:55 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/11 23:06:36 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	out;

	x = 0;
	while (dest[x] != 0)
		x++;
	out = 0;
	while (src[out] != 0)
		out++;
	out += (size <= x) ? size : x;
	y = 0;
	while (src[y] != 0 && x + 1 < size)
		dest[x++] = src[y++];
	dest[x] = 0;
	return (out);
}
