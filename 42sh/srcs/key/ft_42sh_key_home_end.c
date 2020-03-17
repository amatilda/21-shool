/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_home_end.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_home(register t_main_42sh *array,
register t_in_42sh *list, register t_slesh_42sh **spl_tmp,
register t_slesh_42sh **spl_slesh)
{
	register char				*current;
	register size_t				count;
	register size_t				count_litter;

	count_litter = array->msg.pre_msg_litter;
	count = 0;
	current = list->lp_current;
	if (current[-1] != '\n')
	{
		while (spl_tmp < spl_slesh)
		{
			count_litter += spl_tmp[0]->count_litter;
			count += spl_tmp++[0]->count + 2;
		}
		count_litter += spl_tmp[0]->count_litter;
		count += spl_tmp[0]->count;
		count_litter = spl_slesh[0]->count_litter -
		(count_litter - list->count_litter_current);
		count = spl_slesh[0]->count - (count - (current - list->lp_b));
		return (ft_42sh_dsp_caret_left(array, list, count_litter, count));
	}
	spl_slesh--;
	ft_42sh_dsp_caret_left(array, list, spl_slesh[0]->count_litter,
	spl_slesh[0]->count + 2);
}

void			ft_42sh_key_home(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t				tempos;
	register t_slesh_42sh		**spl_slesh;

	if ((tempos = list->lp_current - list->lp_b) == 0)
		return ;
	if ((spl_slesh = list->spl_slesh) != 0)
	{
		fn_home(array, list, spl_slesh, &spl_slesh[list->slesh_current]);
		return ;
	}
	ft_42sh_dsp_caret_left(array, list,
	list->count_litter_current - array->msg.pre_msg_litter, tempos);
}

static void		fn_end(register t_main_42sh *array,
register t_in_42sh *list, register t_slesh_42sh **spl_tmp,
register t_slesh_42sh **spl_slesh)
{
	register char				*current;
	register size_t				count;
	register size_t				count_litter;

	count_litter = array->msg.pre_msg_litter;
	count = 0;
	current = list->lp_current;
	if (list->lp_b + list->count > current + 1 && current[1] != '\n')
	{
		while (spl_tmp < spl_slesh)
		{
			count_litter += spl_tmp[0]->count_litter;
			count += spl_tmp++[0]->count + 2;
		}
		count_litter += spl_tmp[0]->count_litter;
		count += spl_tmp[0]->count;
		count_litter -= list->count_litter_current;
		count = count - (current - list->lp_b);
		return (ft_42sh_dsp_caret_right(array, list, count_litter, count));
	}
	spl_slesh++;
	ft_42sh_dsp_caret_right(array, list, spl_slesh[0]->count_litter,
	spl_slesh[0]->count + 2);
}

void			ft_42sh_key_end(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t				tempos;
	register t_slesh_42sh		**spl_slesh;

	if ((tempos = list->lp_b + list->count - list->lp_current) == 0)
		return ;
	if ((spl_slesh = list->spl_slesh) != 0)
	{
		fn_end(array, list, spl_slesh, &spl_slesh[list->slesh_current]);
		return ;
	}
	ft_42sh_dsp_caret_right(array, list,
	list->count_litter - list->count_litter_current, tempos);
}
