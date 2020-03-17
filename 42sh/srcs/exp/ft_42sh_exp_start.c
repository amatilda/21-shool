/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_exp.h"

static void			fn_set(register t_main_42sh *array)
{
	t_add_exp_42sh					in;
	register void					*key;
	register t_env_42sh				*list;

	in.value = 0;
	in.value_end = 0;
	in.b_type = (EXP_TYPE_NUMBER_42SH | EXP_TYPE_R_ONLY_42SH | EXP_TYPE_LOCAL_42SH);
	key =  "?";
	list = ft_42sh_exp_add(array, key, key + 1, &in);
	list->number = 0;
	array->env.exit_status = list;
}

void				ft_42sh_exp_start(register t_main_42sh *array,
register char **env)
{
	register unsigned char			*key;
	register unsigned char			*value;
	register unsigned char			*value_end;
	t_add_exp_42sh					in;

	if (env[0] == 0)
		return ;
	while ((key = (void *)env++[0]) != 0)
	{
		value_end = key + ft_strlen((void *)key);
		if ((value = ft_42sh_exp_test_exp(key, value_end)) == 0)
			continue ;
		in.value = value;
		in.value_end = value_end;
		in.b_type = EXP_TYPE_EVERIMENT_42SH;
		ft_42sh_exp_add(array, key, value - 1, &in);
	}
	fn_set(array);
	ft_42sh_exp_standart(array);
}
