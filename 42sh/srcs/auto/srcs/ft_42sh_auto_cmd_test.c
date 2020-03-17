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

#include "../includes/ft_42sh_auto.h"

static t_all_cmd_42sh	**fn_add_str(register t_main_42sh *array,
register t_in_42sh *list, register t_all_cmd_42sh *cmd, register size_t n)
{
	t_add_litter_42sh			in;

	in.count = cmd->std.key_count - n;
	in.count_litter = cmd->std.key_litter - array->lp_auto->auto_litter_len;
	ft_42sh_str(array, list, (void *)(cmd->std.lp_key + n), &in);
	in.count = 1;
	in.count_litter = 1;
	if (array->lp_auto == &array->auto_file)
	{
		ft_42sh_str(array, list, (void *)&array->auto_file.spec_sym, &in);
		ft_42sh_auto_toogle(array);
	}
	else
		ft_42sh_str(array, list, (void *)" ", &in);
	return (0);
}

static size_t			fn_pre(register t_all_cmd_42sh *cmd,
register t_all_cmd_42sh **spl_end)
{
	register char					*s1;
	register char					*s2;
	register size_t					n;
	register size_t					i;

	s1 = cmd->std.lp_key;
	s2 = spl_end[0]->std.lp_key;
	n = cmd->std.key_count;
	i = 0;
	while (i < n && s1[i] == s2[i])
		i++;
	return (i);
}

static void				fn_set_count_litter(register t_main_42sh *array,
t_add_litter_42sh *in, register void *str, register size_t count)
{
	in->count_litter = ft_strlen_utf8_n(str, str + count) -
	array->lp_auto->auto_litter_len;
}

t_all_cmd_42sh			**ft_42sh_auto_cmd_test(register t_main_42sh *array,
register t_in_42sh *list, register t_all_cmd_42sh **spl,
register t_all_cmd_42sh **spl_end)
{
	register t_all_cmd_42sh			*cmd;
	t_add_litter_42sh				in;
	register size_t					n;
	register size_t					count;

	spl_end--;
	cmd = spl[0];
	n = array->lp_auto->auto_len;
	if (array->lp_auto != &array->auto_env && cmd == spl_end[0])
		return (fn_add_str(array, list, cmd, n));
	else if (ft_42sh_auto_cmd_test_env(array, list, spl, spl_end) == 0)
		return (0);
	count = fn_pre(cmd, spl_end);
	if (n < count)
	{
		in.count = count - n;
		fn_set_count_litter(array, &in, cmd->std.lp_key, count);
		ft_42sh_str(array, list, (void *)(cmd->std.lp_key + n), &in);
		if (array->lp_auto != &array->auto_env)
			return (0);
	}
	spl_end += spl_end[0] != 0 ? 1 : 0;
	return (spl_end);
}
