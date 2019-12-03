/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void					fn_add_str(register t_main_42sh *array,
register t_all_cmd_42sh *cmd, register size_t n, uint_fast8_t b_space)
{
	register t_in_42sh			*list;
	register char				*str;
	register char				*end;

	str = cmd->std.lp_key;
	end = str + cmd->std.key_count;
	str += n;
	list = array->in.in_current;
	ft_42sh_str(array, list, str, end);
	if (b_space != 0)
		ft_42sh_key_litter(array, list, b_space, 1);
}

static t_all_cmd_42sh		**fn_test(register t_main_42sh *array,
register t_all_cmd_42sh **spl, register t_all_cmd_42sh **spl_end,
register size_t n)
{
	register t_all_cmd_42sh			*cmd;

	spl_end--;
	cmd = spl[0];
	if (cmd->std.key_count == n && spl != spl_end)
		cmd = spl[1];
	if (cmd == spl_end[0])
	{
		fn_add_str(array, cmd, n, ' ');
		return (0);
	}
	if (spl_end[0]->std.key_count >= cmd->std.key_count &&
	ft_strncmp(spl_end[0]->key, cmd->key, cmd->std.key_count) == 0)
	{
		fn_add_str(array, cmd, n, 0);
		return (0);
	}
	spl_end += spl_end[1] != 0 ? 1 : 0;
	return (spl_end);
}

static t_all_cmd_42sh		**fn_start(register t_main_42sh *array,
register unsigned char *str, register size_t n)
{
	register t_all_cmd_42sh			**spl;

	array->tab.auto_len = n;
	if (str == 0)
	{
		array->tab.auto_litter_len = 0;
		ft_42sh_auto_limit(array, array->tab.max_litter,
		array->tab.spl_all_cmd, array->tab.count_all);
		return (0);
	}
	if ((spl = (t_all_cmd_42sh **)
	ft_42sh_spl_find((void **)array->tab.spl_all_cmd,
	array->tab.count_all, (char *)str, n)) == 0)
	{
		ft_write_buffer_str_zero(&array->out, "\x7");
		return (0);
	}
	return (spl);
}

void						ft_42sh_auto_cmd(register t_main_42sh *array,
register unsigned char *str, register size_t n)
{
	register t_all_cmd_42sh			**spl;
	register t_all_cmd_42sh			**spl_end;
	register t_all_cmd_42sh			*cmd;
	register size_t					tempos;

	if ((spl = fn_start(array, str, n)) == 0)
		return ;
	spl_end = spl + 1;
	tempos = spl[0]->key_litter;
	while ((cmd = spl_end[0]) != 0 &&
	ft_strncmp((char *)str, cmd->key, n) == 0)
	{
		if (cmd->key_litter > tempos)
			tempos = cmd->key_litter;
		spl_end++;
	}
	if ((spl_end = fn_test(array, spl, spl_end, n)) == 0)
		return ;
	array->tab.auto_litter_len = ft_strlen_utf8((char *)str);
	ft_42sh_auto_limit(array, tempos, spl, spl_end - spl);
}
