/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_env_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_env_42sh			*ft_42sh_env_create(register char *key,
register size_t key_count, register char *value, register size_t value_count)
{
	register t_env_42sh		*out;
	register char			*tmp;

	if ((out = ft_malloc(sizeof(t_env_42sh) + key_count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	if ((tmp = ft_malloc(value_count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	out->lp_value = tmp;
	out->value_count = value_count;
	tmp[value_count] = 0;
	ft_memcpy(tmp, value, value_count);
	out->std.key_count = key_count;
	tmp = out->key;
	out->std.lp_key = tmp;
	tmp[key_count] = 0;
	ft_memcpy(tmp, key, key_count);
	return (out);
}
