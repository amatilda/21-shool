/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_display_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:31:20 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int			fn_display_add(register t_my *my)
{
	char	*p;

	my->format = my->f++[0];
	if (my->format == 0)
	{
		my->f--;
		return (1);
	}
	my->sp = (my->opt.b_null != 0 && my->opt.b_left == 0) ? 0x30 : 0x20;
	p = ft_strchr(my->stc->str_format, my->format);
	p = (p != 0) ? (char *)(p - my->stc->str_format + 1) : p;
	if ((int)my->opt.max < 0)
	{
		my->opt.b_max_over = my->opt.b_null == 0 ? 1 : my->opt.b_max_over;
		my->opt.b_max_over_str = 1;
		my->opt.max = my->opt.min;
	}
	return ((my->stc->fn[(size_t)p])(my));
}
