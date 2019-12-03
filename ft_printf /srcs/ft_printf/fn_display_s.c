/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:35:09 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static int	fn_stub1(register t_my *my, register const wchar_t *s)
{
	char	str[5];
	size_t	i;
	int		tmp;

	i = 0;
	while (i < my->opt.max)
	{
		tmp = ft_wctomb(str, s[i]);
		if (tmp == -1)
			return (0);
		fn_str_copy(my, str, tmp);
		i++;
	}
	return (1);
}

static int	fn_stub0(register t_my *my)
{
	my->tmp = ft_wcslen((wchar_t *)my->arg);
	if (my->tmp >= INT_MAX)
		return (0);
	else if (my->out + my->count >= INT_MAX - my->tmp)
		return (0);
	if (!(my->opt.b_max) || my->opt.max > my->tmp || my->opt.b_max_over_str)
		my->opt.max = my->tmp;
	my->opt.min = my->opt.min > my->opt.max ? my->opt.min - my->opt.max : 0;
	if (my->opt.b_left == 0 && my->opt.min != 0)
		fn_sp(my, my->sp);
	if (fn_stub1(my, (wchar_t *)my->arg) == 0)
		return (0);
	if (my->opt.min != 0)
		fn_sp(my, my->sp);
	return (1);
}

int			fn_display_s(register t_my *my)
{
	my->arg = va_arg(my->ap_line, size_t);
	my->arg = my->arg == 0 ? (size_t)"(null)" : my->arg;
	if (my->opt.b_sub[1] == 0 && my->format != 'S')
	{
		my->tmp = ft_strlen((char *)my->arg);
		if (my->tmp >= INT_MAX)
			return (0);
		else if (my->out + my->count >= INT_MAX - my->tmp)
			return (0);
		if (!(my->opt.b_max) || my->opt.max > my->tmp || my->opt.b_max_over_str)
			my->opt.max = my->tmp;
		my->opt.min = my->opt.min > my->opt.max ?
			my->opt.min - my->opt.max : 0;
		if (my->opt.b_left != 0)
			fn_str_copy(my, (char *)my->arg, my->opt.max);
		if (my->opt.min != 0)
			fn_sp(my, my->sp);
		if (my->opt.b_left == 0)
			fn_str_copy(my, (char *)my->arg, my->opt.max);
		return (1);
	}
	return (fn_stub0(my));
}
