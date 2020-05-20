/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_display_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void			ft_ls_display_line(register t_main *array,
register t_list_file *list, register char *opt)
{
	register t_list_file	*tmp;

	if (list == 0)
		return ;
	if (opt[FLAG_ONE_LINE] == 0)
		return (ft_ls_display_raw(array, list, opt));
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
