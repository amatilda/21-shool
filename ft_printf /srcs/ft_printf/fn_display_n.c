/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_display_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:34:21 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	fn_display_n(register t_my *my)
{
	size_t	tmp;

	my->arg = va_arg(my->ap_line, size_t);
	tmp = my->out + my->count;
	if (my->opt.b_sub[2] != 0)
		*(intmax_t *)my->arg = (signed)tmp;
	else if (my->opt.b_sub[3] != 0 || my->opt.b_sub[4] != 0)
		*(ptrdiff_t *)my->arg = (signed)tmp;
	else if (my->opt.b_sub[sizeof(STR_SUB)] != 0)
		*(long long *)my->arg = (signed)tmp;
	else if (my->opt.b_sub[1] != 0)
		*(long *)my->arg = (signed)tmp;
	else if (my->opt.b_sub[0] != 0)
		*(short *)my->arg = (signed)tmp;
	else if (my->opt.b_sub[sizeof(STR_SUB) + 1] != 0)
		*(signed char *)my->arg = (signed)tmp;
	else
		*(int *)my->arg = (signed)tmp;
	return (1);
}
