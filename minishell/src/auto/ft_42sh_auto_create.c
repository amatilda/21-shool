/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static t_all_cmd_42sh		*fn_list_create(register t_main_42sh *array,
register char *key)
{
	register size_t				key_count;
	register size_t				key_litter;
	register t_all_cmd_42sh		*out;
	register char				lit;

	key_count = 0;
	key_litter = 0;
	while ((lit = key[key_count++]) != 0)
	{
		key_litter++;
		if ((lit & 0x80) != 0)
		{
			while (((lit = key[key_count]) & 0x80) != 0 && (lit & 0x40) == 0)
				key_count++;
		}
	}
	if ((out = malloc(sizeof(t_all_cmd_42sh) + key_count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	out->std.key_count = key_count - 1;
	out->std.lp_key = out->key;
	out->key_litter = key_litter;
	array->tab.max_litter = key_litter > array->tab.max_litter ?
	key_litter : array->tab.max_litter;
	ft_memcpy(out->key, key, key_count);
	return (out);
}

static void					fn_add_list(register t_main_42sh *array,
register char *lp_key)
{
	register t_past_sort_42sh	*root;
	register size_t				tempos;
	register t_all_cmd_42sh		*list;

	tempos = (unsigned char)lp_key[0];
	list = fn_list_create(array, lp_key);
	root = &array->tab.all_cmd;
	if (root->first == 0)
	{
		list->std.next = 0;
		list->std.prev = 0;
		root->first = list;
		root->center = list;
		root->last = list;
		array->tab.count_all++;
		return ;
	}
	array->tab.count_all += ft_42sh_list_sort_paste(root, &list->std, free);
}

static void					fn_while_dir(register t_main_42sh *array,
register char **spl)
{
	register char			*tmp;
	register size_t			tempos;
	register DIR			*dirp;
	register struct dirent	*dp;
	struct stat				st;

	while ((tmp = spl++[0]) != 0)
	{
		if ((dirp = opendir(tmp)) != 0)
		{
			chdir(tmp);
			while ((dp = readdir(dirp)) != 0)
			{
				if (lstat((tmp = dp->d_name), &st) == 0)
				{
					tempos = st.st_mode;
					if ((tempos & S_IFMT) == S_IFREG && ((tempos & S_IXUSR) |
					(tempos & S_IXGRP) | (tempos & S_IXOTH) != 0))
						fn_add_list(array, tmp);
				}
			}
			closedir(dirp);
		}
	}
}

static void					fn_create_big(register t_main_42sh *array)
{
	register t_all_cmd_42sh		*list;
	register size_t				tempos;
	register t_all_cmd_42sh		**spl;

	list = array->tab.all_cmd.first;
	tempos = array->tab.count_all;
	if ((spl = malloc(sizeof(t_all_cmd_42sh *) * (tempos + 1))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	spl[tempos] = 0;
	array->tab.spl_all_cmd = spl;
	while (list != 0)
	{
		spl++[0] = list;
		list = (void *)list->std.next;
	}
}

void						ft_42sh_auto_create(register t_main_42sh *array)
{
	register char		**spl;

	array->tab.count_all = 0;
	array->tab.max_litter = 0;
	if ((spl = array->lp_spl_path) != 0)
		ft_strsplit_free(spl);
	if ((spl = (char **)array->env.lp_env_path) != 0)
	{
		if ((spl = ft_strsplit((((t_env_42sh *)spl)->lp_value), ':')) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		fn_while_dir(array, spl);
		chdir(array->pwd.path.buff);
	}
	array->lp_spl_path = spl;
	fn_add_list(array, "setenv");
	fn_add_list(array, "unsetenv");
	fn_add_list(array, "echo");
	fn_add_list(array, "env");
	fn_add_list(array, "exit");
	fn_add_list(array, "cd");
	fn_add_list(array, "clear");
	fn_create_big(array);
}
