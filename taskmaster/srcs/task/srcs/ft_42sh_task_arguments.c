/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_arguments.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

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
register char const *s, register char const *e)
{
	register size_t		i;
	register size_t		size;
	register char		*tmp;

	size = 0;
	while (&s[size] < e && s[size] != 0)
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

static char		**fn_strsplit(register char const *s, register char const *e,
register size_t i)
{
	register char		**array;
	register char		litter;

	if ((array = ft_malloc((i + 1) * sizeof(char *))) == 0)
		return (0);
	array[i] = 0;
	i = 0;
	while (s < e)
	{
		if ((litter = s[0]) != 0)
		{
			if ((s = fn_add_str(array, i, s, e)) == 0)
				return (0);
			i++;
		}
		else
			s++;
	}
	return (array);
}

char			**ft_42sh_task_arguments(register unsigned char *dest,
register unsigned char *b, unsigned char *e)
{
	register char				**arg;
	register size_t				count;

	if (dest == 0)
		return (0);
	count = ft_42sh_task_arguments_count(dest, b, &e);
	arg = fn_strsplit((void *)dest, (void *)e, count);
	ft_free(dest);
	return (arg);
}
