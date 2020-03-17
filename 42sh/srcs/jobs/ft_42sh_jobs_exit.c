/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_quest(register t_main_42sh *array,
register t_in_42sh *list, register char **lp_arg)
{
	register t_write_buff		*out;
	register size_t				count;
	register size_t				count_litter;
	register size_t				tempos;

	out = &array->out;
	if (lp_arg != 0)
	{
		ft_42sh_dsp_start(array);
		ft_write_buffer_str_zero(out, "\n");
		ft_write_buffer_str_zero(out, MSG_JOBS_QUEST_42SH);
		ft_write_buffer_str_zero(out, "\x7");
		array->b_quest_exit = MSG_JOBS_QUEST_LEN_42SH;
		return ;
	}
	count_litter = list->count_litter - list->count_litter_current;
	count = list->lp_b + list->count - list->lp_current;
	tempos = list->slesh_current;
	ft_42sh_dsp_caret_right(array, list, count_litter, count);
	ft_write_buffer_str_zero(out, MSG_JOBS_QUEST_42SH);
	ft_write_buffer_str_zero(out, "\x7");
	array->b_quest_exit = MSG_JOBS_QUEST_LEN_42SH;
	list->count_litter_current -= count_litter;
	list->lp_current -= count;
	list->slesh_current = tempos;
}

size_t			ft_42sh_jobs_exit_test(register t_main_42sh *array,
register char **lp_arg)
{
	register t_jobs_42sh		*jobs;
	register size_t				count;

	if ((array->b_location & LOCATION_STANDART_42SH) == 0)
		return (1);
	if (array->b_quest_exit == EXIT_ANYWAY_42SH)
	{
		array->b_quest_exit = 0;
		return (1);
	}
	if (array->pr.jb.first == 0)
		return (1);
	if (lp_arg != 0)
	{
		jobs = array->pr.jb.last;
		count = jobs->count;
		while (count-- > 1)
			jobs = jobs->prev;
		if (jobs->prev == 0)
			return (1);
	}
	fn_quest(array, array->in.in_current, lp_arg);
	return (0);
}

void			ft_42sh_jobs_exit_clear(register t_main_42sh *array,
register t_in_42sh *list, register uintmax_t litter)
{
	ft_42sh_dsp_data(array, array->b_quest_exit);
	ft_write_buffer_str_zero(&array->out, "\xD\x1b[J\x1b[1A");
	ft_42sh_dsp_default_line(array, list);
	ft_write_buffer(&array->out);
	if (litter == 'y')
	{
		array->b_quest_exit = EXIT_ANYWAY_42SH;
		ft_42sh_cm_exit(array, 0);
	}
	array->b_quest_exit = 0;
}