/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_str_test_read.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void				fn_test_save(register t_main_42sh *array,
register unsigned char *b, register unsigned char *end)
{
	register size_t				tempos;
	register unsigned char		litter;
	register unsigned char		*tmp;

	tmp = end--;
	while (((litter = end[0]) & 0x40) == 0)
		end--;
	tempos = 0;
	while ((litter & 0x80) != 0)
	{
		litter = litter << 1;
		tempos++;
	}
	if (tempos == (size_t)(tmp - end))
	{
		ft_42sh_str_add(array, (void *)b, (void *)tmp, 1);
		array->litter_save[0] = 0;
		return ;
	}
	ft_42sh_str_add(array, (void *)b, (void *)end, 1);
	array->litter_save[0] = 0;
	tempos = sizeof(array->litter_save) - (tmp - end);
	tmp = (void *)array->litter_save;
	while (tempos < sizeof(array->litter_save))
		tmp[tempos++] = end++[0];
}

static unsigned char	*fn_b(register t_main_42sh *array,
register unsigned char *b, register size_t count)
{
	register unsigned char		litter;

	if (array->litter_save[0] == 0)
	{
		if ((litter = b[0]) == '\x1b' || litter == 0x7F ||
		(count == 1 && litter < 0x20))
			return (0);
		else
			return (b);
	}
	b = (void *)array->litter_save;
	while (b[0] == 0)
		b++;
	return (b);
}

size_t					ft_42sh_str_test_read(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b, register size_t count)
{
	register unsigned char		*end;

	if (b == (end = b + count))
		return (1);
	if ((b = fn_b(array, b, count)) == 0)
		return (0);
	if (count < sizeof(array->litter) || (end[-1] & 0x80) == 0)
	{
		ft_42sh_str_add(array, (void *)b, (void *)end, 1);
		array->litter_save[0] = 0;
		return (1);
	}
	fn_test_save(array, b, end);
	return (1);
	(void)list;
}
