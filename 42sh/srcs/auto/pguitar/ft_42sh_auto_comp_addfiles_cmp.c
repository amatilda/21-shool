/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_comp_addfiles_cmp.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:07:57 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:08:00 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_42sh_auto_comp.h"

static size_t	ft_42sh_auto_comp_type_file_op_dir(char *d_name,
register t_main_42sh *array, struct stat *st)
{
	char		*str;

	if (array->pguitar.comp.open_dirr != NULL)
	{
		if (!(str = ft_strjoin(array->pguitar.comp.open_dirr, d_name)))
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	}
	else if (array->pguitar.comp.dirr != NULL)
	{
		if (!(str = ft_strjoin(array->pguitar.comp.dirr, d_name)))
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	}
	if (lstat(str, st) == -1)
	{
		free(str);
		str = NULL;
		return (0);
	}
	free(str);
	str = NULL;
	return (1);
}

size_t			ft_42sh_auto_comp_type_file(char *d_name,
register t_main_42sh *array)
{
	char		*str;
	struct stat	st;

	if (!(ft_42sh_auto_comp_type_file_op_dir(d_name, array, &st)))
		return (0);
	str = d_name;
	if (S_ISLNK(st.st_mode))
		ft_42sh_auto_add_list(array, str, '@');
	else if (S_ISDIR(st.st_mode) && (array->auto_file.spec_sym = '/'))
		ft_42sh_auto_add_list(array, str, '/');
	else if (st.st_mode & S_IXUSR || st.st_mode & S_IXGRP
		|| st.st_mode & S_IXOTH)
		ft_42sh_auto_add_list(array, str, '*');
	else
		ft_42sh_auto_add_list(array, str, ' ');
	return (1);
}

size_t			ft_42sh_auto_comp_search_cmp(register t_main_42sh *array,
char *d_name)
{
	if (ft_42sh_auto_comp_strncmp(d_name, array->pguitar.comp.str,
		array->pguitar.comp.count_str) == 0)
		ft_42sh_auto_comp_type_file(d_name, array);
	else
		return (0);
	return (1);
}
