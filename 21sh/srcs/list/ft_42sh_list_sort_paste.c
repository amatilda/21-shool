/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_sort_paste.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static int		fn_free(register t_std_key_42sh *list,
void (*f_free)(register void *))
{
	f_free(list);
	return (0);
}

static int		fn_add_center(register t_past_sort_42sh *root,
register t_std_key_42sh *center, register t_std_key_42sh *list)
{
	register void		*tmp;

	if (center->prev == 0)
	{
		root->first = list;
		list->prev = 0;
		center->prev = list;
		list->next = center;
	}
	else
	{
		tmp = center->prev;
		((t_std_key_42sh *)tmp)->next = list;
		list->next = center;
		list->prev = tmp;
		center->prev = list;
	}
	return (1);
}

int				ft_42sh_list_sort_paste(register t_past_sort_42sh *root,
register t_std_key_42sh *list, void (*f_free)(register void *))
{
	register void				*tmp;
	register t_std_key_42sh		*center;
	register ssize_t			tempos;

	center = root->center;
	tmp = list->lp_key;
	if ((tempos = ft_strcmp(center->lp_key, tmp)) > 0)
		center = root->first;
	else if (tempos == 0)
		return (fn_free(list, f_free));
	while (center != 0)
	{
		if ((tempos = ft_strcmp(center->lp_key, tmp)) > 0)
			return (fn_add_center(root, center, list));
		else if (tempos == 0)
			return (fn_free(list, f_free));
		center = center->next;
	}
	tmp = root->last;
	root->last = list;
	list->next = 0;
	((t_std_key_42sh *)tmp)->next = list;
	list->prev = tmp;
	return (1);
}
