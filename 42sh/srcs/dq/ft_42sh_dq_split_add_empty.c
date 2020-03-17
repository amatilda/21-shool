/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_dq.h"

static t_slesh_42sh	*fn_set_spl(register size_t n, register size_t count)
{
	register t_slesh_42sh		*spl_slesh;

	if ((spl_slesh = ft_malloc(sizeof(t_slesh_42sh))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	spl_slesh->count = n;
	spl_slesh->count_litter = count;
	return (spl_slesh);
}

static void			fn_correction_finish(register t_slesh_42sh **lp_out,
register char *e, register char *current)
{
	register char				litter;
	register char				*tmp;
	register size_t				tempos;

	tempos = 0;
	tmp = current;
	while (current < e && (litter = current[0]) != '\n')
	{
		tempos++;
		current++;
		if ((litter & 0x80) != 0)
			while (((litter << 1) & 0x80) != 0)
				current++;
	}
	if (current < e)
	{
		current--;
		tempos--;
	}
	lp_out[0] = fn_set_spl(current - tmp, tempos);
}

static void			fn_correction(register t_slesh_42sh **lp_out,
register char *b, register char *e, register char *current)
{
	register char				litter;
	register char				*tmp;
	register size_t				tempos;

	tempos = 0;
	tmp = current - 3;
	while (tmp >= b && tmp[0] != '\n')
	{
		tempos++;
		while (((litter = tmp--[0]) & 0x80) != 0 && (litter & 0x40) == 0)
			;
	}
	lp_out[-1]->count = (current - 3) - tmp;
	lp_out[-1]->count_litter = tempos;
	fn_correction_finish(lp_out, e, current);
}

void				ft_42sh_dq_split_add_empty(register t_in_42sh *list,
register t_slesh_42sh **spl_slesh)
{
	register t_slesh_42sh	**lp_out;
	register size_t			slesh_current;
	register size_t			slesh_max;
	register char			*b;

	slesh_current = ++list->slesh_current * sizeof(t_slesh_42sh **);
	slesh_max = ++list->slesh_max * sizeof(t_slesh_42sh **)
	+ sizeof(t_slesh_42sh **);
	if ((lp_out = ft_malloc(slesh_max + sizeof(t_slesh_42sh **))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	list->spl_slesh = lp_out;
	ft_memcpy(lp_out, spl_slesh, slesh_current);
	lp_out = (t_slesh_42sh **)((char *)lp_out + slesh_current);
	ft_memcpy(lp_out + 1, ((char *)spl_slesh + slesh_current),
	slesh_max - slesh_current);
	ft_free(spl_slesh);
	b = list->lp_b;
	fn_correction(lp_out, b, b + list->count, list->lp_current);
}
