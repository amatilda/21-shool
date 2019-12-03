/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	fn_free_file(register t_list_file *file)
{
	register char		*tmp;

	while (file != 0)
	{
		tmp = (char *)file;
		free(file->name);
		if (file->patch != 0)
			free(file->patch);
		if (file->pw_name != 0)
			free(file->pw_name);
		if (file->gr_name != 0)
			free(file->gr_name);
		file = file->next;
		free(tmp);
	}
}

int			ft_ls_free(register t_main *array, register t_list_invalid *invalid,
	register t_list_file *file, register t_list_dir *dir)
{
	register char		*tmp;

	tmp = array->join;
	if (tmp != 0)
	{
		free(tmp);
		array->join = 0;
	}
	while (invalid != 0)
	{
		tmp = (char *)invalid;
		free(invalid->name);
		invalid = invalid->next;
		free(tmp);
	}
	fn_free_file(file);
	while (dir != 0)
	{
		tmp = (char *)dir;
		free(dir->name);
		dir = dir->next;
		free(tmp);
	}
	return (0);
}
