/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_env_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

char			**ft_42sh_env_split(register t_std_key_42sh *list,
register size_t count)
{
	register char				**spl;
	register char				*str;
	register size_t				value_count;
	char						**tmp;

	if ((spl = malloc(sizeof(char *) * (count + 1))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	spl[count] = 0;
	tmp = spl;
	while (list != 0)
	{
		count = list->key_count;
		value_count = ((t_env_42sh *)list)->value_count;
		if ((str = malloc(count + value_count + 1 + 1)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		spl++[0] = str;
		ft_memcpy(str, list->lp_key, count);
		str += count;
		str++[0] = '=';
		ft_memcpy(str, ((t_env_42sh *)list)->lp_value, value_count);
		str[value_count] = 0;
		list = list->next;
	}
	return (tmp);
}
