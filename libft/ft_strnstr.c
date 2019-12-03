/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:16:00 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/10 19:10:24 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	tmp;

	if (to_find[0] == 0)
		return ((char *)str);
	i = 0;
	while (str[i] != 0 && i < len)
	{
		if (str[i] == to_find[0])
		{
			tmp = 0;
			while (str[i] != 0 && i < len && str[i] == to_find[tmp])
			{
				i++;
				tmp++;
			}
			if (to_find[tmp] == 0)
				return ((char *)&str[i - tmp]);
			i -= tmp;
		}
		i++;
	}
	return (0);
}
