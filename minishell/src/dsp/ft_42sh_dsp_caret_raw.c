/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dsp_caret_raw.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static size_t	fn_str_left(register char *s, register size_t n)
{
	register char			litter;
	register char			*tmp;

	tmp = s;
	while (n-- != 0)
	{
		while (((litter = s--[-1]) & 0x80) != 0 && (litter & 0x40) == 0)
			;
	}
	return (tmp - s);
}

static size_t	fn_str_right(register char *s, register size_t n)
{
	register char			litter;
	register char			*tmp;

	tmp = s;
	while (n-- != 0)
	{
		if ((litter = s++[0] & 0x80) != 0)
		{
			while (((litter = s[0]) & 0x80) != 0 && (litter & 0x40) == 0)
				s++;
		}
	}
	return (s - tmp);
}

size_t			ft_42sh_dsp_caret_raw_up(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t			tempos;
	register size_t			i;
	register size_t			count;
	register t_slesh_42sh	**spl_slesh;

	if ((spl_slesh = list->spl_slesh) == 0)
		return (1);
	if ((i = list->slesh_current) == 0)
		return (1);
	tempos = 0;
	count = array->msg.pre_msg_litter;
	while (tempos <= i)
		count += spl_slesh[tempos++]->count_litter;
	count = spl_slesh[i]->count_litter - (count - list->count_litter_current);
	tempos = spl_slesh[i - 1]->count_litter;
	i = tempos;
	if (tempos > count)
		tempos = count;
	i = i - tempos + count;
	tempos = fn_str_left(list->lp_current, i + 1 + 1);
	ft_42sh_dsp_caret_left(array, list, i, tempos);
	return (0);
}

size_t			ft_42sh_dsp_caret_raw_down(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t			tempos;
	register size_t			i;
	register size_t			count;
	register t_slesh_42sh	**spl_slesh;

	if ((spl_slesh = list->spl_slesh) == 0)
		return (1);
	if ((i = list->slesh_current) == list->slesh_max)
		return (1);
	tempos = 0;
	count = array->msg.pre_msg_litter;
	while (tempos <= i)
		count += spl_slesh[tempos++]->count_litter;
	count -= list->count_litter_current;
	tempos = spl_slesh[i + 1]->count_litter;
	i = spl_slesh[i]->count_litter - count;
	if (tempos > i)
		tempos = i;
	count += tempos;
	tempos = fn_str_right(list->lp_current, count + 1 + 1);
	ft_42sh_dsp_caret_right(array, list, count, tempos);
	return (0);
}
