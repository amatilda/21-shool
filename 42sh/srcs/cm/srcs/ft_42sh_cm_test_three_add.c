/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_test_three_add.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

size_t			ft_42sh_cm_test_three_err_unk(register t_main_42sh *array,
register unsigned char *eq)
{
	ft_42sh_dsp_err_msg_add_n(array,
	WAR_42SH""MSG_TEST_UNK_COND_TXT_42SH""PRTF_RESET, (void *)eq, 0);
	array->env.exit_status->number = STATUS_TEST_ERR_42SH;
	return (STATUS_REZERVED_42SH);
}

size_t			ft_42sh_cm_test_three_err_unk_not(register t_main_42sh *array,
register unsigned char *eq)
{
	ft_42sh_dsp_err_msg_add_n(array,
	WAR_42SH""MSG_TEST_COND_TXT_42SH""PRTF_RESET, (void *)eq, 0);
	return (STATUS_REZERVED_42SH);
}

size_t			ft_42sh_cm_test_three_number(register t_main_42sh *array,
register unsigned char *lp_number, register t_test_number_42sh *out)
{
	unsigned char					*lp_save;
	register unsigned char			litter;

	lp_save = lp_number;
	while ((litter = lp_number[0]) != 0 && litter < 0x20)
		lp_number++;
	if ((out->sig = litter) == '-' || litter == '+')
		lp_number++;
	while ((litter = lp_number[0]) == 0x30)
		lp_number++;
	if (litter == 0 || out->sig != '-')
		out->sig = 0;
	out->lp = lp_number;
	while ((litter = lp_number[0]) >= 0x30 && litter <= 0x39)
		lp_number++;
	if (litter != 0)
	{
		ft_42sh_dsp_err_msg_add_n(array,
		WAR_42SH""MSG_TEST_INT_TXT_42SH""PRTF_RESET, (void *)lp_save, 0);
		array->env.exit_status->number = STATUS_TEST_ERR_42SH;
		return (0);
	}
	out->n = (void *)lp_number - out->lp;
	return (1);
}
