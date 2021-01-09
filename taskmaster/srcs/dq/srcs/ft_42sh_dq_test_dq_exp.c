/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_dq_exp.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static unsigned char	fn_ret(unsigned char **out, unsigned char *b,
register unsigned char litter)
{
	*out = b;
	return (litter);
}

static unsigned char	fn_exp(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register uint_fast8_t b_test)
{
	unsigned char				*b;
	register unsigned char		litter;

	b = *out;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (litter == '}')
			return (fn_ret(out, b, 0));
		else if (litter == '$')
		{
			if ((litter = ft_42sh_dq_test_dq_exp(array, &b, e, b_test)) != 0)
				return (fn_ret(out, b, litter));
		}
		else if ((litter == '"' || litter == '\'') &&
		(b_test & DQ_HRDC_42SH) == 0)
			if ((litter = ft_42sh_dq_test_dq(array, &b, e, litter)) != 0)
				return (fn_ret(out, b, litter));
	}
	return (fn_ret(out, b, '}'));
}

static size_t			fn_test(register unsigned char litter,
register uint_fast8_t b_test)
{
	if ((litter == '"' || litter == '\'') && (b_test & DQ_HRDC_42SH) == 0)
		return (1);
	return (0);
}

static unsigned char	fn_arith(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register uint_fast8_t b_test)
{
	unsigned char				*b;
	register unsigned char		litter;

	b = *out;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (litter == '(')
		{
			if ((litter = fn_arith(array, &b, e, b_test)) != 0)
				return (fn_ret(out, b, litter));
		}
		else if (litter == ')')
			return (fn_ret(out, b, 0));
		else if (litter == '$')
		{
			if ((litter = ft_42sh_dq_test_dq_exp(array, &b, e, b_test)) != 0)
				return (fn_ret(out, b, litter));
		}
		else if (fn_test(litter, b_test) != 0)
			if ((litter = ft_42sh_dq_test_dq(array, &b, e, litter)) != 0)
				return (fn_ret(out, b, litter));
	}
	return (fn_ret(out, b, ')'));
}

unsigned char			ft_42sh_dq_test_dq_exp(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register uint_fast8_t b_test)
{
	register unsigned char			litter;
	unsigned char					*b;

	b = *out;
	if (b == e)
		return (0);
	if ((litter = b[0]) == '{')
	{
		*out = *out + 1;
		litter = fn_exp(array, out, e, b_test);
	}
	else if (b + 1 < e && litter == '(' && b[1] == '(')
	{
		*out = *out + 1;
		litter = fn_arith(array, out, e, b_test);
	}
	else
		return (0);
	if (((array->b_location & LOCATION_SCRIPT_42SH) != 0 ||
	(b_test & DQ_HRDC_42SH) != 0) && (litter == '}' ||
	litter == ')'))
		ft_42sh_dq_test_err_n(array, MSG_CLOSING_ERROR_42SH, b, 0);
	return (litter);
}
