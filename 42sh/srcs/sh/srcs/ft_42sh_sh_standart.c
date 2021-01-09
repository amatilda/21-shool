/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_sh_standart.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_sh.h"

static void		fn_slesh(register t_in_42sh *list, unsigned char **out)
{
	register unsigned char			*tmp;

	tmp = *out;
	tmp[0] = ' ';
	tmp[1] = '\n';
	*out += 2;
	list->slesh_max++;
}

static void		fn_fail(register t_main_42sh *array)
{
	ft_42sh_sh_exit(ft_42sh_sh_exit_zero_crit(array,
	MSG_SH_UNKNOWN_42SH), STATUS_FALTURE_42SH);
}

static size_t	fn_count(unsigned char **out,
register unsigned char litter)
{
	register size_t					count;
	register unsigned char			*b;

	b = *out;
	count = 0;
	b[0] = litter;
	*out = *out + 1;
	while (((litter = litter << 1) & 0x80) != 0)
		count++;
	return (count);
}

void			ft_42sh_sh_standart(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b,
register unsigned char *e)
{
	register unsigned char	litter;
	unsigned char			*out;
	register size_t			count;

	out = (void *)list->lp_b;
	list->slesh_max = 0;
	while (b < e)
	{
		if ((litter = b++[0]) == '\n')
			fn_slesh(list, &out);
		else if ((litter & 0x80) != 0)
		{
			if ((count = fn_count(&out, litter)) > 3 || b + count > e)
				fn_fail(array);
			while (count-- != 0)
				out++[0] = b++[0];
		}
		else
			out++[0] = litter;
	}
	list->count = (char *)out - list->lp_b;
}
