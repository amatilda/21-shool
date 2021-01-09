/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_str_delete.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_delete_str(register t_main_42sh *array,
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
		return (ft_42sh_str_delete(array, list, list->lp_current +
		spl[0]->count + (list->slesh_current != list->slesh_max ? 2 : 0),
		spl[0]->count_litter));
	}
	ft_42sh_key_home(array, list);
	ft_write_buffer_str_zero(&array->out, "\x1b[J");
	return (ft_42sh_list_in_default(array, list));
}

void			ft_42sh_key_str_delete(register t_main_42sh *array,
register t_in_42sh *list)
{
	register unsigned char		*b;

	if (list->count == 0)
		return ;
	ft_42sh_list_in_dup(list);
	if ((b = array->slc.b) == 0)
		return (fn_delete_str(array, list));
	if (list->lp_current == (char *)b)
		b = array->slc.e;
	ft_42sh_str_delete(array, list, (void *)b, array->slc.count_litter);
	array->slc.b = 0;
}
