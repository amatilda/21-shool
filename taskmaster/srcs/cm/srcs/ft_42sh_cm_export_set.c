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

static size_t	fn_find(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e)
{
	register t_env_42sh			*list;
	register size_t				b_type;

	if ((list = ft_42sh_list_find_key(&array->env.root, b, e - b)) == 0)
		return (1);
	if (((b_type = list->b_type) & EXP_TYPE_LOCAL_42SH) != 0)
	{
		array->env.count_env++;
		array->env.count_local--;
		b_type = b_type ^ EXP_TYPE_LOCAL_42SH;
		list->b_type = b_type | EXP_TYPE_EVERIMENT_42SH;
	}
	return (0);
}

size_t			ft_42sh_cm_export_set_task(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char		*tmp;
	register unsigned char		*b;
	register unsigned char		*e;
	t_add_exp_42sh				in;

	if (lp_arg == 0)
		return (1);
	while ((b = (void *)lp_arg++[0]) != 0)
	{
		e = (void *)(b + ft_strlen((void *)b));
		if (fn_find(array, b, e) == 0)
			continue ;
		if ((tmp = ft_42sh_exp_name(b, e)) == b || (tmp < e && tmp[0] != '='))
			continue ;
		if (tmp != e)
			in.value = tmp + 1;
		else
			in.value = tmp;
		in.value_end = e;
		in.b_type = EXP_TYPE_EVERIMENT_42SH;
		if (ft_42sh_exp_add_task(array, b, tmp, &in) == 0)
			return (0);
	}
	return (1);
}

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
		if (fn_find(array, b, e) == 0)
			continue ;
		if ((tmp = ft_42sh_exp_name(b, e)) == b || (tmp < e && tmp[0] != '='))
		{
			ft_42sh_dsp_err_msg_add_n(array,
			WAR_42SH""MSG_EXPR_NOT_VALID_TXT_42SH""PRTF_RESET, (void *)b, 0);
			continue ;
		}
		if (tmp != e)
			in.value = tmp + 1;
		else
			in.value = tmp;
		in.value_end = e;
		in.b_type = EXP_TYPE_EVERIMENT_42SH;
		ft_42sh_exp_add(array, b, tmp, &in);
	}
}
