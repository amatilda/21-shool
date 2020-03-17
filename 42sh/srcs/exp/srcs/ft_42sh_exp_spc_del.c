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
void				ft_42sh_exp_spc_del(register t_main_42sh *array,
register unsigned char *key, register size_t n)
{
	register char				**spl;

	if (n == LEN_(EXP_HOME_42SH) && ft_strncmp(key, EXP_HOME_42SH, n) == 0)
		array->lp_home = 0;
	else if (n == LEN_(EXP_PATH_42SH) && ft_strncmp(key, EXP_PATH_42SH, n) == 0)
		fn_path(array);
	else if (n == LEN_(EXP_CDPATH_42SH) &&
	ft_strncmp(key, EXP_CDPATH_42SH, n) == 0)
	{
		if ((spl = array->pwd.spl_cd) != 0)
		{
			array->pwd.spl_cd = 0;
			ft_strsplit_free(spl);
		}
	}
}
