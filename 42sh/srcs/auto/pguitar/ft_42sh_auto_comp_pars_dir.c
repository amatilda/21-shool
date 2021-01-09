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

int			ft_42sh_auto_comp_strncmp(register char *s1, register char *s2,
register size_t n)
{
	register size_t i;
	register size_t j;

	if (n == 0)
		return (0);
	i = 0;
	j = 0;
	if (s2[j] == '\\' && (s2[j + 1] == ' ' || s2[j + 1] == '\''
		|| s2[j + 1] == '\"'))
	{
		n--;
		j++;
	}
	while (s1[i] != 0 && s1[i] == s2[j] && i < n)
	{
		i++;
		j++;
		if (s2[j] == '\\' && ++j)
			n--;
	}
	if (s2[j] == '\0')
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

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
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
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
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	*(array->pguitar.comp.dirr) = '/';
	array->pguitar.comp.count_dirr = 1;
	array->pguitar.comp.str++;
	array->pguitar.comp.count_str--;
}

size_t		ft_42sh_auto_comp_pars_dir(register t_main_42sh *array,
register t_in_42sh *list)
{
	array->lp_auto = &array->auto_file;
	if (ft_42sh_auto_comp_pars_dir_tilda(array, list))
		return (1);
	if (array->pguitar.comp.count_str == 0 ||
		(*(array->pguitar.comp.str) != '/'))
		ft_42sh_auto_comp_pars_dir_cur(array);
	else
		ft_42sh_auto_comp_pars_dir_root(array);
	*(array->pguitar.comp.dirr + array->pguitar.comp.count_dirr) = '\0';
	if (!ft_42sh_auto_comp_check_dir(array, list, NULL))
		return (0);
	if (array->lp_auto->b_auto != 1)
		ft_42sh_auto_comp_add_files(array);
	return (1);
}
