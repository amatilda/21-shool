/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_type_msg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

static void		fn_alias(register t_main_42sh *array,
register t_write_buff *out, register t_all_cmd_42sh **spl)
{
	register unsigned char			*b;
	register size_t					n;
	register t_pguitar_alias_42sh	*alias;

	alias = array->pguitar.list;
	b = (void *)spl[0]->std.lp_key;
	n = spl[0]->std.key_count;
	while (alias != 0)
	{
		if (alias->n_cnt == n && ft_strncmp(alias->name, b, n) == 0)
			break ;
		alias = alias->next;
	}
	ft_write_buffer_str_zero(out, MSG_TYPE_ALIAS_42SH);
	ft_write_buffer_str_zero(out, alias->value);
}

void			ft_42sh_cm_type_msg(register t_main_42sh *array,
register t_write_buff *out, register t_all_cmd_42sh **spl,
register unsigned char *b)
{
	register size_t					b_type;

	b_type = spl[0]->b_type;
	if ((b_type & AUTO_TYPE_ALIAS_42SH) != 0)
		fn_alias(array, out, spl);
	else if ((b_type & AUTO_TYPE_HASH_42SH) != 0)
	{
		ft_write_buffer_str_zero(out, MSG_TYPE_HASH_42SH);
		ft_write_buffer_str_zero(out, spl[0]->path_hash);
	}
	else if ((b_type & AUTO_TYPE_FUN_42SH) != 0)
		ft_write_buffer_str_zero(out, MSG_TYPE_FUN_42SH);
	else if ((b_type & AUTO_TYPE_EXE_42SH) != 0)
	{
		ft_write_buffer_str_zero(out, MSG_TYPE_EXE_42SH);
		ft_write_buffer_str_zero(out, spl[0]->path);
		ft_write_buffer_str_zero(out, "/");
		ft_write_buffer_str_zero(out, (void *)b);
	}
}
