/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_test_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

static size_t		fn_test_md(register struct stat *st,
register unsigned char litter)
{
	register mode_t				md;

	if (litter == 'g')
	{
		if (((md = st->st_mode) & S_ISGID) != 0 && (md & S_IXGRP) != 0)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'k')
	{
		if (((md = st->st_mode) & S_ISVTX) != 0 && (md & S_IXOTH) != 0)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'u')
	{
		if (((md = st->st_mode) & S_ISUID) != 0 && (md & S_IXUSR) != 0)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'x')
	{
		if (((md = st->st_mode) & S_ISUID) == 0 && (md & S_IXUSR) != 0)
			return (STATUS_OK_42SH);
	}
	return (STATUS_FALTURE_42SH);
}

static size_t		fn_test_finish(register struct stat *st,
register unsigned char litter)
{
	if (litter == 's')
	{
		if (st->st_size > 0)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'S')
	{
		if ((st->st_mode & S_IFMT) == S_IFSOCK)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'w')
	{
		if ((st->st_mode & S_IWUSR) != 0)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'O')
	{
		if (st->st_uid != 0)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'e')
		return (STATUS_OK_42SH);
	else
		return (fn_test_md(st, litter));
	return (STATUS_FALTURE_42SH);
}

static size_t		fn_test_next(register struct stat *st,
register unsigned char litter)
{
	if (litter == 'h' || litter == 'L')
	{
		if ((st->st_mode & S_IFMT) == S_IFLNK)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'p')
	{
		if ((st->st_mode & S_IFMT) == S_IFIFO)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'r')
	{
		if ((st->st_mode & S_IRUSR) != 0)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'G')
	{
		if (st->st_gid != 0)
			return (STATUS_OK_42SH);
	}
	else
		return (fn_test_finish(st, litter));
	return (STATUS_FALTURE_42SH);
}

static size_t		fn_test(register struct stat *st,
register unsigned char litter)
{
	if (litter == 'b')
	{
		if ((st->st_mode & S_IFMT) == S_IFBLK)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'c')
	{
		if ((st->st_mode & S_IFMT) == S_IFCHR)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'd')
	{
		if ((st->st_mode & S_IFMT) == S_IFDIR)
			return (STATUS_OK_42SH);
	}
	else if (litter == 'f')
	{
		if ((st->st_mode & S_IFMT) == S_IFREG)
			return (STATUS_OK_42SH);
	}
	else
		return (fn_test_next(st, litter));
	return (STATUS_FALTURE_42SH);
}

size_t				ft_42sh_cm_test_path(register t_main_42sh *array,
register char **lp_arg, register unsigned char *str,
register unsigned char litter)
{
	struct stat					st;
	int							(*f)(const char *, struct stat *);

	if (litter == 'b' || litter == 'c' || litter == 'd' || litter == 'e' ||
	litter == 'f' || litter == 'g' || litter == 'h' || litter == 'k' ||
	litter == 'L' || litter == 'p' || litter == 'r' || litter == 'S' ||
	litter == 's' || litter == 'u' || litter == 'W' || litter == 'x' ||
	litter == 'O' || litter == 'G' || litter == 'w')
	{
		if (lp_arg[0] != 0)
		{
			ft_42sh_dsp_err_msg(array,
			WAR_42SH""MSG_TEST_TOO_ARG_TXT_42SH""PRTF_RESET);
			return (STATUS_REZERVED_42SH);
		}
		f = (litter == 'L' || litter == 'h') ? lstat : stat;
		if (str[0] != 0 && f((void *)str, &st) == 0)
			return (fn_test(&st, litter));
		else
			return (STATUS_FALTURE_42SH);
	}
	return (ft_42sh_cm_test_three_err_unk(array, (void *)lp_arg[-2]));
}