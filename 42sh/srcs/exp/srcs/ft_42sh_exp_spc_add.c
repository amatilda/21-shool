/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_spc_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static void			fn_cd(register t_main_42sh *array,
register t_env_42sh *list)
{
	register char				**spl;

	if ((spl = array->pwd.spl_cd) != 0)
		ft_strsplit_free(spl);
	if ((array->pwd.spl_cd = ft_strsplit(list->lp_value, ':')) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
}

static void			fn_path(register t_main_42sh *array,
register t_env_42sh *list)
{
	register char				**spl;

	if ((spl = array->lp_spl_path) != 0)
		ft_strsplit_free(spl);
	if ((array->lp_spl_path = ft_strsplit(list->lp_value, ':')) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	if (array->lp_auto->all_cmd.first != 0)
		ft_42sh_auto_free_all_cmd(array);
	ft_42sh_auto_create(array);
}

t_env_42sh			*ft_42sh_exp_spc_add(register t_main_42sh *array,
register t_env_42sh *list)
{
	register size_t				n;

	if (list == 0 || (list->b_type & EXP_TYPE_EVERIMENT_42SH) == 0)
	{
		ft_42sh_exp_spc_correction(array, list);
		return (list);
	}
	n = list->std.key_count;
	if (n == LEN_(EXP_HOME_42SH) &&
	ft_strncmp(list->std.lp_key, EXP_HOME_42SH, n) == 0)
	{
		array->lp_home = list->lp_value;
		array->count_home = list->value_count;
	}
	else if (n == LEN_(EXP_PATH_42SH) &&
	ft_strncmp(list->std.lp_key, EXP_PATH_42SH, n) == 0)
		fn_path(array, list);
	else if (n == LEN_(EXP_CDPATH_42SH) &&
	ft_strncmp(list->std.lp_key, EXP_CDPATH_42SH, n) == 0)
		fn_cd(array, list);
	ft_42sh_exp_spc_correction(array, list);
	return (list);
}
