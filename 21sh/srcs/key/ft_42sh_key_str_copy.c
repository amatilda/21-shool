/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_str_copy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static size_t	fn_slesh_pre(register t_in_42sh *list,
register t_slesh_42sh **spl_slesh)
{
	register t_slesh_42sh		**spl_tmp;
	register size_t				count;

	spl_tmp = list->spl_slesh;
	count = 0;
	while (spl_tmp < spl_slesh)
		count += spl_tmp++[0]->count + 2;
	count += spl_slesh[0]->count;
	return (spl_slesh[0]->count - (count - (list->lp_current - list->lp_b)));
}

static void		fn_save(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b, register size_t count)
{
	register void				*out;

	if ((out = ft_malloc(count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_memcpy(out, b, count);
	ft_42sh_dsp_clear_select(array, list);
	array->slc.lp_clipboard = out;
	array->slc.clipboard_count = count;
}

static size_t	fn_test(register t_main_42sh *array,
register t_in_42sh *list)
{
	register unsigned char		*b;
	register size_t				count;

	if ((b = array->slc.lp_clipboard) != 0)
	{
		array->slc.lp_clipboard = 0;
		ft_free(b);
		return (0);
	}
	if ((count = list->count) == 0)
		return (0);
	return (count);
}

void			ft_42sh_key_str_copy(register t_main_42sh *array,
register t_in_42sh *list)
{
	register unsigned char		*b;
	register t_slesh_42sh		**spl;
	register size_t				count;

	if ((count = fn_test(array, list)) == 0)
		return ;
	if ((b = array->slc.b) == 0)
	{
		if ((spl = list->spl_slesh) != 0)
		{
			b = (void *)list->lp_current;
			spl = &spl[list->slesh_current];
			if ((count = spl[0]->count) == 0)
				return (ft_42sh_dsp_clear_select(array, list));
			if ((list->lp_b != (char *)b && b[-1] != '\n'))
				b -= fn_slesh_pre(list, spl);
		}
		else
			b = (void *)list->lp_b;
	}
	else
		count = array->slc.e - b;
	fn_save(array, list, b, count);
}
