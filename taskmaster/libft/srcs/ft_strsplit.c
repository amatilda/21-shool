/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:08:06 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/03 23:08:09 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*fn_free(register char **array, register size_t index)
{
	while (index > 0)
	{
		ft_free(array[index]);
		index--;
	}
	ft_free(array);
	return (0);
}

static char		*fn_add_str(char **array, size_t index,
	register char const *s, register char c)
{
	register size_t		i;
	register size_t		size;
	register char		*tmp;
	register char		litter;

	size = 0;
	while ((litter = s[size]) != 0 && litter != c)
		size++;
	if ((tmp = ft_malloc(size + 1)) == 0)
		return (fn_free(array, index));
	array[index] = tmp;
	i = 0;
	while (i < size)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = 0;
	return ((char *)s + size);
}

static size_t	fn_size(register char const *s, register char c)
{
	register size_t		size;
	register char		litter;

	size = 0;
	while ((litter = s[0]) != 0)
	{
		if (litter != c)
		{
			while ((litter = s[0]) != 0 && litter != c)
				s++;
			size++;
		}
		else
			s++;
	}
	return (size);
}

char			**ft_strsplit(register char const *s, register char c)
{
	register char		**array;
	register size_t		i;
	register char		litter;

	i = fn_size(s, c);
	if ((array = ft_malloc((i + 1) * sizeof(char *))) == 0)
		return (0);
	array[i] = 0;
	if (i == 0)
		return (array);
	i = 0;
	while ((litter = s[0]) != 0)
	{
		if (litter != c)
		{
			if ((s = fn_add_str(array, i, s, c)) == 0)
				return (0);
			i++;
		}
		else
			s++;
	}
	return (array);
}
