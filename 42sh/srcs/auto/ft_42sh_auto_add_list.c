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

#include "includes/ft_42sh_auto.h"

static void				fn_set(register t_all_cmd_42sh *out,
register char add_litter)
{
	out->std.lp_key = out->key;
	out->add_litter = add_litter;
	out->count_cmd = 0;
	out->b_type = 0;
	out->std.next = 0;
	out->std.prev = 0;
}

t_all_cmd_42sh			*ft_42sh_auto_list_create(register t_main_42sh *array,
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
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	out->std.key_count = key_count - 1;
	out->std.key_litter = key_litter;
	fn_set(out, add_litter);
	key_litter += add_litter != 0 ? 1 : 0;
	array->lp_auto->max_litter = key_litter > array->lp_auto->max_litter ?
	key_litter : array->lp_auto->max_litter;
	ft_memcpy(out->key, key, key_count);
	array->lp_auto->count_all++;
	return (out);
}

void					*ft_42sh_auto_add_list(register t_main_42sh *array,
register char *lp_key, char add_litter)
{
	register t_past_sort_42sh	*root;
	register t_all_cmd_42sh		*list;
	register void				*tmp;

	tmp = ft_42sh_str_shield((void*)lp_key, (void*)lp_key +
	ft_strlen(lp_key), SHIELD_EXTERNALLY, 0);
	root = &array->lp_auto->all_cmd;
	list = ft_42sh_auto_list_create(array, tmp, add_litter);
	ft_free(tmp);
	if (root->first == 0)
	{
		root->first = list;
		root->center = list;
		root->last = list;
	}
	else if (ft_42sh_list_sort_paste(root, &list->std, ft_free) == 0)
		return (0);
	return (list);
}
