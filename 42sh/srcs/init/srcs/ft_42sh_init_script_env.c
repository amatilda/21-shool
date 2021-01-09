/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init_script_env.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_init.h"

static void	fn_arg(register t_main_42sh *array, register char **lp_arg)
{
	register unsigned char		*tmp;
	register size_t				tempos;
	register size_t				count;
	t_add_exp_42sh				in;
	char						buff[sizeof(uintmax_t) * 3];

	tempos = 0;
	while ((tmp = (void *)lp_arg++[0]) != 0)
	{
		count = ft_itoa(buff, tempos++, 10, ITOA_LOWER);
		in.value = tmp;
		in.value_end = tmp + ft_strlen((void *)tmp);
		in.b_type = EXP_TYPE_LOCAL_42SH;
		ft_42sh_exp_add(array, (void *)buff, (void *)(buff + count), &in);
	}
}

void		ft_42sh_init_script_env(register t_main_42sh *array,
register char **env, register char **lp_arg)
{
	t_past_sort_42sh		root;

	root = array->env.root;
	array->env.root.first = 0;
	ft_42sh_exp_start(array, env);
	ft_42sh_list_fun(&root, ft_free);
	ft_free(env);
	fn_arg(array, lp_arg);
}
