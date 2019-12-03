/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:27:23 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int		ft_snprintf(char *str, size_t size, const char *format, ...)
{
	t_arg	arg;
	size_t	out;

	if (size > (size_t)INT_MAX + 1)
		return (-1);
	arg.b = str;
	arg.f = format;
	arg.size_b = size > 0 ? size - 1 : size;
	arg.b_in_str = 1;
	va_start(arg.ap, format);
	out = fn_big(&arg);
	va_end(arg.ap);
	return (out);
}
