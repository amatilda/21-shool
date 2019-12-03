/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:30:49 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/ft_printf.h"

static int	fn_finish(register t_my *my)
{
	if (my->f[0] == '.')
	{
		my->opt.b_max = 1;
		my->opt.max = ft_atoi(my->f + 1);
		while (my->f[1] >= 0x30 && my->f[1] <= 0x39)
			my->f++;
	}
	else if (my->f[0] == 0x30)
		my->opt.b_null = 1;
	else if (my->f[0] == ' ')
		my->opt.b_space = 1;
	else if (my->f[0] == '+')
		my->opt.b_plus = 1;
	else if (my->f[0] == '-')
		my->opt.b_left = 1;
	else if (my->f[0] == '\'')
		my->opt.b_grup = 1;
	else if ((my->f[0] == 'l' || my->f[0] == 'h') && my->f[0] == my->f[1])
		my->opt.b_sub[sizeof(STR_SUB) + ((my->f++[0] == 'l') ? 0 : 1)] = 1;
	else if ((my->str_tmp_sub = ft_strchr(my->stc->str_sub, my->f[0])) != 0)
		my->opt.b_sub[my->str_tmp_sub - my->stc->str_sub] = 1;
	else
		return (0);
	return (1);
}

static void	fn_stub1(register t_my *my)
{
	my->b_point = my->f[-1] == '.' ? 1 : 0;
	my->b_star = my->f[0] == '*' ? 1 : 0;
	my->f = my->f[0] == '*' ? my->f + 1 : my->f;
	my->null = my->f[0];
	my->tmp = 0;
	if (my->f[0] >= 0x30 && my->f[0] <= 0x39)
	{
		my->tmp = ft_atoi(my->f);
		while (my->f[1] >= 0x30 && my->f[1] <= 0x39)
			my->f++;
		my->f = my->f[1] == '$' ? my->f + 1 : my->f;
	}
}

static int	fn_stub0(register t_my *my)
{
	fn_stub1(my);
	if (my->f[0] != '$')
		return (1);
	if (my->b_point != 0)
	{
		va_copy(my->ap_n, my->ap_line);
		my->opt.max = va_arg(my->ap_n, size_t);
		my->opt.b_max = 1;
	}
	else if (my->tmp == 0)
		my->opt.min = 0;
	else if (my->b_star != 0)
	{
		va_copy(my->ap_n, my->ap);
		while (my->tmp-- > 0)
			my->opt.min = va_arg(my->ap_n, size_t);
	}
	else
	{
		va_copy(my->ap_line, my->ap);
		while (my->tmp-- > 1)
			va_arg(my->ap_line, size_t);
	}
	return (0);
}

static int	fn_flag(register t_my *my)
{
	if ((my->f[0] >= 0x31 && my->f[0] <= 0x39) || my->f[0] == '*')
	{
		if (fn_stub0(my) == 0)
			my->f = my->f;
		else if (my->b_point != 0)
		{
			my->f--;
			my->opt.max = va_arg(my->ap_line, size_t);
			my->opt.b_max = 1;
		}
		else if (my->b_star != 0)
		{
			my->f--;
			my->opt.min = va_arg(my->ap_line, size_t);
			my->opt.b_null = my->null == 0x30 ? 1 : my->opt.b_null;
			my->opt.min = my->tmp != 0 ? my->tmp : my->opt.min;
		}
		else
			my->opt.min = my->tmp;
	}
	else if (my->f[0] == '#')
		my->opt.b_prefix = 1;
	else if (fn_finish(my) == 0)
		return (0);
	return (1);
}

int			fn_display(register t_my *my)
{
	ft_memset(&my->opt, 0, sizeof(t_option));
	while (my->f[0] != 0)
	{
		if (fn_flag(my) == 0)
			break ;
		my->f++;
	}
	if ((int)my->opt.min < 0)
	{
		my->opt.b_left = 1;
		my->opt.min = ~(int)my->opt.min + 1;
	}
	if (my->opt.min >= INT_MAX || my->out + my->count >= INT_MAX - my->opt.min)
		return (0);
	return (fn_display_add(my));
}
