/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		ft_42sh_cm_exit(register t_main_42sh *array,
register char **lp_arg)
{
	ft_write_buffer(&array->out);
	ft_42sh_auto_free_all_cmd(array);
	if (array->lp_spl_path != 0)
		ft_strsplit_free(array->lp_spl_path);
	free(array->pwd.path.buff);
	free(array->pwd.prev_path.buff);
	ft_42sh_list_fun(&array->env.env, ft_42sh_env_free);
	exit(E_CODE_42SH);
	(void)lp_arg;
}
