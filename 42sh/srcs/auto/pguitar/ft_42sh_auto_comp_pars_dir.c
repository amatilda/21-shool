/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_comp_pars_dir.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:08:54 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:08:57 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_42sh_auto_comp.h"

static void	ft_42sh_auto_comp_add_files(t_main_42sh *array)
{
	DIR				*dir;
	struct dirent	*entry;

	if (array->pguitar.comp.open_dirr)
	{
		if (!(dir = opendir(array->pguitar.comp.open_dirr)))
			return ;
	}
	else if (!(dir = opendir(array->pguitar.comp.dirr)))
		return ;
	while ((entry = readdir(dir)) != NULL)
	{
		if ((entry->d_name[0] == '.' && entry->d_name[1] == '\0') ||
			(entry->d_name[0] == '.' && entry->d_name[1] == '.'
			&& entry->d_name[2] == '\0'))
			;
		else if (array->pguitar.comp.count_str != 0)
			ft_42sh_auto_comp_search_cmp(array, entry->d_name);
		else if ((entry->d_name[0] != '.'))
			ft_42sh_auto_comp_type_file(entry->d_name, array);
	}
	closedir(dir);
	if (array->lp_auto->all_cmd.first)
		ft_42sh_auto_create_array(array, array->lp_auto->all_cmd.first,
	array->lp_auto->count_all);
}

static void	ft_42sh_auto_comp_pars_dir_cur(register t_main_42sh *array)
{
	if (!(array->pguitar.comp.dirr = (char *)malloc(sizeof(char) * 3)))
		ft_42sh_exit(E_MEM_CODE_42SH);
	*(array->pguitar.comp.dirr) = '.';
	*(array->pguitar.comp.dirr + 1) = '/';
	array->pguitar.comp.del = 2;
	array->pguitar.comp.count_dirr = 2;
	if (*(array->pguitar.comp.str) == '.' &&
		*(array->pguitar.comp.str + 1) == '/')
	{
		array->pguitar.comp.str = array->pguitar.comp.str + 2;
		array->pguitar.comp.count_str = array->pguitar.comp.count_str - 2;
		array->pguitar.comp.del = 0;
	}
}

static void	ft_42sh_auto_comp_pars_dir_root(register t_main_42sh *array)
{
	if (!(array->pguitar.comp.dirr = (char *)malloc(sizeof(char) * 2)))
		ft_42sh_exit(E_MEM_CODE_42SH);
	*(array->pguitar.comp.dirr) = '/';
	array->pguitar.comp.count_dirr = 1;
	array->pguitar.comp.str++;
	array->pguitar.comp.count_str--;
}

static void	ft_42sh_auto_comp_pars_dir_tilda(register t_main_42sh *array)
{
	register char *dir;
	register char *home;

	if (array->pguitar.comp.count_str != 1)
	{
		array->pguitar.comp.dirr = ft_strdup("/Users/");
		array->pguitar.comp.count_dirr = 7;
		array->pguitar.comp.str++;
		array->pguitar.comp.count_str--;
		return ;
	}
	home = array->lp_home;
	if (!(dir = (char *)malloc(sizeof(char) * array->count_home + 2)))
		ft_42sh_exit(E_MEM_CODE_42SH);
	array->pguitar.comp.dirr = dir;
	while (*home)
		*(dir++) = *(home++);
	*dir = '/';
	array->pguitar.comp.count_dirr = array->count_home + 1;
	array->pguitar.comp.str++;
	array->pguitar.comp.count_str--;
}

size_t		ft_42sh_auto_comp_pars_dir(register t_main_42sh *array)
{
	array->lp_auto = &array->auto_file;
	if (*(array->pguitar.comp.str) == '~')
	{
		if (*(array->pguitar.comp.str + 1) != '/')
			ft_42sh_auto_comp_pars_dir_tilda(array);
		else
		{
			array->pguitar.comp.dirr = ft_strdup("~/");
			array->pguitar.comp.count_dirr = 2;
			array->pguitar.comp.str += 2;
			array->pguitar.comp.count_str -= 2;
		}
	}
	else if (array->pguitar.comp.count_str == 0 ||
		(*(array->pguitar.comp.str) != '/'))
		ft_42sh_auto_comp_pars_dir_cur(array);
	else
		ft_42sh_auto_comp_pars_dir_root(array);
	*(array->pguitar.comp.dirr + array->pguitar.comp.count_dirr) = '\0';
	if (!ft_42sh_auto_comp_check_dir(array))
		return (0);
	if (array->lp_auto->b_auto != 1)
		ft_42sh_auto_comp_add_files(array);
	return (1);
}
