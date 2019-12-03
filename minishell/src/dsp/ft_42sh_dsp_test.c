/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dsp_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

size_t			ft_42sh_dsp_test_care(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_slesh_42sh	**spl_slesh;
	register size_t			tempos;
	register size_t			count;
	register size_t			i;

	if ((spl_slesh = list->spl_slesh) == 0)
		tempos = list->count_litter_current;
	else if ((count = list->slesh_current) == 0)
		tempos = list->count_litter_current;
	else
	{
		i = 0;
		tempos = list->count_litter_current - array->msg.pre_msg_litter;
		while (i < count)
			tempos -= spl_slesh[i++]->count_litter;
	}
	return (tempos % array->ws.ws_col);
}
