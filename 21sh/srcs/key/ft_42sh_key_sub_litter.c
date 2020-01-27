/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_sub_litter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void				ft_42sh_key_backspace(register t_main_42sh *array,
register t_in_42sh *list)
{
	register char		*current;
	register char		*offset;
	register char		litter;

	if (list->lp_b == (current = list->lp_current))
		return ;
	offset = current;
	while (((litter = offset--[-1]) & 0x80) != 0 && (litter & 0x40) == 0)
		;
	if (litter == '\n')
		ft_42sh_str_delete(array, list, offset - 1, 0);
	else
		ft_42sh_str_delete(array, list, offset, 1);
}

void				ft_42sh_key_delete(register t_main_42sh *array,
register t_in_42sh *list)
{
	register char		*current;
	register char		*end;
	register char		*offset;
	register char		litter;

	end = list->lp_b + list->count;
	if (end == (current = list->lp_current))
		return ;
	offset = current;
	if (((litter = offset++[0]) & 0x80) != 0)
		while (((litter = litter << 1) & 0x80) != 0)
			offset++;
	if (end != offset && offset[0] == '\n')
		ft_42sh_str_delete(array, list, offset + 1, 0);
	else
		ft_42sh_str_delete(array, list, offset, 1);
}
