/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		fn_dub_char(register t_main *array, register const char litter,
	register size_t dup_count)
{
	register size_t			count;
	register char			*b;

	count = array->count;
	b = array->b;
	while (dup_count-- != 0)
	{
		if (count == FT_LS_BUFFER_SIZE)
		{
			write(1, b, count);
			count = 0;
		}
		b[count++] = litter;
	}
	array->count = count;
}

void		fn_copy_str(register t_main *array, register const char *str,
	register size_t n)
{
	register size_t			count;
	register char			*b;

	count = array->count;
	b = array->b;
	while (n-- != 0)
	{
		if (count == FT_LS_BUFFER_SIZE)
		{
			write(1, b, count);
			count = 0;
		}
		b[count++] = str++[0];
	}
	array->count = count;
}

void		fn_copy_str_zero(register t_main *array, register const char *str)
{
	register size_t			count;
	register char			litter;
	register char			*b;

	count = array->count;
	b = array->b;
	while ((litter = str++[0]) != 0)
	{
		if (count == FT_LS_BUFFER_SIZE)
		{
			write(1, b, count);
			count = 0;
		}
		b[count++] = litter;
	}
	array->count = count;
}

void		fn_copy_str_zero_invalid(register t_main *array,
	register const char *str)
{
	register size_t			count;
	register char			litter;
	register char			*b;

	count = array->count_invalid;
	b = array->b_invalid;
	while ((litter = str++[0]) != 0)
	{
		if (count == FT_LS_BUFFER_SIZE_INVALID)
		{
			write(2, b, count);
			count = 0;
		}
		b[count++] = litter;
	}
	array->count_invalid = count;
}
