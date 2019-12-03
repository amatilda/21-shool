/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_list_add_invalid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	fn_stub10(register t_list_invalid *list,
	register t_fl_ls_list_invalid *invalid)
{
	invalid->first = list;
	invalid->center = list;
	invalid->last = list;
	list->next = 0;
	list->prev = 0;
	return (1);
}

static int	fn_stub00(register t_list_invalid *list, register char *name)
{
	if ((list->name = ft_strdup(name)) == 0)
	{
		free(list);
		return (0);
	}
	list->errno_ = errno;
	return (1);
}

int			ft_ls_list_add_invalid(register t_main *array,
	register t_fl_ls_list_invalid *invalid, register char *name)
{
	register t_list_invalid		*list;
	register char				*tmp;

	if ((list = malloc(sizeof(t_list_invalid))) == 0 ||
		fn_stub00(list, name) == 0)
		return (0);
	if (invalid->first == 0)
		return (fn_stub10(list, invalid));
	if (array->option[FLAG_NOT_SORT] == 0)
	{
		return (ft_ls_sort(array, (char *)invalid,
			(char *)list, ft_ls_strcmp_invalid));
	}
	tmp = (char *)invalid->last;
	invalid->last = list;
	((t_list_invalid *)tmp)->next = list;
	list->next = 0;
	list->prev = (t_list_invalid *)tmp;
	return (1);
}
