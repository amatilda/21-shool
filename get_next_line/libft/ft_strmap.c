/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:08:06 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/03 23:08:09 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		count;
	char		*out;

	if (s == 0 || f == 0)
		return (0);
	count = 0;
	while (s[count] != 0)
		count++;
	count++;
	if (count == 0)
		return (0);
	out = malloc(count);
	if (out == 0)
		return (0);
	count = 0;
	while (s[count] != 0)
	{
		out[count] = f(s[count]);
		count++;
	}
	out[count] = 0;
	return (out);
}
