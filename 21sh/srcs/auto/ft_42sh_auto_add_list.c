/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_add_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static t_all_cmd_42sh	*fn_list_create(register t_main_42sh *array,
register char *key, register char add_litter)
{
	register size_t				key_count;
	register size_t				key_litter;
	register t_all_cmd_42sh		*out;
	register char				lit;

	key_count = 0;
	key_litter = 0;
	while ((lit = key[key_count++]) != 0)
	{
		key_litter++;
		if ((lit & 0x80) != 0)
			while (((lit = key[key_count]) & 0x80) != 0 && (lit & 0x40) == 0)
				key_count++;
	}
	if ((out = ft_malloc(sizeof(t_all_cmd_42sh) + key_count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	out->std.key_count = key_count - 1;
	out->std.lp_key = out->key;
	out->key_litter = key_litter;
	out->add_litter = add_litter;
	key_litter += add_litter != 0 ? 1 : 0;
	array->lp_auto->max_litter = key_litter > array->lp_auto->max_litter ?
	key_litter : array->lp_auto->max_litter;
	ft_memcpy(out->key, key, key_count);
	return (out);
}

void					*ft_42sh_auto_add_list(register t_main_42sh *array,
register char *lp_key, char add_litter)
{
	register t_past_sort_42sh	*root;
	register size_t				tempos;
	register t_all_cmd_42sh		*list;

	root = &array->lp_auto->all_cmd;
	list = fn_list_create(array, lp_key, add_litter);
	if (root->first == 0)
	{
		list->std.next = 0;
		list->std.prev = 0;
		root->first = list;
		root->center = list;
		root->last = list;
		tempos = 1;
	}
	else
		tempos = ft_42sh_list_sort_paste(root, &list->std, ft_free);
	if (tempos == 0)
		return (0);
	array->lp_auto->count_all++;
	return (list);
}
