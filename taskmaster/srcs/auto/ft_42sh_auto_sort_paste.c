/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_sort_paste.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_auto.h"

static void				*fn_paste(register t_main_42sh *array,
register t_past_sort_42sh *root, register t_std_key_42sh *cur,
register char *lp_key)
{
	register void					*tmp;
	register t_std_key_42sh			*list;

	list = (void *)ft_42sh_auto_list_create(array, lp_key, 0);
	if (cur->prev == 0)
	{
		root->first = list;
		list->prev = 0;
		cur->prev = list;
		list->next = cur;
	}
	else
	{
		tmp = cur->prev;
		((t_std_key_42sh *)tmp)->next = list;
		list->next = cur;
		list->prev = tmp;
		cur->prev = list;
	}
	return (list);
}

static void				*fn_last(register t_main_42sh *array,
register char *lp_key, register void *str, uint_fast8_t b_type)
{
	register t_std_key_42sh		*list;
	register t_std_key_42sh		*last;
	register t_past_sort_42sh	*root;

	root = &array->lp_auto->all_cmd;
	list = (void *)ft_42sh_auto_list_create(array, lp_key, 0);
	last = root->last;
	root->last = list;
	last->next = list;
	list->prev = last;
	ft_42sh_auto_list_add(array, (void *)list, str, b_type);
	return (list);
}

static void				*fn_first(register t_main_42sh *array,
register char *lp_key, register void *str, uint_fast8_t b_type)
{
	register t_all_cmd_42sh		*list;
	register t_past_sort_42sh	*root;

	root = &array->lp_auto->all_cmd;
	list = (void *)ft_42sh_auto_list_create(array, lp_key, 0);
	list->std.next = 0;
	list->std.prev = 0;
	root->first = list;
	root->center = list;
	root->last = list;
	ft_42sh_auto_list_add(array, (void *)list, str, b_type);
	return (list);
}

static t_std_key_42sh	*fn_pre(register t_past_sort_42sh *root,
register char *lp_key, register size_t n)
{
	register t_std_key_42sh		*cur;
	register size_t				count;
	register ssize_t			tempos;

	cur = root->center;
	count = cur->key_count;
	count = count > n ? n : count;
	if ((tempos = ft_strncmp(cur->lp_key, lp_key, count)) > 0 ||
	(tempos == 0 && cur->key_count > n))
		cur = root->first;
	return (cur);
}

void					*ft_42sh_auto_sort_paste(register t_main_42sh *array,
register char *lp_key, register void *str, uint_fast8_t b_type)
{
	register t_std_key_42sh		*cur;
	register ssize_t			tempos;
	register size_t				count;
	register size_t				n;

	if (array->lp_auto->all_cmd.first == 0)
		return (fn_first(array, lp_key, str, b_type));
	n = ft_strlen(lp_key);
	cur = fn_pre(&array->lp_auto->all_cmd, lp_key, n);
	while (cur != 0)
	{
		count = cur->key_count;
		count = count > n ? n : count;
		if ((tempos = ft_strncmp(cur->lp_key, lp_key, count)) > 0 ||
		(tempos == 0 && cur->key_count > n))
		{
			return (ft_42sh_auto_list_add(array, (void *)fn_paste(array,
			&array->lp_auto->all_cmd, cur, lp_key), str, b_type));
		}
		else if (tempos == 0 && cur->key_count == n)
			return (ft_42sh_auto_list_add(array, (void *)cur, str, b_type));
		cur = cur->next;
	}
	return (fn_last(array, lp_key, str, b_type));
}
