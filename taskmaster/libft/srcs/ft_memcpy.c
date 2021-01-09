/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:40:10 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/03 20:40:27 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

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
