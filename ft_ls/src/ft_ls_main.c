/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/12/11 19:31:42 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_init_main1(register t_main *array, register t_fl_ls_list_dir *dir)
{
	array->b_level = array->file.first != 0 ? 1 : 0;
	array->b_level |= array->invalid.first != 0 ? 0x10 : 0;
	if (dir->count > 1)
		array->b_level |= 0x10;
	ft_ls_display(array, &array->invalid, &array->file, 0);
	if (array->option[FLAG_ONLY_DIR] == 0)
		ft_ls_recursive(array, dir, array->b_level);
	if (array->count_invalid != 0)
		write(2, array->b_invalid, array->count_invalid);
	if (array->count != 0)
		write(1, array->b, array->count);
}

void	ft_ls_init_main0(register t_main *array)
{
	register void	*tmp;
	time_t			curent;

	time(&curent);
	tmp = ctime(&curent);
	array->offset_sec = ft_atoi(tmp + 11) * 3600;
	curent += array->offset_sec;
	ft_gmtime_r(&curent, (struct tm *)array->out_pre);
	array->current_moth = ((struct tm *)array->out_pre)->tm_mon;
	array->current_year = ((struct tm *)array->out_pre)->tm_year;
	if (array->option[FLAG_NOT_SORT] != 0)
		array->option[FLAG_SYSTEM] = 1;
	if (array->st_timespec == 0)
		array->st_timespec = &array->stat_info.st_mtimespec;
	if (array->option[FLAG_INFO_FULL] != 0)
		array->f = lstat;
	else
		array->f = stat;
	array->err_str = NAME_PROG;
}
