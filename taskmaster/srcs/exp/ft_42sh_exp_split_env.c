/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_split_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_while(register char **spl,
register t_std_key_42sh *list)
{
	while (list != 0)
	{
		if ((((t_env_42sh *)list)->b_type & EXP_TYPE_EVERIMENT_42SH) != 0)
			spl++[0] = list->lp_key;
		list = list->next;
	}
}

char			**ft_42sh_exp_split_env(register t_main_42sh *array,
size_t b_exit)
{
	register size_t				count;
	register char				**spl;

	count = array->env.count_env;
	if ((spl = ft_malloc(sizeof(char *) * (count + 1))) == 0)
	{
		if (b_exit == 0)
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
		else
			exit(b_exit);
	}
	spl[count] = 0;
	fn_while(spl, array->env.root.first);
	return (spl);
}
