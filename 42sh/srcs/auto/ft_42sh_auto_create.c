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

#include "includes/ft_42sh_auto.h"

static void				fn_add_list(register t_main_42sh *array,
register char *lp_key, register void *str, uint_fast8_t b_type)
{
	register void			*b;

	b = ft_42sh_str_shield((void *)lp_key,
	(void *)lp_key + ft_strlen(lp_key), SHIELD_EXTERNALLY, 0);
	ft_42sh_auto_sort_paste(array, b, str, b_type);
	ft_free(b);
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
				if (stat((tmp = dp->d_name), &st) == 0)
				{
					md = st.st_mode;
					if ((md & S_IFMT) != S_IFDIR &&
					((md & S_IXUSR) | (md & S_IXGRP) | (md & S_IXOTH)) != 0)
						fn_add_list(array, tmp, slesh, AUTO_TYPE_EXE_42SH);
				}
			}
			closedir(dirp);
		}
	}
}

void					ft_42sh_auto_create_array(register t_main_42sh *array,
register t_all_cmd_42sh *list, register size_t count)
{
	register t_all_cmd_42sh		**spl;

	if ((spl = ft_malloc(sizeof(t_all_cmd_42sh *) * (count + 1))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	spl[count] = 0;
	array->lp_auto->spl_all_cmd = spl;
	while (list != 0)
	{
		spl++[0] = list;
		list = (void *)list->std.next;
	}
}

static void				fn_add_bultin(register t_main_42sh *array)
{
	fn_add_list(array, MSG_EXPR_42SH, &ft_42sh_cm_export, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, "true", &ft_42sh_cm_true, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, "false", &ft_42sh_cm_false, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, "echo", &ft_42sh_cm_echo, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_EXIT_42SH, &ft_42sh_cm_exit, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_CD_42SH, &ft_42sh_cm_cd, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_TYPE_42SH, &ft_42sh_cm_type, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_SET_42SH, &ft_42sh_cm_set, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_UNSET_42SH, &ft_42sh_cm_unset, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_ALIAS_42SH, &ft_42sh_alias, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_UNALIAS_42SH, &ft_42sh_alias_un, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_JOBS_42SH, &ft_42sh_cm_jobs, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_FG_42SH, &ft_42sh_cm_fg, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_BG_42SH, &ft_42sh_cm_bg, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_HASH_42SH, &ft_42sh_cm_hash, AUTO_TYPE_FUN_42SH);
	fn_add_list(array, MSG_TEST_42SH, &ft_42sh_cm_test, AUTO_TYPE_FUN_42SH);
	ft_42sh_task_add_bultin(array, fn_add_list);
}

void					ft_42sh_auto_create(register t_main_42sh *array)
{
	register char							**spl;
	register t_pguitar_alias_42sh			*list;

	array->lp_auto->count_all = 0;
	array->lp_auto->max_litter = 0;
	fn_add_bultin(array);
	if ((spl = array->lp_spl_path) != 0)
	{
		fn_while_dir(array, spl, 0);
		chdir(array->pwd.path.buff);
	}
	list = array->pguitar.list;
	while (list != 0)
	{
		ft_42sh_auto_sort_paste(array, list->name, 0, AUTO_TYPE_ALIAS_42SH);
		list = list->next;
	}
	ft_42sh_auto_create_array(array, array->lp_auto->all_cmd.first,
	array->lp_auto->count_all);
}
