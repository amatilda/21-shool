/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_alias_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:07:32 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:07:38 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_alias.h"

void		ft_42sh_alias_free(register t_main_42sh *array)
{
	t_pguitar_alias_42sh		*list;
	t_pguitar_alias_42sh		*tmp;

	if (array->pguitar.f_modif.home != 0)
	{
		ft_free(array->pguitar.f_modif.home);
		array->pguitar.f_modif.home = 0;
	}
	list = array->pguitar.list;
	while (list != 0)
	{
		tmp = list;
		list = list->next;
		ft_free(tmp);
	}
	array->pguitar.list = 0;
}
