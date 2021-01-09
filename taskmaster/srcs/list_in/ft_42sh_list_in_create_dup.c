/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_create_dup.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_in_42sh		*ft_42sh_list_in_create_dup(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_in_42sh	*new;
	register char		*lp_b;

	if ((new = ft_malloc(sizeof(t_in_42sh))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	ft_memcpy(new, list, sizeof(t_in_42sh));
	if ((lp_b = ft_malloc(list->max)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	ft_memcpy(lp_b, list->lp_b, list->max);
	new->lp_b = lp_b;
	new->lp_current = lp_b + (list->lp_current - list->lp_b);
	new->max_dup = 0;
	array->in.in_count++;
	return (new);
}

t_in_42sh		*ft_42sh_list_in_create_dup_full(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_in_42sh	*new;

	new = ft_42sh_list_in_create_dup(array, list);
	new->spl_slesh = ft_42sh_dq_split_dup(new->spl_slesh, new->slesh_max + 1);
	return (new);
}
