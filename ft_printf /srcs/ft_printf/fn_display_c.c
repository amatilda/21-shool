/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:32:37 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	fn_display_c(register t_my *my)
{
	char	str[5];

	my->arg = (wint_t)va_arg(my->ap_line, size_t);
	if (my->opt.b_sub[1] == 0 && my->format != 'C')
	{
		if (my->out + my->count >= INT_MAX - 1)
			return (0);
		my->format = (unsigned char)my->arg;
		fn_display_unknown(my);
		return (1);
	}
	my->opt.max = ft_wctomb(str, my->arg);
	if ((int)my->opt.max == -1)
		return (0);
	if (my->out + my->count >= INT_MAX - my->opt.max)
		return (0);
	if (my->opt.b_left != 0)
		fn_str_copy(my, str, my->opt.max);
	if (my->opt.min-- >= 2)
		fn_sp(my, my->sp);
	if (my->opt.b_left == 0)
		fn_str_copy(my, str, my->opt.max);
	return (1);
}
