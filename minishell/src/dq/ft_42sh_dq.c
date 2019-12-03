/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void			ft_42sh_dq(register t_main_42sh *array,
register t_in_42sh *list)
{
	register char		litter;

	ft_42sh_key_end(array, list);
	ft_write_buffer_str_zero(&array->out, "\n\x1b[J");
	if ((litter = array->dquote) != 0)
	{
		ft_42sh_dq_combi_date(array, array->in_dquote, list);
		if ((litter = ft_42sh_dq_test(list->lp_b, list->count, litter)) == 0)
			ft_42sh_dq_paste(array);
	}
	else if ((litter = ft_42sh_dq_test_dq(list->lp_b, list->count)) != 0)
		ft_42sh_dq_cut(array, list);
	ft_42sh_msg_change(array, litter, array->dquote);
	if (litter == 0)
		return (ft_42sh_parsing(array, list));
	ft_42sh_list_in_deffault(array);
	ft_write_buffer_str_zero(&array->out, array->msg.pre_msg);
	if (array->msg.pre_msg_litter % array->ws.ws_col == 0)
		ft_write_buffer_str_zero(&array->out, " \xD");
}
