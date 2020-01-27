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

static t_all_cmd_42sh		**fn_stub(register t_main_42sh *array)
{
	array->lp_auto->auto_litter_len = 0;
	ft_42sh_auto_limit(array, array->lp_auto->max_litter,
	array->lp_auto->spl_all_cmd, array->lp_auto->count_all);
	return (0);
}

static t_all_cmd_42sh		**fn_start(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *str, register size_t n)
{
	register t_all_cmd_42sh			**spl;
	register size_t					count;

	array->lp_auto->auto_len = n;
	if (str == 0)
		return (fn_stub(array));
	if ((spl = (t_all_cmd_42sh **)
	ft_42sh_spl_find((void **)array->lp_auto->spl_all_cmd,
	array->lp_auto->count_all, (char *)str, n)) == 0)
	{
		ft_write_buffer_str_zero(&array->out, "\x7");
		return (0);
	}
	array->lp_auto->auto_litter_len = ft_strlen_utf8_n((char *)str,
	(char *)(str + n));
	count = list->lp_current - (char *)str;
	if ((n -= count) != 0)
	{
		str += count;
		ft_42sh_dsp_caret_right(array, list,
		ft_strlen_utf8_n((char *)str, (char *)(str + n)), n);
	}
	return (spl);
}

void						ft_42sh_auto_cmd(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *str, register size_t n)
{
	register t_all_cmd_42sh			**spl;
	register t_all_cmd_42sh			**spl_end;
	register t_all_cmd_42sh			*cmd;
	register size_t					tempos;

	if ((spl = fn_start(array, list, str, n)) == 0)
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
	if ((spl_end = ft_42sh_auto_cmd_test(array, list, spl, spl_end)) == 0)
		return ;
	ft_42sh_auto_limit(array, tempos, spl, spl_end - spl);
}
