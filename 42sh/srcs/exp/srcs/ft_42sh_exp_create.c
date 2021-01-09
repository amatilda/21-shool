/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static size_t		fn_stub(register unsigned char *tmp,
register unsigned char *value, register size_t value_count)
{
	register unsigned char			*value_end;
	register unsigned char			litter;
	register size_t					count;

	tmp[value_count] = 0;
	value_end = value + value_count;
	count = 0;
	while (value < value_end)
	{
		if ((litter = value++[0]) == '\n')
			count++;
		tmp++[0] = litter;
	}
	return (count);
}

static void			fn_set(register t_env_42sh *out, register char *tmp,
register size_t key_count)
{
	out->std.next = 0;
	out->std.prev = 0;
	out->std.lp_key = tmp;
	out->std.key_litter = ft_strlen_utf8_n(tmp, tmp + key_count);
	out->std.key_count = key_count;
}

static void			fn_type(register t_main_42sh *array,
register t_env_42sh *out, register t_add_exp_42sh *in,
register size_t correction)
{
	register size_t			b_type;

	if (((b_type = in->b_type) & EXP_TYPE_EVERIMENT_42SH) != 0)
		array->env.count_env++;
	else
		array->env.count_local++;
	out->b_type = (b_type | correction);
}

t_env_42sh			*ft_42sh_exp_create(register t_main_42sh *array,
register unsigned char *key, register unsigned char *key_end,
register t_add_exp_42sh *in)
{
	register t_env_42sh		*out;
	register char			*tmp;
	register size_t			key_count;
	register size_t			value_count;
	register size_t			correction;

	key_count = key_end - key;
	value_count = in->value_end - in->value;
	correction = ft_42sh_exp_shield(in->value, in->value_end);
	if ((out = ft_malloc(sizeof(t_env_42sh) + key_count +
	value_count + 1 + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	fn_type(array, out, in, correction);
	out->value_count = value_count;
	tmp = out->key;
	ft_memcpy(tmp, key, key_count);
	fn_set(out, tmp, key_count);
	tmp[key_count] = '=';
	tmp += key_count + 1;
	out->lp_value = tmp;
	out->value_litter = ft_strlen_utf8_n(in->value, in->value + value_count);
	out->number = fn_stub((void *)tmp, in->value, value_count);
	return (out);
}
