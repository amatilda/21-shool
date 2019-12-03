/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42s_dq_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_slesh_42sh		**ft_42s_dq_split_dup(register t_slesh_42sh **spl,
register size_t n)
{
	register t_slesh_42sh		**lp_out;
	register t_slesh_42sh		*spl_slesh;
	register t_slesh_42sh		*tmp;

	if (spl == 0)
		return (0);
	if ((lp_out = malloc((n + 1) * sizeof(t_slesh_42sh **))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	while ((tmp = spl[0]) != 0)
	{
		if ((spl_slesh = malloc(sizeof(t_slesh_42sh))) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		spl_slesh->count = tmp->count;
		spl_slesh->count_litter = tmp->count_litter;
		lp_out++[0] = spl_slesh;
		spl++;
	}
	lp_out[0] = 0;
	lp_out -= n;
	return (lp_out);
}

static t_slesh_42sh	*fn_set_spl(register size_t n, register size_t count)
{
	register t_slesh_42sh		*spl_slesh;

	if ((spl_slesh = malloc(sizeof(t_slesh_42sh))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	spl_slesh->count = n;
	spl_slesh->count_litter = count;
	return (spl_slesh);
}

static void			fn_while(register t_slesh_42sh **lp_out, register char *b,
register char *end, register char *start)
{
	register char			litter;
	register size_t			count;

	while (b < end)
	{
		if (((litter = b++[0]) & 0x80) != 0)
			while (((litter = b[0]) & 0x80) != 0 && (litter & 0x40) == 0)
				b++;
		if (litter == '\n')
		{
			lp_out++[0] = fn_set_spl(b - start - 1 - 1, count - 1);
			count = 0;
			start = b;
		}
		else
			count++;
	}
	lp_out[0] = fn_set_spl(b - start, count);
}

void				ft_42s_dq_split(register t_in_42sh *list,
register size_t count)
{
	register t_slesh_42sh	**lp_out;
	register char			*b;

	if ((lp_out = malloc((count + 1 + 1) * sizeof(t_slesh_42sh **))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	lp_out[count + 1] = 0;
	list->spl_slesh = lp_out;
	b = list->lp_b;
	fn_while(lp_out, b, b + list->count, b);
}
