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

static char		*fn_free(char **array, size_t index)
{
	while (index > 0)
	{
		free(array[index]);
		index--;
	}
	free(array);
	return (0);
}

static char		*fn_add_str(char **array, size_t index, char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	*tmp;

	size = 0;
	while (s[size] != 0 && s[size] != c)
		size++;
	tmp = malloc(size + 1);
	if (tmp == 0)
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

static size_t	fn_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (s[0] != 0)
	{
		if (s[0] != c)
		{
			while (s[0] != 0 && s[0] != c)
				s++;
			size++;
		}
		else
			s++;
	}
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	i;

	if (s == 0 || c == 0)
		return (0);
	if ((i = fn_size(s, c)) + 1 == 0)
		return (0);
	if ((array = malloc((i + 1) * sizeof(char *))) == 0)
		return (0);
	array[i] = 0;
	if (i == 0)
		return (array);
	i = 0;
	while (s[0] != 0)
	{
		if (s[0] != c)
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
