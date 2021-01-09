/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_path_logins.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_path.h"

static void		fn_dir(register t_main_42sh *array)
{
	register DIR			*dirp;
	register struct dirent	*dp;
	register unsigned char	*tmp;
	register size_t			count;
	struct stat				st;

	if ((dirp = opendir(EXP_HOME_PATH_42SH)) == 0)
		return ;
	while ((dp = readdir(dirp)) != 0)
	{
		count = dp->d_namlen;
		if ((tmp = ft_strnjoin(EXP_HOME_PATH_42SH,
		sizeof(EXP_HOME_PATH_42SH) - 1, dp->d_name, count)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
		if (stat((void *)tmp, &st) == 0 && st.st_uid != 0)
		{
			ft_42sh_path_logins_list_add(array,
			ft_42sh_path_logins_list_create((void *)&dp->d_name, count, tmp,
			count + sizeof(EXP_HOME_PATH_42SH) - 1));
		}
		ft_free(tmp);
	}
	closedir(dirp);
}

static void		*fn_comment(register unsigned char *b,
register unsigned char *e)
{
	while (b < e && b[0] <= 0x20)
		b++;
	while (b < e && b[0] == '#')
	{
		while (b < e && b[0] != '\n')
			b++[0] = ' ';
		while (b < e && b[0] <= 0x20)
			b++;
	}
	return (b);
}

static void		*fn_path(register unsigned char *b,
register unsigned char *e, size_t *count)
{
	register unsigned char		litter;

	*count = 0;
	while (b < e && (litter = b[0]) != '\n' && *count != 5)
	{
		if (litter == ':')
			*count = *count + 1;
		b++;
	}
	return (b);
}

static void		fn_file(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e)
{
	register unsigned char		*name;
	register size_t				name_count;
	register unsigned char		*home_dir;
	register unsigned char		litter;
	size_t						count;

	while ((b = fn_comment(b, e)) < e)
	{
		name = b;
		while (b < e && (litter = b[0]) != ':' && litter != '\n')
			b++;
		name_count = b - name;
		b = fn_path(b, e, &count);
		home_dir = b;
		while (b < e && (litter = b[0]) != ':' && litter != '\n')
			b++;
		if (count == 5 && litter == ':')
		{
			ft_42sh_path_logins_list_add(array,
			ft_42sh_path_logins_list_create(name, name_count,
			home_dir, b - home_dir));
		}
		while (b < e && b[0] != '\n')
			b++;
	}
}

void			ft_42sh_path_logins(register t_main_42sh *array)
{
	register unsigned char	*b;
	register size_t			count;
	struct stat				st;
	register int			fd;

	fn_dir(array);
	if (stat(FILE_PASSWD_42SH, &st) != 0)
		return (ft_42sh_path_logins_test_empty(array));
	count = st.st_size;
	if (count <= FILE_PASSWD_MIN_42SH || count >= FILE_PASSWD_MAX_42SH)
		return (ft_42sh_path_logins_test_empty(array));
	if ((b = ft_malloc(count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	if ((fd = open(FILE_PASSWD_42SH, O_RDONLY)) != -1)
		if (read(fd, b, count) != -1)
			fn_file(array, b, b + count);
	ft_free(b);
	close(fd);
	return (ft_42sh_path_logins_test_empty(array));
}
