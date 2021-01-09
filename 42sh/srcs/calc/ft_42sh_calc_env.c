/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_calc_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_calc.h"

void			ft_42sh_calc_set_env(register void *array,
register void *b, register size_t number)
{
	register t_env_42sh				*list;
	t_add_exp_42sh					in;
	register size_t					n;

	if (((char *)b)[0] == '$')
		b++;
	n = ft_strlen(b);
	if (n == 0)
		return ;
	in.value = 0;
	in.value_end = 0;
	in.b_type = (EXP_TYPE_NUMBER_42SH | EXP_TYPE_LOCAL_42SH);
	list = ft_42sh_exp_add(array, b, b + n, &in);
	list->number = number;
}

void			*ft_42sh_calc_get_env(register void *array,
register void *b)
{
	register t_env_42sh				*list;
	register size_t					n;

	if (((char *)b)[0] == '$')
		b++;
	n = ft_strlen(b);
	if (n == 0 || (list = ft_42sh_list_find_key(&((t_main_42sh *)
	array)->env.root, b, n)) == 0)
		return (ft_strdup("0"));
	n = ft_42sh_exp_parsing_value_count(array, list, PARSING_MODE_CMD_42SH);
	if ((b = ft_malloc(n + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	((char *)b)[n] = 0;
	ft_42sh_exp_parsing_value(array, list, b, PARSING_MODE_CMD_42SH);
	return (b);
}
