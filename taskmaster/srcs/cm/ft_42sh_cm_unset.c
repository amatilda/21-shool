/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_while(register t_main_42sh *array,
register char **lp_arg, register t_past_sort_42sh *root)
{
	register t_env_42sh			*list;
	register void				*key;

	if (root->first == 0)
		return ;
	while ((key = (void *)lp_arg++[0]) != 0)
	{
		if ((list = ft_42sh_list_find_key(root, key, ft_strlen(key))) == 0)
			continue ;
		if ((list->b_type & EXP_TYPE_R_ONLY_42SH) != 0)
		{
			ft_42sh_dsp_err_msg_add_n(array,
			WAR_42SH""MSG_UNSET_R_ONLY_TXT_42SH""PRTF_RESET,
			list->std.lp_key, list->std.key_count);
			continue ;
		}
		ft_42sh_exp_del(array, root, list);
	}
}

void			ft_42sh_cm_unset(register t_main_42sh *array,
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
	if (lp_arg[0] == 0)
	{
		return (ft_42sh_dsp_err_msg(array,
		WAR_42SH""MSG_UNSET_NOT_ARG_TXT_42SH""PRTF_RESET));
	}
	fn_while(array, lp_arg, &array->env.root);
}
