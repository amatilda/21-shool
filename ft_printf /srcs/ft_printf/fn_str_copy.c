/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_str_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:37:19 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

void	fn_str_copy(register t_my *my, register const char *str,
		register size_t count)
{
	while (count-- > 0)
	{
		if (my->count < my->size_b)
			my->b[my->count] = str++[0];
		my->count++;
		if (my->count == my->size_b && my->b_in_str == 0)
		{
			my->out += my->count;
			my->count = 0;
			write(my->fildes, my->b, my->size_b);
		}
	}
}
