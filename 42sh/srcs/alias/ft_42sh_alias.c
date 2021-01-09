/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:07:32 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:07:38 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_alias.h"

void			ft_42sh_alias(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char			*str;
	register unsigned char			litter;

	while ((str = (void *)lp_arg[0]) != 0 && str++[0] == '-')
	{
		lp_arg++;
		if ((litter = str[0]) == 0 || (litter == '-' && str[1] == 0))
			break ;
		str++;
		return (ft_42sh_dsp_err_msg_add_n(array,
		WAR_PR_42SH""MSG_BAD_OPTION_TXT_42SH""PRTF_RESET"-",
		(void *)str - 1, ft_strlen_utf8_litter(str - 1)));
	}
	ft_42sh_alias_pars(array, lp_arg);
}
