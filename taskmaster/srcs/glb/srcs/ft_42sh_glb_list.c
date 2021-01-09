/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_glb_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_glb.h"

void		ft_42sh_glb_list_add_only(register t_main_42sh *array,
t_glb_list *list)
{
	register t_glb_list				*first;

	list->next = 0;
	if ((first = array->glb.first) == 0)
	{
		array->glb.first = list;
		array->glb.last = list;
		list->prev = 0;
	}
	else
	{
		array->glb.last->next = list;
		list->prev = array->glb.last;
		array->glb.last = list;
	}
}

static void	*fn_path_dir(register unsigned char *path)
{
	register unsigned char			*path_dir;

	path_dir = path + ft_strlen((void *)path) - 1;
	while (path_dir > path && path_dir[0] == '/')
		path_dir--;
	while (path_dir > path && path_dir[0] != '/')
		path_dir--;
	if (path_dir[0] == '/')
		path_dir++;
	return (path_dir);
}

static void	fn_dir(register t_main_42sh *array,
register unsigned char *path, register char *name, register const char *src)
{
	register char			*tmp;
	register size_t			count;

	if (path[0] != 0)
	{
		tmp = (void *)path;
		count = ft_strlen(tmp);
		if (count != 0 && tmp[count - 1] == '/')
			tmp[count - 1] = 0;
		if ((path = (void *)ft_42sh_path_join((char *)path, name)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
		ft_free(name);
		if (count != 0 && tmp[count - 1] == 0)
			tmp[count - 1] = '/';
	}
	else
		path = (void *)name;
	ft_42sh_glb_while_dir(array, src, (void *)path, fn_path_dir(path));
}

static void	*fn_join(register char *name,
register const char *src, register char *tmp)
{
	if (tmp != src)
		if ((name = ft_strnjoin(name, ft_strlen(name), tmp, src - tmp)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	return (name);
}

void		ft_42sh_glb_list_add(register t_main_42sh *array,
register unsigned char *path, register char *name, register const char *src)
{
	register char					*tmp;
	register size_t					n_path;
	register size_t					n_name;
	register t_glb_list				*list;

	if ((tmp = (char *)src) != 0)
	{
		while (src[0] == '/')
			src++;
		name = fn_join(name, src, tmp);
		if (src[0] != 0)
			return (fn_dir(array, path, name, src));
	}
	n_path = ft_strlen((void *)path);
	n_name = ft_strlen((void *)name);
	if ((list = malloc(sizeof(t_glb_list) + n_path + n_name + 2)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	ft_memcpy(&list->name[0], path, n_path);
	if (n_path != 0 && path[n_path - 1] != '/')
		list->name[n_path++] = '/';
	ft_memcpy(&list->name[n_path], name, n_name);
	list->name[n_path + n_name] = 0;
	ft_42sh_glb_list_add_only(array, list);
	if (tmp != src)
		ft_free(name);
}