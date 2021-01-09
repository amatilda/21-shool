/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_glb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_glb.h"

static void	*test_dir(register char *tmp, struct stat *st,
register unsigned char *patt, register const char *src)
{
	if (tmp[0] == '.')
	{
		if (patt[0] != '.')
			return (0);
		st->st_mode = S_IFDIR;
		if (tmp[1] == 0 && (patt[1] == '/' || patt[1] == 0))
			return (tmp);
		else if (tmp[1] == '.' && tmp[2] == 0 && patt[1] == '.'
		&& (patt[2] == '/' || patt[2] == 0))
			return (tmp);
		return (0);
	}
	if (stat(tmp, st) != 0)
		return (0);
	if (src[0] != 0 && (st->st_mode & S_IFMT) != S_IFDIR)
		return (0);
	return (tmp);
}

static void	fn_glb_while_dir(register t_main_42sh *array,
register const char *src, register unsigned char *path, register DIR *dirp)
{
	register char			*path_dir;
	register void			*tmp;
	register unsigned char	*patt;
	register struct dirent	*dp;
	struct stat				st;

	patt = (void *)src;
	while (src[0] != '/' && src[0] != 0)
		src++;
	if (src - (const char *)patt == 0)
		return ;
	if ((path_dir = getcwd(0, 0)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	while ((dp = readdir(dirp)) != 0)
	{
		chdir((char *)path_dir);
		if ((tmp = test_dir(dp->d_name, &st, patt, src)) == 0)
			continue ;
		if (ft_42sh_pattern(tmp, (tmp + ft_strlen(tmp)),
		patt, (void *)src) == 0)
			continue ;
		ft_42sh_glb_list_add(array, path, tmp,
		((st.st_mode & S_IFMT) == S_IFDIR) ? src : 0);
	}
	free(path_dir);
}

void		ft_42sh_glb_while_dir(register t_main_42sh *array,
register const char *src, register unsigned char *path, register char *path_dir)
{
	register DIR			*dirp;

	if ((dirp = opendir((void *)path_dir)) != 0)
	{
		chdir(path_dir);
		fn_glb_while_dir(array, src, (void *)path, dirp);
		closedir(dirp);
	}
	ft_free((void *)path);
}

void		*ft_42sh_glb(register t_main_42sh *array, register const char *src)
{
	register const char		*tmp;
	register char			*path_dir;
	register void			*last;

	tmp = src;
	while (src[0] == '/')
		src++;
	path_dir = (tmp != src) ? "/" : "./";
	if ((tmp = ft_strndup(tmp, src - tmp)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	last = array->glb.last;
	ft_42sh_glb_while_dir(array, src, (void *)tmp, path_dir);
	chdir(array->pwd.path.buff);
	if (last == array->glb.last)
		return (0);
	return (array->glb.first);
}
