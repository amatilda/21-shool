/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_spc_del.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static void			fn_path(register t_main_42sh *array)
{
	register char				**spl;

	if ((spl = array->lp_spl_path) != 0)
	{
		array->lp_spl_path = 0;
		ft_strsplit_free(spl);
	}
	ft_42sh_auto_free_all_cmd(array);
	ft_42sh_auto_create(array);
}

static void			fn_ps2(register t_main_42sh *array)
{
	ft_free(array->msg.hrdc);
	if ((array->msg.hrdc =
	ft_strdup(PRTF_BOLT""MSG_HEREDOC_42SH""PRTF_RESET)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	array->msg.hrdc_lit = PRE_MSG_HEREDOC_LITTER_42SH;
}

void				ft_42sh_exp_spc_del(register t_main_42sh *array,
register unsigned char *key, register size_t n)
{
	register char				**spl;

	if (n == (sizeof(EXP_HOME_42SH) - 1) &&
	ft_strncmp(key, EXP_HOME_42SH, n) == 0)
		array->home.lp_home = 0;
	else if (n == (sizeof(EXP_PS2_42SH) - 1) &&
	ft_strncmp(key, EXP_PS2_42SH, n) == 0)
		fn_ps2(array);
	else if (n == (sizeof(EXP_PATH_42SH) - 1) &&
	ft_strncmp(key, EXP_PATH_42SH, n) == 0)
		fn_path(array);
	else if (n == (sizeof(EXP_CDPATH_42SH) - 1) &&
	ft_strncmp(key, EXP_CDPATH_42SH, n) == 0)
	{
		if ((spl = array->pwd.spl_cd) != 0)
		{
			array->pwd.spl_cd = 0;
			ft_strsplit_free(spl);
		}
	}
}
