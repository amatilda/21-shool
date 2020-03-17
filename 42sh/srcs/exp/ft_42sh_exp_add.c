/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_exp.h"

static t_env_42sh	*fn_first(register t_main_42sh *array,
register unsigned char *key, register unsigned char *key_end,
register t_add_exp_42sh *in)
{
	register t_env_42sh			*list;
	register t_past_sort_42sh	*root;

	root = &array->env.root;
	if (root->first != 0)
		return (0);
	array->env.count_env = 0;
	array->env.count_local = 0;
	list = ft_42sh_exp_create(array, key, key_end, in);
	root->first = list;
	root->center = list;
	root->last = list;
	return (list);
}

t_env_42sh			*ft_42sh_exp_add(register t_main_42sh *array,
register unsigned char *key, register unsigned char *key_end,
register t_add_exp_42sh *in)
{
	register t_env_42sh			*list;

	if ((list = fn_first(array, key, key_end, in)) != 0)
		return (ft_42sh_exp_spc_add(array, list));
	list = ft_42sh_exp_sort_paste(array, key, key_end, in);
	return (ft_42sh_exp_spc_add(array, list));
}
