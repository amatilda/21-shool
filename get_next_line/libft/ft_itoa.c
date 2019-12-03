/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:16:51 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/10 16:44:00 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	intmax_t	value;
	char		*out;
	int			count;
	int			i;
	char		buffer[sizeof(uintmax_t) * 4 + 1];

	value = n;
	count = ft_itoa_base(buffer, value, 10, ITOA_LOWER | ITOA_SIGNED);
	out = malloc(count + 1);
	if (out == 0)
		return (0);
	i = 0;
	while (i < count)
	{
		out[i] = buffer[i];
		i++;
	}
	out[i] = 0;
	return (out);
}
