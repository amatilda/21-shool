/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_cm.h"

static void		fn_err(register t_main_42sh *array,
register unsigned char *str)
{
	if (str[0] == '-' && str[1] != 0)
	{
		ft_42sh_dsp_err_msg_add_n(array, MSG_TEST_UNK_COND_42SH, (void *)str, 0);
		array->env.exit_status->number = STATUS_TEST_ERR_42SH;
		return ;
	}
	ft_42sh_dsp_err_msg_add_n(array, MSG_TEST_COND_42SH, (void *)str, 0);
	return ;
}

static void		fn_test(register t_main_42sh *array, register size_t out,
register uint_fast8_t b_test)
{
	if ((ssize_t)out == STATUS_REZERVED_42SH)
		return ;
	if (b_test == 0)
	{
		array->env.exit_status->number = out;
		return ;
	}
	array->env.exit_status->number = (out == STATUS_FALTURE_42SH) ?
	STATUS_OK_42SH : STATUS_FALTURE_42SH;
}

static void		fn_stub(register t_main_42sh *array,
register unsigned char *str, uint_fast8_t b_test)
{
	return (fn_test(array, (str[0] != 0) ?
	STATUS_OK_42SH : STATUS_FALTURE_42SH, b_test));
}

void			ft_42sh_cm_test(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char			*str;
	register unsigned char			*two;
	uint_fast8_t					b_test;

	if ((str = (void *)lp_arg[0]) != 0 && str[0] == '!' && str[1] == 0)
	{
		b_test = 1;
		lp_arg++;
	}
	else
		b_test = 0;
	if ((str = (void *)lp_arg++[0]) == 0)
		return (fn_test(array, STATUS_FALTURE_42SH, b_test));
	if (str[0] == '-' && str[1] != 0 && str[2] == 0)
	{
		return (fn_test(array, ft_42sh_cm_test_two(array, lp_arg, str),
		b_test));
	}
	else if (lp_arg[0] == 0)
		return (fn_stub(array, str, b_test));
	if ((two = (void *)lp_arg[1]) == 0)
		return (fn_err(array, str));
	return (fn_test(array, ft_42sh_cm_test_three(array, str,
	(void *)lp_arg[0], two), b_test));
}
