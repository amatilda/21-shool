/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_display_full_add.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/10/07 19:04:14 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		fn_stub30(register t_main *array,
	register t_list_file *list, register char *buff)
{
	register void			*tmp;

	fn_dub_char(array, ' ', 1);
	fn_copy_str_zero(array, list->name);
	if (array->option[FLAG_F] != 0 && array->type != 0)
		fn_dub_char(array, array->type, 1);
	if (list->st_mode_type == S_IFLNK)
	{
		tmp = list->patch == 0 ? list->name : list->patch;
		fn_copy_str_zero(array, " -> ");
		fn_copy_str(array, buff, readlink(tmp, buff, FT_LS_MAX_NAME));
	}
	else if (array->option[FLAG_DIR_SLECH] != 0
			&& list->st_mode_type == S_IFDIR)
		fn_dub_char(array, '/', 1);
}

static void		fn_stub20(register t_main *array,
	register t_list_file *list, register void *tmp, register char *buff)
{
	register size_t			tempos;

	fn_copy_str(array, tmp + 3, 8);
	list->st_timespec.tv_sec += array->offset_sec;
	ft_gmtime_r(&list->st_timespec.tv_sec, (struct tm *)buff);
	tempos = ((struct tm *)buff)->tm_mon - array->current_moth;
	if ((ssize_t)tempos < 0)
		tempos = ~tempos + 1;
	if (tempos > 6 || array->current_year != ((struct tm *)buff)->tm_year)
	{
		tempos = ft_itoa(buff, ((struct tm *)buff)->tm_year + 1900,
				10, ITOA_LOWER);
		fn_dub_char(array, ' ', 1);
		fn_copy_str(array, buff, tempos);
	}
	else
		fn_copy_str(array, tmp + 11, 5);
}

static void		fn_stub10(register t_main *array,
	t_fl_ls_list_file *file, register t_list_file *list, register char *buff)
{
	register size_t			tempos;

	if ((tempos = (size_t)list->gr_name) != 0)
	{
		fn_dub_char(array, ' ', list->pw_name != 0 ? 2 : 1);
		fn_copy_str_zero(array, (char *)tempos);
		fn_dub_char(array, ' ', file->max_gr_name - list->gr_size);
		free((char *)tempos);
	}
	if (tempos == 0 && list->pw_name == 0)
		fn_dub_char(array, ' ', 1);
	fn_dub_char(array, ' ', 2);
	if (list->st_mode_type == S_IFCHR || list->st_mode_type == S_IFBLK)
	{
		tempos = ft_itoa(buff, major(list->st_rdev), 10, ITOA_LOWER);
		buff[tempos++] = ',';
		buff[tempos++] = ' ';
		fn_copy_str(array, buff, tempos);
		tempos = ft_itoa(buff, minor(list->st_rdev), 10, ITOA_LOWER);
	}
	else
		fn_dub_char(array, ' ', file->max_size -
			(tempos = ft_itoa(buff, list->size_file, 10, ITOA_LOWER)));
	fn_copy_str(array, buff, tempos);
}

static void		fn_stub00(register t_main *array,
	t_fl_ls_list_file *file, register t_list_file *list, register char *buff)
{
	register void			*tmp;
	register size_t			tempos;

	tmp = list->patch == 0 ? list->name : list->patch;
	if (listxattr(tmp, 0, 0, XATTR_NOFOLLOW) > 0)
		buff[10] = '@';
	else if ((tmp = acl_get_link_np(tmp, ACL_TYPE_EXTENDED)) != 0)
	{
		acl_free(tmp);
		buff[10] = '+';
	}
	else
		buff[10] = ' ';
	fn_copy_str(array, buff, 11);
	tempos = ft_itoa(buff, list->st_nlink, 10, ITOA_LOWER);
	fn_dub_char(array, ' ', file->max_nlink - tempos + 1);
	fn_copy_str(array, buff, tempos);
	if ((tempos = (size_t)list->pw_name) != 0)
	{
		fn_dub_char(array, ' ', 1);
		fn_copy_str_zero(array, (char *)tempos);
		fn_dub_char(array, ' ', file->max_pw_name - list->pw_size);
		free((char *)tempos);
	}
}

void			ft_ls_display_full_add(register t_main *array,
	t_fl_ls_list_file *file, register t_list_file *list, register char *buff)
{
	register void			*tmp;

	fn_stub00(array, file, list, buff);
	fn_stub10(array, file, list, buff);
	tmp = ctime(&list->st_timespec.tv_sec);
	if (array->option[FLAG_FULL_DATE] != 0)
	{
		fn_copy_str(array, tmp + 3, 16);
		fn_dub_char(array, ' ', 1);
		tmp += 19;
		while (((char *)tmp)[0] != 0 && ((char *)tmp)[0] == ' ')
			tmp += 1;
		while (((char *)tmp)[0] >= 0x30 && ((char *)tmp)[0] <= 0x39)
			fn_dub_char(array, ((char *)tmp++)[0], 1);
	}
	else
		fn_stub20(array, list, tmp, buff);
	fn_stub30(array, list, buff);
}
