/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_display_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:31:02 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

int			fn_display_a(t_my *my)
{
	my->opt.b_exp = 1;
	my->format = my->format + ('p' - 'a');
	my->opt.base = 16;
	my->opt.b_ox = 2;
	return (fn_display_float(my));
}
