/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_str_full_home_end.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_42sh_str_full_home(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t				tempos;

	if ((tempos = list->lp_current - list->lp_b) == 0)
		return ;
	ft_42sh_dsp_caret_left(array, list,
	list->count_litter_current - array->msg.pre_msg_litter, tempos);
}

void			ft_42sh_str_full_end(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t				tempos;

	if ((tempos = list->lp_b + list->count - list->lp_current) == 0)
		return ;
	ft_42sh_dsp_caret_right(array, list,
	list->count_litter - list->count_litter_current, tempos);
}
