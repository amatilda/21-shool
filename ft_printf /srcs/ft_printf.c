/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:25:18 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_arg	arg;
	size_t	out;

	arg.b = 0;
	arg.f = format;
	arg.fildes = 1;
	arg.b_in_str = 0;
	arg.size_b = SIZE_B;
	va_start(arg.ap, format);
	out = fn_big(&arg);
	va_end(arg.ap);
	return (out);
}
