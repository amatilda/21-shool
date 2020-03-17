/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_eof.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_check_list(register t_main_42sh *array,
register t_in_42sh *list)
{
	register void				*cmp;

	cmp = array->dq.hrdoc_cmp_lp;
	ft_42sh_str_add(array, cmp, cmp + array->dq.hrdoc_cmp_count, 1);
	ft_free(cmp);
	array->dq.hrdoc_cmp_lp = 0;
	return (ft_42sh_dq(array, list));
}

void			ft_42sh_key_eof(register t_main_42sh *array,
register t_in_42sh *list)
{
	register size_t				count;

	if ((count = list->count) == 0)
	{
		if ((count = array->dq.dquote) == 0)
		{
			ft_write_buffer_str_zero(&array->out, "\n");
			ft_42sh_cm_exit(array, 0);
			return ;
		}
		else if (count == '<')
			return (fn_check_list(array, list));
		else
			return (ft_write_buffer_str_zero(&array->out, "\x7"));
	}
	if (list->lp_b + count == list->lp_current)
		return (ft_write_buffer_str_zero(&array->out, "\x7"));
	ft_42sh_key_delete(array, list);
}
