/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:17:19 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/03 22:17:23 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strndup(const char *s1, size_t n)
{
	register size_t		count;
	register char		*out;

	out = (char*)ft_malloc(n + 1);
	if (out == 0)
		return (0);
	count = 0;
	while (count < n)
	{
		out[count] = s1[count];
		count++;
	}
	out[count] = 0;
	return (out);
}
