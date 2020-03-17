/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_export_set.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

void			ft_42sh_cm_export_set(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char		*tmp;
	register unsigned char		*b;
	register unsigned char		*e;
	t_add_exp_42sh				in;

	while ((b = (void *)lp_arg++[0]) != 0)
	{
		e = (void *)(b + ft_strlen((void *)b));
		if ((tmp = ft_42sh_exp_test_exp(b, e)) == 0)
		{
			ft_42sh_dsp_err_msg_add_n(array, MSG_EXPR_NOT_V_42SH, (void *)b, 0);
			continue ;
		}
		in.value = tmp;
		in.value_end = e;
		in.b_type = EXP_TYPE_EVERIMENT_42SH;
		ft_42sh_exp_add(array, b, tmp - 1, &in);
	}
}