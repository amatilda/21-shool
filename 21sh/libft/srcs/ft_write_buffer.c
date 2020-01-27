/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_write_buffer(register t_write_buff *array)
{
	if (array->count != 0)
	{
		write(array->fd, array->b, array->count);
		array->count = 0;
	}
}

void		ft_write_buffer_char(register t_write_buff *array,
	register const char litter, register size_t n)
{
	register size_t			count;
	register size_t			max;
	register char			*b;

	count = array->count;
	max = array->max;
	b = array->b;
	while (n-- != 0)
	{
		if (count == max)
		{
			write(array->fd, b, count);
			count = 0;
		}
		b[count++] = litter;
	}
	array->count = count;
}

void		ft_write_buffer_str(register t_write_buff *array,
	register const char *str, register size_t n)
{
	register size_t			count;
	register size_t			max;
	register char			*b;

	count = array->count;
	max = array->max;
	b = array->b;
	while (n-- != 0)
	{
		if (count == max)
		{
			write(array->fd, b, count);
			count = 0;
		}
		b[count++] = str++[0];
	}
	array->count = count;
}

void		ft_write_buffer_str_zero(register t_write_buff *array,
	register const char *str)
{
	register size_t			count;
	register char			litter;
	register size_t			max;
	register char			*b;

	count = array->count;
	max = array->max;
	b = array->b;
	while ((litter = str++[0]) != 0)
	{
		if (count == max)
		{
			write(array->fd, b, count);
			count = 0;
		}
		b[count++] = litter;
	}
	array->count = count;
}
