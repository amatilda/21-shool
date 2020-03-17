/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exe.h"

void				ft_42sh_exe_set_(register t_main_42sh *array,
register t_exp_set_42sh *exp_set, size_t b_type)
{
	register unsigned char			*key;
	register unsigned char			*value;
	t_add_exp_42sh					in;

	in.b_type = b_type;
	while (exp_set != 0)
	{
		key = exp_set->lp;
		value = key;
		while (value++[0] != '=')
			;
		in.value = value;
		in.value_end = key + exp_set->n;
		ft_42sh_exp_add(array, key, value - 1, &in);
		exp_set = exp_set->next;
	}
}

void				ft_42sh_exe_set(register t_main_42sh *array,
register char **lp_arg)
{
	ft_42sh_exe_set_(array, (t_exp_set_42sh *)lp_arg, EXP_TYPE_LOCAL_42SH);
}
