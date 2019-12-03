/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_display_full.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/10/07 21:02:51 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	fn_root_file(register size_t tempos, register char *buff)
{
	buff[1] = (tempos & S_IRUSR) != 0 ? 'r' : '-';
	buff[2] = (tempos & S_IWUSR) != 0 ? 'w' : '-';
	if ((tempos & S_ISUID) != 0)
		buff[3] = (tempos & S_IXUSR) != 0 ? 's' : 'S';
	else
		buff[3] = (tempos & S_IXUSR) != 0 ? 'x' : '-';
	buff[4] = (tempos & S_IRGRP) != 0 ? 'r' : '-';
	buff[5] = (tempos & S_IWGRP) != 0 ? 'w' : '-';
	if ((tempos & S_ISGID) != 0)
		buff[6] = (tempos & S_IXGRP) != 0 ? 's' : 'S';
	else
		buff[6] = (tempos & S_IXGRP) != 0 ? 'x' : '-';
	buff[7] = (tempos & S_IROTH) != 0 ? 'r' : '-';
	buff[8] = (tempos & S_IWOTH) != 0 ? 'w' : '-';
	if ((tempos & S_ISVTX) != 0)
		buff[9] = (tempos & S_IXOTH) != 0 ? 't' : 'T';
	else
		buff[9] = (tempos & S_IXOTH) != 0 ? 'x' : '-';
}

static void	fn_type_file(register t_main *array, register size_t tempos,
	register t_list_file *list, register char *buff)
{
	t_list_type		val;

	if (tempos == S_IFDIR)
		val.t_uni.tempos = ('/' << 8) | 'd';
	else if (tempos == S_IFLNK)
		val.t_uni.tempos = ('@' << 8) | 'l';
	else if (tempos == S_IFSOCK)
		val.t_uni.tempos = ('=' << 8) | 's';
	else if (tempos == S_IFIFO)
		val.t_uni.tempos = ('|' << 8) | 'p';
	else if (tempos == S_IFCHR)
		val.t_uni.tempos = ('%' << 8) | 'c';
	else if (tempos == S_IFBLK)
		val.t_uni.tempos = ('%' << 8) | 'b';
	else
	{
		tempos = list->st_mode;
		tempos = (tempos & S_IXUSR) | (tempos & S_IXGRP) | (tempos & S_IXOTH);
		val.t_uni.tempos = ((tempos != 0 ? '*' : 0) << 8) | '-';
	}
	array->type = val.t_uni.t_ltype.type;
	buff[0] = val.t_uni.t_ltype.buff;
}

static void	fn_only_dir(register t_main *array,
	t_fl_ls_list_file *file, register char *buff)
{
	register size_t			tempos;

	fn_copy_str_zero(array, "total ");
	tempos = ft_itoa(buff, file->st_blocks, 10, ITOA_LOWER);
	buff[tempos] = '\n';
	fn_copy_str(array, buff, tempos + 1);
}

void		fn_display_info_full(register t_main *array,
	t_fl_ls_list_file *file, register t_list_file *list, uint_fast8_t b_level)
{
	register char			*buff;
	register void			*tmp;

	if (list == 0)
		return ;
	buff = array->out_pre;
	file->max_size = ft_itoa(buff, file->max_size, 10, ITOA_LOWER);
	file->max_nlink = ft_itoa(buff, file->max_nlink, 10, ITOA_LOWER);
	if (array->option[FLAG_ONLY_DIR] == 0 && b_level != 0)
		fn_only_dir(array, file, buff);
	while (list != 0)
	{
		fn_type_file(array, list->st_mode_type, list, buff);
		fn_root_file(list->st_mode, buff);
		ft_ls_display_full_add(array, file, list, buff);
		fn_dub_char(array, '\n', 1);
		tmp = list;
		free(list->name);
		if (list->patch != 0)
			free(list->patch);
		list = list->next;
		free(tmp);
	}
}
