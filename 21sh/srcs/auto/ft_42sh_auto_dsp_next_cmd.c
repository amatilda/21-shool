/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_dsp_next_cmd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_start(register t_main_42sh *array, register t_in_42sh *list,
register t_all_cmd_42sh **spl, register size_t n)
{
	t_add_litter_42sh			in;

	in.count = spl[0]->std.key_count - n;
	in.count_litter = spl[0]->key_litter - array->lp_auto->auto_litter_len;
	ft_42sh_str(array, list, (void *)spl[0]->std.lp_key + n, &in);
	array->lp_auto->b_auto = 2;
}

void			ft_42sh_auto_dsp_next_cmd(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t				tempos;
	register size_t				n;
	register size_t				x;
	t_add_litter_42sh			in;
	register t_all_cmd_42sh		**spl;

	ft_42sh_dsp_clear_auto(array, list);
	spl = array->lp_auto->auto_spl;
	n = array->lp_auto->auto_len;
	x = array->lp_auto->auto_litter_len;
	if ((tempos = array->lp_auto->b_auto) == 1)
		return (fn_start(array, list, spl, n));
	tempos -= 2;
	ft_42sh_str_delete(array, list, list->lp_current -
	(spl[tempos]->std.key_count - n), spl[tempos]->key_litter - x);
	if (++tempos == array->lp_auto->auto_cmd)
		return (fn_start(array, list, spl, n));
	in.count = spl[tempos]->std.key_count - n;
	in.count_litter = spl[tempos]->key_litter - x;
	ft_42sh_str(array, list, (void *)spl[tempos]->std.lp_key + n, &in);
	array->lp_auto->b_auto = tempos + 2;
}

void			ft_42sh_auto_dsp_next_cmd_pre(register t_main_42sh *array,
register t_in_42sh *list)
{
	if (array->lp_auto->auto_len == array->lp_auto->auto_spl[0]->std.key_count)
		array->lp_auto->b_auto++;
	ft_42sh_auto_dsp_next_cmd(array, list);
}
