/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/10/07 19:05:28 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*fn_strjoin(register char const *s1, register char const *s2)
{
	register char	*out;
	register size_t	count;
	register size_t	size;

	size = 0;
	while (s1[size] != 0)
		size++;
	count = 0;
	while (s2[count] != 0)
		count++;
	size += count;
	if ((out = malloc(size + 2)) == 0)
		return (0);
	size = (size_t)out;
	while ((count = (unsigned char)s1++[0]) != 0)
		out++[0] = (unsigned char)count;
	out++[0] = '/';
	while ((count = (unsigned char)s2++[0]) != 0)
		out++[0] = (unsigned char)count;
	out[0] = 0;
	return ((char *)size);
}

static int	fn_add_list_while_cmp(register char *name, char *opt)
{
	if (opt[FLAG_SYSTEM] != 0 || name[0] != '.' || (opt[FLAG_A] != 0
				&& name[0] == '.' && name[1] != '.' && name[1] != 0))
		return (1);
	return (0);
}

static int	fn_add_list_while(register t_main *array, register char *list_name,
	DIR *dirp, register char *name)
{
	char			*opt;

	opt = array->option;
	while ((array->dp = readdir(dirp)) != 0)
	{
		if (fn_add_list_while_cmp((name = array->dp->d_name), opt) != 0)
		{
			if ((array->join = fn_strjoin(list_name, name)) == 0)
				return (0);
			if (lstat(array->join, &array->stat_info) == 0)
			{
				if (((array->stat_info.st_mode & S_IFMT) == S_IFDIR &&
					opt[FLAG_RECURS] != 0 && (name[0] != '.' ||
					(name[0] == '.' && name[1] != '.' && name[1] != 0)) &&
					ft_ls_list_add_dir(array, array->dir_new, array->join) == 0)
					|| (ft_ls_list_add_file(array, array->file_new, name) == 0))
					return (0);
			}
			else if (ft_ls_list_add_invalid(array, array->inv_new, name) == 0)
				return (0);
			free(array->join);
			array->join = 0;
		}
	}
	return (1);
}

static int	fn_add_list(register t_main *array, register char *list_name,
	DIR *dirp, uint_fast8_t b_level)
{
	t_fl_ls_list_invalid	inv_new;
	t_fl_ls_list_file		f_new;
	t_fl_ls_list_dir		d_new;

	fl_ls_add_list_init(array, &inv_new, &f_new, &d_new);
	if ((dirp = opendir(list_name)) != 0)
	{
		if (fn_add_list_while(array, list_name, dirp, 0) == 0)
			return (ft_ls_free(array, inv_new.first, f_new.first, d_new.first));
		if (b_level != 0)
			fl_ls_add_list_test(array, list_name, b_level);
		ft_ls_display(array, &inv_new, &f_new, 1);
		closedir(dirp);
		if (d_new.first != 0 && ft_ls_recursive(array, &d_new, 0x11) == 0)
			return (0);
	}
	else if (errno == ENOMEM)
		return (ft_ls_free(array, inv_new.first, f_new.first, d_new.first));
	else
		ft_ls_display_reverse(array, list_name);
	return (1);
}

int			ft_ls_recursive(register t_main *array,
	t_fl_ls_list_dir *dir, uint_fast8_t b_level)
{
	register t_list_dir		*list;
	t_list_dir				*ptr;

	list = dir->first;
	while (list != 0)
	{
		if (fn_add_list(array, list->name, 0, b_level) == 0)
		{
			perror(NAME_PROG);
			return (ft_ls_free(array, 0, 0, dir->first));
		}
		ptr = list;
		free(list->name);
		list = list->next;
		dir->first = list;
		free(ptr);
		b_level = 0x1;
	}
	return (1);
}
