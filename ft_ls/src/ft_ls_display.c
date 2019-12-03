/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_ls_display_reverse(register t_main *array,
	register char *list_name)
{
	register char			*tmp;

	fn_copy_str_zero_invalid(array, "\n");
	fn_copy_str_zero_invalid(array, list_name);
	fn_copy_str_zero_invalid(array, ":\n");
	fn_copy_str_zero_invalid(array, NAME_PROG": ");
	tmp = list_name;
	while (tmp[0] != 0)
		tmp++;
	while (tmp[0] != '/' && tmp != list_name)
		tmp--;
	if (tmp[0] == '/')
		tmp++;
	fn_copy_str_zero_invalid(array, tmp);
	fn_copy_str_zero_invalid(array, ": ");
	fn_copy_str_zero_invalid(array, strerror(errno));
	fn_copy_str_zero_invalid(array, "\n");
	if (array->count_invalid != 0)
	{
		write(2, array->b_invalid, array->count_invalid);
		array->count_invalid = 0;
	}
}

static void		fn_display_invalid(register t_main *array,
	t_fl_ls_list_invalid *invalid)
{
	register t_list_invalid		*tmp;
	register t_list_invalid		*list;

	list = invalid->first;
	while (list != 0)
	{
		tmp = list;
		fn_copy_str_zero_invalid(array, NAME_PROG": ");
		fn_copy_str_zero_invalid(array, list->name);
		fn_copy_str_zero_invalid(array, ": ");
		fn_copy_str_zero_invalid(array, strerror(list->errno_));
		fn_copy_str_zero_invalid(array, "\n");
		list = list->next;
		free(tmp);
	}
}

static void		fn_display_finish(register t_main *array,
	t_fl_ls_list_invalid *invalid, t_fl_ls_list_file *file)
{
	register size_t			tmp;

	if ((tmp = array->count_invalid) != 0)
	{
		write(2, array->b_invalid, tmp);
		array->count_invalid = 0;
	}
	if ((tmp = array->count) != 0)
	{
		write(1, array->b, tmp);
		array->count = 0;
	}
	file->first = 0;
	invalid->first = 0;
}

static void		fn_stub00(register t_main *array, register t_list_file *list,
	register char litter, register char *opt)
{
	register size_t			tempos;

	fn_copy_str_zero(array, list->name);
	if (opt[FLAG_F] == 0)
		return ;
	if ((tempos = list->st_mode_type) == S_IFDIR)
		litter = '/';
	else if (tempos == S_IFLNK)
		litter = '@';
	else if (tempos == S_IFSOCK)
		litter = '=';
	else if (tempos == S_IFIFO)
		litter = '|';
	else if (tempos == S_IFCHR)
		litter = '%';
	else if (tempos == S_IFBLK)
		litter = '%';
	else if (tempos == S_IFREG)
	{
		tempos = list->st_mode;
		tempos = (tempos & S_IXUSR) | (tempos & S_IXGRP) | (tempos & S_IXOTH);
		litter = tempos != 0 ? '*' : litter;
	}
	if (litter != 0)
		fn_dub_char(array, litter, 1);
}

void			ft_ls_display(register t_main *array,
	t_fl_ls_list_invalid *invalid, t_fl_ls_list_file *file,
	uint_fast8_t b_level)
{
	register t_list_file	*tmp;
	register t_list_file	*list;
	register char			*opt;

	fn_display_invalid(array, invalid);
	list = file->first;
	if ((opt = array->option)[FLAG_INFO_FULL] != 0)
		fn_display_info_full(array, file, list, b_level);
	else
	{
		while (list != 0)
		{
			fn_stub00(array, list, 0, opt);
			if (opt[FLAG_DIR_SLECH] != 0 && list->st_mode_type == S_IFDIR)
				fn_dub_char(array, '/', 1);
			fn_dub_char(array, '\n', 1);
			tmp = list;
			free(list->name);
			if (list->patch != 0)
				free(list->patch);
			list = list->next;
			free(tmp);
		}
	}
	fn_display_finish(array, invalid, file);
}
