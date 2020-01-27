/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_cmd_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void				fn_add_str(register t_main_42sh *array,
register t_in_42sh *list, register t_all_cmd_42sh *cmd, register size_t n)
{
	t_add_litter_42sh			in;

	in.count = cmd->std.key_count - n;
	in.count_litter = cmd->key_litter - array->lp_auto->auto_litter_len;
	ft_42sh_str(array, list, (void *)(cmd->std.lp_key + n), &in);
	in.count = 1;
	in.count_litter = 1;
	if (array->lp_auto == &array->auto_file)
	{
		ft_42sh_str(array, list, (void *)"/", &in);
		ft_42sh_auto_toogle(array);
	}
	else
		ft_42sh_str(array, list, (void *)" ", &in);
}

static size_t			fn_root(register char *s1,
register char *s2, register size_t n)
{
	register size_t					i;

	i = 0;
	while (i < n && s1[i] == s2[i])
		i++;
	return (i);
}

t_all_cmd_42sh			**ft_42sh_auto_cmd_test(register t_main_42sh *array,
register t_in_42sh *list, register t_all_cmd_42sh **spl,
register t_all_cmd_42sh **spl_end)
{
	t_add_litter_42sh				in;
	register t_all_cmd_42sh			*cmd;
	register size_t					n;
	register size_t					count;
	register size_t					count_litter;

	spl_end--;
	n = array->lp_auto->auto_len;
	if ((cmd = spl[0]) == spl_end[0])
	{
		fn_add_str(array, list, cmd, n);
		return (0);
	}
	count = fn_root(cmd->std.lp_key, spl_end[0]->std.lp_key,
	cmd->std.key_count);
	count_litter = ft_strlen_utf8_n(cmd->std.lp_key, cmd->std.lp_key + count);
	if (n < count)
	{
		in.count = count - n;
		in.count_litter = count_litter - array->lp_auto->auto_litter_len;
		ft_42sh_str(array, list, (void *)(cmd->std.lp_key + n), &in);
		return (0);
	}
	spl_end += spl_end[0] != 0 ? 1 : 0;
	return (spl_end);
}
