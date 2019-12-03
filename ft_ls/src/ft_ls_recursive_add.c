/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_recursive_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fl_ls_add_list_init(register t_main *array,
	t_fl_ls_list_invalid *inv_new, register t_fl_ls_list_file *file_new,
	t_fl_ls_list_dir *dir_new)
{
	array->inv_new = inv_new;
	array->file_new = file_new;
	array->dir_new = dir_new;
	dir_new->first = 0;
	dir_new->count = 0;
	inv_new->first = 0;
	file_new->first = 0;
	file_new->max_size = 0;
	file_new->max_nlink = 0;
	file_new->max_pw_name = 0;
	file_new->max_gr_name = 0;
	file_new->st_blocks = 0;
}

void	fl_ls_add_list_test(register t_main *array, register char *list_name,
	uint_fast8_t b_level)
{
	if (b_level != 0x10)
		fn_dub_char(array, '\n', 1);
	if (list_name[0] == '/' && array->option[FLAG_RECURS] != 0)
		list_name++;
	fn_copy_str_zero(array, list_name);
	fn_copy_str_zero(array, ":\n");
}
