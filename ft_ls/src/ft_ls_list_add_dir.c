/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_list_add_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	fn_stub20(register t_list_dir *list,
	register t_fl_ls_list_dir *dir)
{
	register void			*tmp;

	tmp = (char *)dir->last;
	dir->last = list;
	((t_list_dir *)tmp)->next = list;
	list->next = 0;
	list->prev = (t_list_dir *)tmp;
	return (1);
}

static int	fn_stub10(register t_list_dir *list,
	register t_fl_ls_list_dir *dir)
{
	dir->first = list;
	dir->center = list;
	dir->last = list;
	list->next = 0;
	list->prev = 0;
	return (1);
}

static int	fn_stub00(register t_main *array, register t_list_dir *list,
	register t_fl_ls_list_dir *dir, register char *name)
{
	if ((list->name = ft_strdup(name)) == 0)
	{
		free(list);
		return (0);
	}
	dir->count++;
	list->st_timespec.tv_sec = array->st_timespec->tv_sec;
	list->st_timespec.tv_nsec = array->st_timespec->tv_nsec;
	list->size_file = array->stat_info.st_size;
	return (1);
}

int			ft_ls_list_add_dir(register t_main *array,
	register t_fl_ls_list_dir *dir, char *name)
{
	register t_list_dir		*list;
	register char			*option;
	register void			*tmp;

	if ((list = malloc(sizeof(t_list_dir))) == 0 ||
		fn_stub00(array, list, dir, name) == 0)
		return (0);
	if (dir->first == 0)
		return (fn_stub10(list, dir));
	option = array->option;
	if (option[FLAG_NOT_SORT] == 0)
	{
		if (option[FLAG_SORT_SIZE] != 0)
			tmp = (char *)ft_ls_strcmp_size;
		else if (option[FLAG_LAST_MODIF] != 0)
			tmp = (char *)ft_ls_strcmp_last_modif;
		else
			tmp = (char *)ft_ls_strcmp_name;
		return (ft_ls_sort(array, (char *)dir, (char *)list, tmp));
	}
	return (fn_stub20(list, dir));
}
