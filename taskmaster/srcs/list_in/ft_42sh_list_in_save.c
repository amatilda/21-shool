/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_save.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_list_in.h"

void					ft_42sh_list_in_free(register t_in_42sh *list)
{
	register void		**tmp;

	if ((tmp = (void **)list->spl_slesh) != 0)
		ft_strsplit_free((char **)tmp);
	if (list->max_dup != 0)
	{
		ft_free(list->lp_b_dup);
		if ((tmp = (void **)list->spl_slesh_dup) != 0)
			ft_strsplit_free((char **)tmp);
	}
	ft_free(list->lp_b);
	ft_free(list);
}

static void				*fn_alloc(register t_in_42sh *list, size_t i,
size_t max_dup)
{
	t_in_save_42sh				*b;
	size_t						count;

	count = sizeof(t_in_save_42sh);
	while (list != 0)
	{
		i++;
		count += sizeof(t_in_42sh) + list->max;
		if (list->spl_slesh != 0)
			count += (sizeof(t_slesh_42sh) * (list->slesh_max + 1));
		if ((max_dup = list->max_dup) != 0)
		{
			count += max_dup;
			if (list->spl_slesh_dup != 0)
				count += (sizeof(t_slesh_42sh) * (list->slesh_max_dup + 1));
		}
		list = list->next;
	}
	if ((b = malloc(count)) == 0)
		return (0);
	ft_memset(b, 0xFF, count);
	b->i = i;
	b->len = count;
	return (b);
}

void					ft_42sh_list_in_free_all_save(register
t_main_42sh *array)
{
	uint8_t					*b;
	register t_in_42sh		*list;

	list = array->in.in_first;
	if (list == array->in.in_last && list->count == 0)
		return (ft_42sh_list_in_free_all(array));
	b = fn_alloc(list, 0, 0);
	if (b == 0)
		return (ft_42sh_list_in_free_all(array));
	ft_42sh_list_in_save_copy_buffer(b, list, array);
	array->in.in_first = 0;
	ft_42sh_list_in_save_file((t_in_save_42sh *)b);
}

void					ft_42sh_list_in_free_all(register t_main_42sh *array)
{
	register t_in_42sh		*list;
	register t_in_42sh		*tmp;

	list = array->in.in_first;
	while (list != 0)
	{
		tmp = list;
		list = list->next;
		ft_42sh_list_in_free(tmp);
	}
	array->in.in_first = 0;
}
