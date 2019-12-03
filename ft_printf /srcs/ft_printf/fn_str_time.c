/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_str_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:53:56 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/02 15:37:49 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/fn_str_time.h"

static void	fn_any(register t_ft_str_time_in_out *in_out,
		register t_ft_str_time *str_time, register size_t number)
{
	str_time->tmp = (str_time->f[0] == str_time->f[1]) ? 2 : 1;
	str_time->f += str_time->tmp;
	str_time->tmp = number > 9 ? 2 : str_time->tmp;
	in_out->count_out += str_time->tmp;
	if (in_out->max >= in_out->count_out)
	{
		if (str_time->tmp == 1)
			str_time->s++[0] = number + 0x30;
		else
		{
			str_time->tmp = number / 10;
			str_time->s[0] = str_time->tmp + 0x30;
			str_time->s[1] = (number - str_time->tmp * 10) + 0x30;
			str_time->s += 2;
		}
	}
	if (ft_strchr(str_time->str_format, str_time->f[0]) == 0)
	{
		in_out->count_out++;
		if (in_out->max >= in_out->count_out)
			str_time->s++[0] = str_time->f++[0];
	}
}

static int	fn_year(register t_ft_str_time_in_out *in_out,
		register t_ft_str_time *str_time)
{
	if (str_time->f[0] == 'Y')
	{
		str_time->b_test |= STR_TIME_YEAR_;
		str_time->tmp = in_out->timeptr.tm_year + 1900;
		if (str_time->tmp > 9999)
			return (0);
		if (str_time->f[1] == 'Y')
			in_out->count_out = 4;
		else
		{
			in_out->count_out = 2;
			str_time->tmp = str_time->tmp - (str_time->tmp / 100) * 100;
		}
		str_time->f += in_out->count_out >> 1;
		if (in_out->max >= in_out->count_out)
			str_time->s += ft_itoa(str_time->s, str_time->tmp, 10, ITOA_LOWER);
		if (ft_strchr(str_time->str_format, str_time->f[0]) == 0)
		{
			in_out->count_out++;
			if (in_out->max >= in_out->count_out)
				str_time->s++[0] = str_time->f++[0];
		}
	}
	return (1);
}

static int	fn_stub0(register t_ft_str_time_in_out *in_out,
		register t_ft_str_time *str_time)
{
	if (str_time->f[0] == 'D')
	{
		if ((str_time->b_test & STR_TIME_MONTH_) == 0)
			return (0);
		fn_any(in_out, str_time, in_out->timeptr.tm_mday);
	}
	if (str_time->f[0] == 'h')
	{
		str_time->b_test |= STR_TIME_HOUR_;
		fn_any(in_out, str_time, in_out->timeptr.tm_hour);
	}
	if (str_time->f[0] == 'm')
	{
		if ((str_time->b_test & STR_TIME_HOUR_) == 0)
			return (0);
		str_time->b_test |= STR_TIME_MIN_;
		fn_any(in_out, str_time, in_out->timeptr.tm_min);
	}
	if (str_time->f[0] == 's')
	{
		if ((str_time->b_test & STR_TIME_SEC_) == 0)
			return (0);
		fn_any(in_out, str_time, in_out->timeptr.tm_sec);
	}
	return (1);
}

int			fn_str_time(register t_ft_str_time_in_out *in_out)
{
	t_ft_str_time		str_time;

	str_time.s = in_out->s;
	str_time.f = in_out->f;
	str_time.str_format = "YMDhms";
	str_time.b_test = 0;
	in_out->count_out = 0;
	if (fn_year(in_out, &str_time) == 0)
		return (0);
	if (str_time.f[0] == 'M')
	{
		if ((str_time.b_test & STR_TIME_YEAR_) == 0)
			return (0);
		str_time.b_test |= STR_TIME_MONTH_;
		fn_any(in_out, &str_time, in_out->timeptr.tm_mon + 1);
	}
	if (fn_stub0(in_out, &str_time) == 0)
		return (0);
	if (in_out->count_out > in_out->max)
		return (0);
	if (in_out->count_out != 0 && str_time.s[-1] == str_time.f[-1])
		in_out->count_out--;
	return (1);
}
