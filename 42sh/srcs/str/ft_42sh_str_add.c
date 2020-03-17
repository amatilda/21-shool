/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_str_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static char				*fn_set(register t_main_42sh *array,
register t_add_litter_42sh *in, register char *tmp, register char *str)
{
	in->count = str - tmp - in->correction;
	in->count_litter -= in->correction;
	ft_42sh_str(array, array->in.in_current, (void *)tmp, in);
	in->count = 2;
	in->count_litter = 0;
	ft_42sh_str(array, array->in.in_current, (void *)" \n", in);
	return (str);
}

static char				*fn_set_other(register t_main_42sh *array,
register t_add_litter_42sh *in, register char *tmp, register char *str)
{
	in->count = str - tmp - 1;
	in->count_litter -= 1;
	ft_42sh_str(array, array->in.in_current, (void *)tmp, in);
	in->count_litter = 0;
	return (str);
}

void					ft_42sh_str_add(register t_main_42sh *array,
register char *str, register char *end, uint_fast8_t correction)
{
	register char				*tmp;
	register unsigned char		litter;
	t_add_litter_42sh			in;

	tmp = str;
	in.count_litter = 0;
	in.correction = correction;
	while (str < end)
	{
		in.count_litter++;
		if (((litter = str++[0])) == '\n')
			tmp = fn_set(array, &in, tmp, str);
		else if (litter < 0x20)
			tmp = fn_set_other(array, &in, tmp, str);
		else if ((litter & 0x80) != 0)
			while (((litter = litter << 1) & 0x80) != 0)
				str++;
	}
	in.count = str - tmp;
	ft_42sh_str(array, array->in.in_current, (void *)tmp, &in);
}
