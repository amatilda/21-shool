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

static void		fn_view(register t_main_42sh *array, register t_in_42sh *list)
{
	register size_t				count;
	register size_t				count_litter;

	if (array->tab.b_view != 0)
	{
		array->tab.b_view = 0;
		count = list->lp_b + list->count - list->lp_current;
		count_litter = list->count_litter - list->count_litter_current;
		ft_42sh_dsp_caret_right(array, list, count_litter, count);
		ft_write_buffer_str_zero(&array->out, "\x1b[J");
		ft_42sh_dsp_caret_left(array, list, count_litter, count);
	}
}

static void		fn_start(register t_main_42sh *array, register t_in_42sh *list,
register t_all_cmd_42sh **spl, register size_t n)
{
	register char				*str;

	str = spl[0]->std.lp_key + n;
	ft_42sh_str(array, list, str, str + spl[0]->std.key_count - n);
	array->tab.b_auto = 2;
}

void			ft_42sh_auto_dsp_next_cmd(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t				tempos;
	register size_t				n;
	register char				*str;
	register t_all_cmd_42sh		**spl;

	fn_view(array, list);
	spl = array->tab.auto_spl;
	n = array->tab.auto_len;
	if ((tempos = array->tab.b_auto) == 1)
		return (fn_start(array, list, spl, n));
	tempos -= 2;
	ft_42sh_str_del(array, list,
	spl[tempos]->key_litter - array->tab.auto_litter_len);
	if (++tempos == array->tab.auto_cmd)
		fn_start(array, list, spl, n);
	else
	{
		str = spl[tempos]->std.lp_key + n;
		ft_42sh_str(array, list, str,
		str + spl[tempos]->std.key_count - n);
		array->tab.b_auto = tempos + 2;
	}
}
