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

static void				fn_add_list(register t_main_42sh *array,
register char *lp_key, register void *str, uint_fast8_t b_type)
{
	register t_all_cmd_42sh		*list;

	if ((list = ft_42sh_auto_add_list(array, lp_key, 0)) == 0)
		return ;
	list->path = str;
	list->b_type = b_type;
}

static void				fn_while_dir(register t_main_42sh *array,
char **spl, register char *slesh)
{
	register char			*tmp;
	register size_t			md;
	register DIR			*dirp;
	register struct dirent	*dp;
	struct stat				st;

	while ((slesh = spl++[0]) != 0)
	{
		if ((dirp = opendir(slesh)) != 0)
		{
			chdir(slesh);
			while ((dp = readdir(dirp)) != 0)
			{
				if (lstat((tmp = dp->d_name), &st) == 0)
				{
					md = st.st_mode;
					if ((md & S_IXUSR) | (md & S_IXGRP) | (md & S_IXOTH) != 0)
						fn_add_list(array, tmp, slesh, AUTO_TYPE_EXE);
				}
			}
			closedir(dirp);
		}
	}
}

void					ft_42sh_auto_create_array(register t_main_42sh *array)
{
	register t_all_cmd_42sh		*list;
	register size_t				tempos;
	register t_all_cmd_42sh		**spl;

	list = array->lp_auto->all_cmd.first;
	tempos = array->lp_auto->count_all;
	if ((spl = ft_malloc(sizeof(t_all_cmd_42sh *) * (tempos + 1))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	spl[tempos] = 0;
	array->lp_auto->spl_all_cmd = spl;
	while (list != 0)
	{
		spl++[0] = list;
		list = (void *)list->std.next;
	}
}

void					ft_42sh_auto_create(register t_main_42sh *array)
{
	register char		**spl;

	array->lp_auto->count_all = 0;
	array->lp_auto->max_litter = 0;
	if ((spl = array->lp_spl_path) != 0)
		ft_strsplit_free(spl);
	fn_add_list(array, "setenv", &ft_42sh_cm_setenv, AUTO_TYPE_FUN);
	fn_add_list(array, "unsetenv", &ft_42sh_cm_unsetenv, AUTO_TYPE_FUN);
	fn_add_list(array, "echo", &ft_42sh_cm_echo, AUTO_TYPE_FUN);
	fn_add_list(array, "env", &ft_42sh_cm_env, AUTO_TYPE_FUN);
	fn_add_list(array, "exit", &ft_42sh_cm_exit, AUTO_TYPE_FUN);
	fn_add_list(array, "cd", &ft_42sh_cm_cd, AUTO_TYPE_FUN);
	fn_add_list(array, "clear", &ft_42sh_cm_clear, AUTO_TYPE_FUN);
	if ((spl = (char **)array->env.lp_env_path) != 0)
	{
		if ((spl = ft_strsplit((((t_env_42sh *)spl)->lp_value), ':')) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		fn_while_dir(array, spl, 0);
		chdir(array->pwd.path.buff);
	}
	array->lp_spl_path = spl;
	ft_42sh_auto_create_array(array);
}
