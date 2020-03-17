/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_spc_correction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

void			ft_42sh_exp_spc_correction(register t_main_42sh *array,
register t_env_42sh *list)
{
	register char				**spl;

	if (list == 0)
		return ;
	if ((spl = (char **)array->auto_env.spl_all_cmd) != 0)
	{
		array->auto_env.spl_all_cmd = 0;
		ft_free(spl);
	}
}
