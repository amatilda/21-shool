/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:08:06 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/03 23:08:09 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;

	if (s == 0)
		return (0);
	if (len + 1 == 0)
		return (0);
	out = malloc(len + 1);
	if (out == 0)
		return (0);
	s += start;
	start = 0;
	while (s[start] != 0 && start < len)
	{
		out[start] = s[start];
		start++;
	}
	out[start] = 0;
	return (out);
}
