/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_str_paste_cut.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_42sh_key_str_paste(register t_main_42sh *array,
register t_in_42sh *list)
{
	register char			*b;

	if ((b = array->slc.lp_clipboard) != 0)
	{
		if (array->slc.b != 0)
			ft_42sh_key_str_delete(array, list);
		return (ft_42sh_str_add(array, b, b + array->slc.clipboard_count, 2));
	}
	if (list->count == 0)
		return ;
	ft_42sh_key_str_copy(array, list);
	if ((b = array->slc.lp_clipboard) != 0)
		ft_42sh_str_add(array, b, b + array->slc.clipboard_count, 2);
}

static void		fn_save(register t_main_42sh *array,
register t_in_42sh *list, register char *e)
{
	register char				*current;
	register char				*b;
	register size_t				count;

	if ((current = list->lp_current) > e)
	{
		b = e;
		e = current;
	}
	else
		b = current;
	if ((current = array->slc.lp_clipboard) != 0)
		ft_free(current);
	count = e - b;
	if ((array->slc.lp_clipboard = ft_strndup(b, count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	array->slc.clipboard_count = count;
}

static void		fn_find_str(register t_main_42sh *array,
register t_in_42sh *list)
{
	register unsigned char		*b;
	register t_slesh_42sh		**spl;

	if ((spl = list->spl_slesh) != 0)
	{
		b = (void *)list->lp_current;
		spl = &spl[list->slesh_current];
		if (spl[0]->count == 0 || (list->lp_b != (char *)b && b[-1] != '\n'))
		{
			ft_42sh_key_home(array, list);
			spl = &list->spl_slesh[list->slesh_current];
		}
		b = (void *)(list->lp_current + spl[0]->count +
		(list->slesh_current != list->slesh_max ? 2 : 0));
		fn_save(array, list, (void *)b);
		return (ft_42sh_str_delete(array, list, (void *)b,
		spl[0]->count_litter));
	}
	ft_42sh_key_home(array, list);
	fn_save(array, list, list->lp_b + list->count);
	ft_write_buffer_str_zero(&array->out, "\x1b[J");
	return (ft_42sh_list_in_default(array, list));
}

void			ft_42sh_key_str_cut(register t_main_42sh *array,
register t_in_42sh *list)
{
	register unsigned char		*b;

	if (list->count == 0)
		return ;
	ft_42sh_list_in_dup(list);
	if ((b = array->slc.b) == 0)
		return (fn_find_str(array, list));
	if (list->lp_current == (char *)b)
		b = array->slc.e;
	fn_save(array, list, (void *)b);
	ft_42sh_str_delete(array, list, (void *)b, array->slc.count_litter);
	array->slc.b = 0;
}
