/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_display_unknown.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:35:53 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int	fn_display_unknown(register t_my *my)
{
	if (my->b_in_str == 0 && my->count == my->size_b)
	{
		my->out += my->count;
		my->count = 0;
		write(my->fildes, my->b, my->size_b);
	}
	if (my->opt.min != 0)
		my->opt.min--;
	if (my->opt.b_left == 0 && my->opt.min != 0)
		fn_sp(my, my->sp);
	if (my->count < my->size_b)
		my->b[my->count] = my->format;
	my->count++;
	if (my->opt.min != 0)
		fn_sp(my, my->sp);
	return (1);
}
