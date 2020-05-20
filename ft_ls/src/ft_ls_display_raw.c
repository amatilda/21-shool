/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_display_raw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			fn_stub00(register t_main *array,
register t_list_file *list, register char litter, register char *opt)
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

static size_t		fn_set(size_t max_cmd, register size_t x, size_t *y)
{
	if (x == 0)
		x++;
	if (x > max_cmd)
	{
		*y = 1;
		x = max_cmd;
	}
	else
		*y = max_cmd / x + 1;
	return (x);
}

static void			fn_x(t_main *array, t_list_file *list,
size_t max_litter)
{
	register char			*opt;
	register t_list_file	*tmp;
	register size_t			tempos;

	opt = array->option;
	fn_stub00(array, list, 0, opt);
	tempos = list->len;
	if (opt[FLAG_F] == 0)
		tempos++;
	if (opt[FLAG_DIR_SLECH] != 0 && list->st_mode_type == S_IFDIR)
	{
		fn_dub_char(array, '/', 1);
		tempos++;
	}
	fn_dub_char(array, 0x20, max_litter - tempos);
	tmp = list;
	free(list->name);
	if (list->patch != 0)
		free(list->patch);
	list = list->next;
	free(tmp);
}

static size_t		fn_raw(t_main *array, size_t max_litter,
t_list_file **spl, size_t max_cmd)
{
	register size_t				tempos;
	register size_t				x;
	size_t						y;
	register size_t				i_y;
	register size_t				i_x;

	max_litter += 2;
	x = fn_set(max_cmd, array->ws.ws_col / max_litter, &y);
	i_y = 0;
	while (i_y < y)
	{
		i_x = 0;
		while (i_x < x && max_cmd > (tempos = i_y + i_x++ * y))
			fn_x(array, spl[tempos], max_litter);
		i_y++;
		fn_dub_char(array, '\n', 1);
	}
	if (x == 1 && max_litter > array->ws.ws_col)
		return (max_cmd + max_cmd * (max_litter / array->ws.ws_col) + 1);
	return (y);
}

void				ft_ls_display_raw(register t_main *array,
register t_list_file *list, register char *opt)
{
	register t_list_file			**out;
	register t_list_file			**spl;

	if ((out = malloc(sizeof(t_list_file *) * (array->count_list + 1))) == 0)
	{
		perror(array->err_str);
		exit(1);
	}
	spl = out;
	out[array->count_list] = 0;
	while (list != 0)
	{
		spl++[0] = list;
		list = list->next;
	}
	fn_raw(array, array->max_len, out, array->count_list);
	free(out);
	(void)opt;
}
