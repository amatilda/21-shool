/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort_strcmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static ssize_t	fn_stub_00(register char *root, register char *center,
	register char *list)
{
	register char		*tmp;

	if (((t_list_invalid *)center)->prev == 0)
	{
		((t_fl_ls_list_invalid *)root)->first = (t_list_invalid *)list;
		((t_list_invalid *)list)->prev = 0;
		((t_list_invalid *)center)->prev = (t_list_invalid *)list;
		((t_list_invalid *)list)->next = (t_list_invalid *)center;
	}
	else
	{
		tmp = (char *)((t_list_invalid *)center)->prev;
		((t_list_invalid *)tmp)->next = (t_list_invalid *)list;
		((t_list_invalid *)list)->next = (t_list_invalid *)center;
		((t_list_invalid *)list)->prev = (t_list_invalid *)tmp;
		((t_list_invalid *)center)->prev = (t_list_invalid *)list;
	}
	return (1);
}

ssize_t			ft_ls_strcmp_name(register t_main *array,
	register char *curent, register char *list)
{
	register ssize_t		out;

	out = ft_strcmp(((t_list_invalid *)curent)->name,
		((t_list_invalid *)list)->name);
	if (array->option[FLAG_REVERSE] != 0)
		out = ~out + 1;
	return (out);
}

ssize_t			ft_ls_strcmp_size(register t_main *array,
	register char *curent, register char *list)
{
	register ssize_t		out;

	out = ((t_list_file *)list)->size_file -
	((t_list_file *)curent)->size_file;
	if (out == 0)
		return (ft_ls_strcmp_name(array, curent, list));
	if (array->option[FLAG_REVERSE] != 0)
		out = ~out + 1;
	return (out);
}

ssize_t			ft_ls_strcmp_last_modif(register t_main *array,
	register char *curent, register char *list)
{
	register ssize_t		out;

	out = ((t_list_file *)list)->st_timespec.tv_sec -
	((t_list_file *)curent)->st_timespec.tv_sec;
	if (out == 0)
		out = ((t_list_file *)list)->st_timespec.tv_nsec -
	((t_list_file *)curent)->st_timespec.tv_nsec;
	if (out == 0)
		return (ft_ls_strcmp_name(array, curent, list));
	if (array->option[FLAG_REVERSE] != 0)
		out = ~out + 1;
	return (out);
}

ssize_t			ft_ls_sort(register t_main *array, register char *root,
	register char *list,
	ssize_t (*cmp)(register t_main *, register char *, register char *))
{
	register char		*tmp;
	register char		*center;

	center = (char *)((t_fl_ls_list_invalid *)root)->center;
	tmp = (char *)((t_list_invalid *)list)->name;
	if (cmp(array, center, list) > 0)
		center = (char *)((t_fl_ls_list_invalid *)root)->first;
	while (center != 0)
	{
		if (cmp(array, center, list) > 0)
			return (fn_stub_00(root, center, list));
		center = (char *)((t_list_invalid *)center)->next;
	}
	tmp = (char *)((t_fl_ls_list_invalid *)root)->last;
	((t_fl_ls_list_invalid *)root)->last = (t_list_invalid *)list;
	((t_list_invalid *)list)->next = 0;
	((t_list_invalid *)tmp)->next = (t_list_invalid *)list;
	((t_list_invalid *)list)->prev = (t_list_invalid *)tmp;
	return (1);
}
