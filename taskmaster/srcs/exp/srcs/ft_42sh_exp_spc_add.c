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
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
}

static void			fn_path(register t_main_42sh *array,
register t_env_42sh *list)
{
	register char				**spl;

	if ((spl = array->lp_spl_path) != 0)
		ft_strsplit_free(spl);
	if ((array->lp_spl_path = ft_strsplit(list->lp_value, ':')) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	ft_42sh_auto_free_all_cmd(array);
	ft_42sh_auto_create(array);
}

static void			fn_home(register t_main_42sh *array,
register t_env_42sh *list)
{
	array->home.lp_home = list->lp_value;
	array->home.count_home = list->value_count;
}

static void			fn_ps2(register t_main_42sh *array,
register t_env_42sh *list)
{
	register unsigned char		*tmp;
	t_shield_out_42sh			lp;

	if ((tmp = (void *)array->msg.hrdc) != 0)
		ft_free(tmp);
	tmp = (void *)list->lp_value;
	array->msg.hrdc = ft_42sh_str_shield(tmp, tmp + list->value_count,
	SHIELD_EXTERNALLY, &lp);
	array->msg.hrdc_lit = lp.count_litter;
}

t_env_42sh			*ft_42sh_exp_spc_add(register t_main_42sh *array,
register t_env_42sh *list)
{
	register size_t				n;
	register char				*key;

	if (list == 0)
	{
		ft_42sh_exp_spc_correction(array, list);
		return (list);
	}
	key = list->std.lp_key;
	n = list->std.key_count;
	if (n == (sizeof(EXP_HOME_42SH) - 1) && ft_strncmp(key,
	EXP_HOME_42SH, n) == 0)
		fn_home(array, list);
	else if (n == (sizeof(EXP_PS2_42SH) - 1) && ft_strncmp(key,
	EXP_PS2_42SH, n) == 0)
		fn_ps2(array, list);
	else if (n == (sizeof(EXP_PATH_42SH) - 1) &&
	ft_strncmp(key, EXP_PATH_42SH, n) == 0)
		fn_path(array, list);
	else if (n == (sizeof(EXP_CDPATH_42SH) - 1) &&
	ft_strncmp(key, EXP_CDPATH_42SH, n) == 0)
		fn_cd(array, list);
	ft_42sh_exp_spc_correction(array, list);
	return (list);
}
