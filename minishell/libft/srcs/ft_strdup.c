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

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	register size_t		count;
	register char		*out;
	register char		litter;

	count = 0;
	while (s1[count] != 0)
		count++;
	out = (char*)malloc(count + 1);
	if (out == 0)
		return (0);
	count = 0;
	while ((litter = s1[count]) != 0)
	{
		out[count] = litter;
		count++;
	}
	out[count] = 0;
	return (out);
}
