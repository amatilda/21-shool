/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_list_add_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	fn_stub20(register t_main *array, register t_list_file *list,
	register t_fl_ls_list_file *file)
{
	register void				*tmp;
	register char				*option;

	option = array->option;
	if (option[FLAG_NOT_SORT] == 0)
	{
		if (option[FLAG_SORT_SIZE] != 0)
			tmp = (char *)ft_ls_strcmp_size;
		else if (option[FLAG_LAST_MODIF] != 0)
			tmp = (char *)ft_ls_strcmp_last_modif;
		else
			tmp = (char *)ft_ls_strcmp_name;
		return (ft_ls_sort(array, (char *)file, (char *)list, tmp));
	}
	tmp = (char *)file->last;
	file->last = list;
	((t_list_file *)tmp)->next = list;
	list->next = 0;
	list->prev = (t_list_file *)tmp;
	return (1);
}

static int	fn_stub11(register t_main *array, register t_list_file *list,
	register t_fl_ls_list_file *file, register void *tmp)
{
	register size_t				tempos;

	file->st_blocks += array->stat_info.st_blocks;
	list->st_rdev = array->stat_info.st_rdev;
	if (array->stat_info.st_size > file->max_size)
		file->max_size = array->stat_info.st_size;
	if (array->option[FLAG_ONLY_USER] == 0 &&
	(tmp = (char *)getgrgid(array->stat_info.st_gid)) != 0)
	{
		tempos = ft_strlen(((struct group *)tmp)->gr_name);
		if ((list->gr_name =
			ft_strndup(((struct group *)tmp)->gr_name, tempos)) == 0)
		{
			free(list->name);
			if (list->patch != 0)
				free(list->patch);
			if (list->pw_name != 0)
				free(list->pw_name);
			free(list);
			return (0);
		}
		if (file->max_gr_name < (list->gr_size = tempos))
			file->max_gr_name = tempos;
	}
	return (1);
}

static int	fn_stub10(register t_main *array, register t_list_file *list,
	register t_fl_ls_list_file *file, register void *tmp)
{
	register size_t				tempos;

	tempos = array->stat_info.st_nlink;
	if ((list->st_nlink = tempos) > file->max_nlink)
		file->max_nlink = tempos;
	if (array->option[FLAG_ONLY_GROOP] == 0 &&
	(tmp = (char *)getpwuid(array->stat_info.st_uid)) != 0)
	{
		tempos = ft_strlen(((struct passwd *)tmp)->pw_name);
		if ((list->pw_name =
			ft_strndup(((struct passwd *)tmp)->pw_name, tempos)) == 0)
		{
			free(list->name);
			if (list->patch != 0)
				free(list->patch);
			free(list);
			return (0);
		}
		if (file->max_pw_name < (list->pw_size = tempos))
			file->max_pw_name = tempos;
	}
	return (fn_stub11(array, list, file, tmp));
}

static int	fn_stub00(register t_main *array, register t_list_file *list,
	register char *name)
{
	register size_t			tempos;

	tempos = ft_strlen(name);
	if ((list->name = ft_strndup(name, tempos)) == 0)
	{
		free(list);
		return (0);
	}
	array->count_list++;
	array->max_len = array->max_len < tempos ? tempos : array->max_len;
	list->len = tempos;
	list->patch = array->join;
	list->pw_name = 0;
	list->gr_name = 0;
	list->st_timespec.tv_sec = array->st_timespec->tv_sec;
	list->st_timespec.tv_nsec = array->st_timespec->tv_nsec;
	list->size_file = array->stat_info.st_size;
	list->st_mode = array->stat_info.st_mode;
	list->st_mode_type = array->stat_info.st_mode & S_IFMT;
	array->join = 0;
	return (1);
}

int			ft_ls_list_add_file(register t_main *array,
	register t_fl_ls_list_file *file, char *name)
{
	register t_list_file		*list;

	if ((list = malloc(sizeof(t_list_file))) == 0 ||
		fn_stub00(array, list, name) == 0)
		return (0);
	if (array->option[FLAG_INFO_FULL] != 0 &&
		fn_stub10(array, list, file, 0) == 0)
		return (0);
	if (file->first == 0)
	{
		file->first = list;
		file->center = list;
		file->last = list;
		list->next = 0;
		list->prev = 0;
		return (1);
	}
	return (fn_stub20(array, list, file));
}
