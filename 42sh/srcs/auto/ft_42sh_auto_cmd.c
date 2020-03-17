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

#include "includes/ft_42sh_auto.h"

static void				fn_offset(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *str, register size_t n)
{
	register size_t					count;

	count = list->lp_current - (char *)str;
	if (n > count)
	{
		str += count;
		n = n - count;
		ft_42sh_dsp_caret_right(array, list, ft_42sh_parsing_litter_n((char *)str,
		(char *)(str + n)), n);
	}
	else if (count > n)
	{
		str += n;
		n = count - n;
		ft_42sh_dsp_caret_left(array, list, ft_42sh_parsing_litter_n((char *)str,
		(char *)(str + n)), n);
	}
}

t_all_cmd_42sh			**fn_test(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b, register size_t n)
{
	register t_all_cmd_42sh			**spl;

	if ((spl = (t_all_cmd_42sh **)
	ft_42sh_spl_find((void **)array->lp_auto->spl_all_cmd,
	array->lp_auto->count_all, (char *)b, n)) == 0)
	{
		if (ft_42sh_auto_cmd_env_replase(array, list, b) == 0)
			ft_write_buffer_str_zero(&array->out, "\x7");
		ft_42sh_auto_toogle(array);
		return (0);
	}
	return (spl);
}

static t_all_cmd_42sh	**fn_start(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *str, register size_t n)
{
	register t_all_cmd_42sh			**spl;

	array->lp_auto->auto_len = n;
	if (str == 0)
	{
		array->lp_auto->auto_litter_len = 0;
		ft_42sh_auto_limit(array, array->lp_auto->max_litter,
		array->lp_auto->spl_all_cmd, array->lp_auto->count_all);
		return (0);
	}
	if (array->lp_auto == &array->auto_env && array->pguitar.comp.figure != 0)
	{
		array->env.lp_end_exp = str - array->env.offset_auto;
		array->env.n_exp = 0;
		array->env.b_exp_err = ft_42sh_auto_cmd_env_close_while_count(
			&array->env.lp_end_exp, (void *)list->lp_current,
			&array->env.n_exp);
	}
	if ((spl = fn_test(array, list, str, n)) == 0)
		return (0);
	array->lp_auto->auto_litter_len = ft_strlen_utf8_n((char *)str,
	(char *)(str + n));
	fn_offset(array, list, str, n);
	return (spl);
}

void					ft_42sh_auto_cmd(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *str, register size_t n)
{
	register t_all_cmd_42sh			**spl;
	register t_all_cmd_42sh			**spl_end;
	register t_all_cmd_42sh			*cmd;
	register size_t					tempos;

	n = ft_42sh_auto_cmd_env_corection(array, list, str, n);
	if (array->env.offset_auto == 3)
		str++;
	if ((spl = fn_start(array, list, str, n)) == 0)
		return ;
	spl_end = spl + 1;
	tempos = spl[0]->std.key_litter;
	while ((cmd = spl_end[0]) != 0 && cmd->std.key_count >= n &&
	ft_strncmp((char *)str, cmd->std.lp_key, n) == 0)
	{
		if (cmd->std.key_litter > tempos)
			tempos = cmd->std.key_litter;
		spl_end++;
	}
	if ((spl_end = ft_42sh_auto_cmd_test(array, list, spl, spl_end)) == 0)
		return ;
	ft_42sh_auto_limit(array, tempos, spl, spl_end - spl);
}
