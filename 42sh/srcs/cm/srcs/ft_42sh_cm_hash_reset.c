/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_hash_reset.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

void			ft_42sh_cm_hash_reset(register t_main_42sh *array,
register char **lp_arg)
{
	if (lp_arg[0] != 0)
	{
		return (ft_42sh_dsp_err_msg(array,
		WAR_42SH""MSG_HASH_TOO_ARG_TXT_42SH""PRTF_RESET));
	}
	ft_42sh_auto_free_all_cmd(array);
	ft_42sh_auto_create(array);
	array->b_hash = HASH_NOT_42SH;
}
