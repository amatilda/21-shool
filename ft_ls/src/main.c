/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	fn_stub00(register t_main *array, register struct stat *stat_info,
	register t_fl_ls_list_dir *dir, register char *tmp)
{
	if ((stat_info->st_mode & S_IFMT) == S_IFDIR)
	{
		if (array->option[FLAG_ONLY_DIR] == 0)
		{
			if (ft_ls_list_add_dir(array, dir, tmp) == 0)
				return (0);
		}
		else if (ft_ls_list_add_file(array, &array->file, tmp) == 0)
			return (0);
	}
	else if (ft_ls_list_add_file(array, &array->file, tmp) == 0)
		return (0);
	return (1);
}

static int	fn_search_dir(register t_main *array, int argc,
	register char **argv, register t_fl_ls_list_dir *dir)
{
	register char			*tmp;
	register struct stat	*stat_info;

	stat_info = &array->stat_info;
	while (argc-- > 1)
	{
		if (array->f((tmp = &argv++[0][0]), stat_info) == 0 ||
			(array->f != lstat && lstat(tmp, stat_info) == 0))
		{
			if (fn_stub00(array, stat_info, dir, tmp) == 0)
				return (0);
		}
		else if (tmp[0] == 0)
		{
			array->err_str = ERROR_NULL_STR;
			return (0);
		}
		else if (ft_ls_list_add_invalid(array, &array->invalid, tmp) == 0)
			return (0);
	}
	return (1);
}

static int	fn_init(register t_main *array, int argc, register char **argv)
{
	t_fl_ls_list_dir		dir;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &array->ws);
	ft_ls_init_main0(array);
	dir.first = 0;
	dir.count = 0;
	if (argc <= 1)
	{
		argc++;
		argv--[-1] = ".";
	}
	if (fn_search_dir(array, argc, argv, &dir) == 0)
	{
		perror(array->err_str);
		return (ft_ls_free(array, array->invalid.first,
			array->file.first, dir.first));
	}
	ft_ls_init_main1(array, &dir);
	return (1);
}

static void	fn_option(register t_main *array, register char *opt,
	register int litter)
{
	if (litter == FLAG_INFO_FULL)
		opt[FLAG_ONE_LINE] = 0;
	else if (litter == FLAG_ONE_LINE)
		opt[FLAG_INFO_FULL] = 0;
	else if (litter == FLAG_ONLY_GROOP)
	{
		opt[FLAG_ONE_LINE] = 0;
		opt[FLAG_INFO_FULL] = 1;
	}
	else if (litter == FLAG_ONLY_USER)
	{
		opt[FLAG_ONE_LINE] = 0;
		opt[FLAG_INFO_FULL] = 1;
	}
	else if (litter == FLAG_F)
		opt[FLAG_DIR_SLECH] = 0;
	else if (litter == FLAG_DIR_SLECH)
		opt[FLAG_F] = 0;
	else if (litter == FLAG_SORT_TIME_CREATION)
		array->st_timespec = &array->stat_info.st_birthtimespec;
	else if (litter == FLAG_SORT_LAST_CHANGE)
		array->st_timespec = &array->stat_info.st_ctimespec;
	else if (litter == FLAG_SORT_TIME_ACCES)
		array->st_timespec = &array->stat_info.st_atimespec;
	opt[litter] = 1;
}

int			main(int argc, char **a)
{
	static t_main		array;
	register char		litter;
	register char		*tmp;

	a++;
	while (argc > 1)
	{
		if (a[0][0] != '-' || a[0][1] == 0)
			break ;
		argc--;
		if (a++[0][0] == '-' && (tmp = &a[-1][1])[0] == '-' && a[-1][2] == 0)
			break ;
		while ((litter = tmp++[0]) != 0)
		{
			if (ft_strchr(STR_OPTION, litter) == 0)
			{
				write(2, USAGE_PRE, sizeof(USAGE_PRE) - 1);
				write(2, &tmp[-1], 1);
				write(2, USAGE_LAST, sizeof(USAGE_LAST) - 1);
				return (1);
			}
			fn_option(&array, array.option, litter);
		}
	}
	return (fn_init(&array, argc, a));
}
