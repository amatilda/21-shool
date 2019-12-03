/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_sp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:30:03 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static void	fn_stub0(register t_my *my, register uint_fast8_t sp)
{
	size_t			tmp;

	if (my->count < my->size_b)
	{
		tmp = my->size_b - my->count;
		if (tmp > my->opt.min)
			tmp = my->opt.min;
		ft_memset(&my->b[my->count], sp, tmp);
	}
	my->count += my->opt.min;
	my->opt.min = 0;
}

void		fn_sp(register t_my *my, register uint_fast8_t sp)
{
	if (my->b_in_str != 0)
	{
		fn_stub0(my, sp);
		return ;
	}
	if (my->opt.min > my->size_b - my->count)
	{
		ft_memset(&my->b[my->count], sp, my->size_b - my->count);
		my->out += my->size_b;
		my->opt.min -= my->size_b - my->count;
		write(my->fildes, my->b, my->size_b);
	}
	while (my->opt.min > my->size_b)
	{
		ft_memset(&my->b[0], sp, my->size_b);
		my->opt.min -= my->size_b;
		my->out += my->size_b;
		write(my->fildes, my->b, my->size_b);
	}
	ft_memset(&my->b[my->count], sp, my->opt.min);
	my->count += my->opt.min;
	my->opt.min = 0;
}
