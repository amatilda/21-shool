/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_test_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

static size_t	fn_stub_eq(t_test_number_42sh *in_fr,
t_test_number_42sh *in_tw)
{
	if ((in_fr->sig != 0 && in_tw->sig == 0) ||
	(in_fr->sig == in_tw->sig && ft_strcmp(in_fr->lp, in_tw->lp) <= 0))
		return (STATUS_OK_42SH);
	return (STATUS_FALTURE_42SH);
}

static size_t	fn_test_eq(register t_main_42sh *array,
register unsigned char *first, register unsigned char *eq,
register unsigned char *two)
{
	register unsigned char			fr;
	t_test_number_42sh				in_fr;
	t_test_number_42sh				in_tw;

	if (ft_42sh_cm_test_three_number(array, first, &in_fr) == 0 ||
	ft_42sh_cm_test_three_number(array, two, &in_tw) == 0)
		return (STATUS_REZERVED_42SH);
	if ((fr = eq[1]) == 'n')
	{
		if (in_fr.sig != in_tw.sig || ft_strcmp(in_fr.lp, in_tw.lp) != 0)
			return (STATUS_OK_42SH);
		return (STATUS_FALTURE_42SH);
	}
	if (fr == 'g')
	{
		if ((in_fr.sig == 0 && in_tw.sig != 0) ||
		(in_fr.sig == in_tw.sig && ft_strcmp(in_fr.lp, in_tw.lp) >= 0))
			return (STATUS_OK_42SH);
		return (STATUS_FALTURE_42SH);
	}
	if (fr == 'l')
		return (fn_stub_eq(&in_fr, &in_tw));
	return (ft_42sh_cm_test_three_err_unk(array, eq));
}

static size_t	fn_test_glt(register t_main_42sh *array,
register unsigned char *first, register unsigned char *eq,
register unsigned char *two)
{
	register unsigned char			fr;
	t_test_number_42sh				in_fr;
	t_test_number_42sh				in_tw;

	if (ft_42sh_cm_test_three_number(array, first, &in_fr) == 0 ||
	ft_42sh_cm_test_three_number(array, two, &in_tw) == 0)
		return (STATUS_REZERVED_42SH);
	if ((fr = eq[1]) == 'g')
	{
		if ((in_fr.sig == 0 && in_tw.sig != 0) ||
		(in_fr.sig == in_tw.sig && ft_strcmp(in_fr.lp, in_tw.lp) > 0))
			return (STATUS_OK_42SH);
		return (STATUS_FALTURE_42SH);
	}
	if (fr == 'l')
	{
		if ((in_fr.sig != 0 && in_tw.sig == 0) ||
		(in_fr.sig == in_tw.sig && ft_strcmp(in_fr.lp, in_tw.lp) < 0))
			return (STATUS_OK_42SH);
		return (STATUS_FALTURE_42SH);
	}
	return (ft_42sh_cm_test_three_err_unk(array, eq));
}

static size_t	fn_test_cond(register t_main_42sh *array,
register unsigned char *first, register unsigned char *eq,
register unsigned char *two)
{
	register unsigned char			fr;
	register unsigned char			tw;
	t_test_number_42sh				in_fr;
	t_test_number_42sh				in_tw;

	fr = eq[0];
	if (fr != '-' || (fr = eq[1]) == 0 || eq[2] == 0 || eq[3] != 0)
	{
		ft_42sh_dsp_err_msg_add_n(array, MSG_TEST_COND_42SH, (void *)eq, 0);
		return (STATUS_REZERVED_42SH);
	}
	if ((tw = eq[2]) == 'e')
		return (fn_test_eq(array, first, eq, two));
	if (tw == 't')
		return (fn_test_glt(array, first, eq, two));
	if (fr == 'e' && tw == 'q')
	{
		if (ft_42sh_cm_test_three_number(array, first, &in_fr) == 0 ||
		ft_42sh_cm_test_three_number(array, two, &in_tw) == 0)
			return (STATUS_REZERVED_42SH);
		if (in_fr.sig == in_tw.sig && ft_strcmp(in_fr.lp, in_tw.lp) == 0)
			return (STATUS_OK_42SH);
		return (STATUS_FALTURE_42SH);
	}
	return (ft_42sh_cm_test_three_err_unk(array, eq));
}

size_t			ft_42sh_cm_test_three(register t_main_42sh *array,
register unsigned char *first, register unsigned char *eq,
register unsigned char *two)
{
	register unsigned char			litter;

	if ((litter = eq[0]) == '=' && eq[1] == 0)
	{
		if (ft_strcmp((void *)first, (void *)two) == 0)
			return (STATUS_OK_42SH);
		return (STATUS_FALTURE_42SH);
	}
	if (litter == '!' && eq[1] == '=' && eq[2] == 0)
	{
		if (ft_strcmp((void *)first, (void *)two) != 0)
			return (STATUS_OK_42SH);
		return (STATUS_FALTURE_42SH);
	}
	return (fn_test_cond(array, first, eq, two));
}