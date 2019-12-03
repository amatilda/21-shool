/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:17:19 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/03 22:17:23 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	count;
	char	*out;

	count = 0;
	while (s1[count] != 0)
		count++;
	out = (char*)malloc(count + 1);
	if (out == 0)
		return (0);
	count = 0;
	while (s1[count] != 0)
	{
		out[count] = s1[count];
		count++;
	}
	out[count] = 0;
	return (out);
}
