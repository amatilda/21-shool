/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_sintax_exp.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static size_t			f(register t_main_42sh *array,
register unsigned char *add)
{
	register unsigned char			litter;
	register unsigned char			*tmp;

	tmp = add;
	if (((litter = add++[0]) & 0x80) != 0)
		while (((litter = litter << 1) & 0x80) != 0)
			add++;
	ft_42sh_dq_test_err_n(array, MSG_EXP_SUB_BAD_42SH, tmp, add - tmp);
	return (0);
}

static void				*fn_test(register t_main_42sh *array,
register unsigned char *b)
{
	register unsigned char			litter;

	if ((litter = b++[0]) == '#' || litter == '%')
	{
		if (litter == b[0])
			b++;
		return (b);
	}
	else if (litter == '=')
		return (b);
	else if (litter == '%')
	{
		if ((litter = b[0]) == '}' || (litter == '%' && b++[1] == '}'))
			return (b);
	}
	else if (litter == ':' && ((litter = b[0]) == '?' || litter == '+' ||
	litter == '=' || litter == '-'))
		return (b + 1);
	else
		b--;
	return ((void *)f(array, b));
}

static unsigned char	ft_dq(register t_main_42sh *array,
unsigned char **out, register unsigned char *e)
{
	register unsigned char	litter;
	unsigned char			*b;

	b = *out;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (litter == '"')
		{
			*out = b;
			return (1);
		}
		else if (litter == '$')
			if (ft_42sh_dq_test_sintax_exp(array, &b, e) == 0)
				return (0);
	}
	*out = b;
	return (1);
}

static unsigned char	*fn_end(register t_main_42sh *array,
unsigned char *b, register unsigned char *e)
{
	register unsigned char	lit;

	while ((lit = b++[0]) != '}')
	{
		if (lit == '\\')
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (lit == '\'')
			ft_42sh_dq_skip_dq(&b, e, '\'');
		else if (lit == '"')
		{
			if (ft_dq(array, &b, e) == 0)
				return (0);
		}
		else if (lit == '$')
			if (ft_42sh_dq_test_sintax_exp(array, &b, e) == 0)
				return (0);
	}
	return (b);
}

size_t					ft_42sh_dq_test_sintax_exp(register t_main_42sh *array,
unsigned char **src, register unsigned char *e)
{
	register unsigned char			*b;
	register unsigned char			*tmp;
	register unsigned char			litter;

	if ((b = *src) + 2 < e && b[0] == '(' && b[1] == '(')
		if (ft_42sh_calc_test(array, src, e) == 0)
			return (0);
	if ((b = *src) == e || b++[0] != '{')
		return (1);
	if ((litter = b[0]) == '#')
		b++;
	tmp = b;
	b = ft_42sh_exp_name_special(b, e);
	if (tmp == b)
		return (f(array, b));
	if (b[0] == '}')
		return ((size_t)(*src = b + 1));
	if (litter == '#')
		return (f(array, b));
	if ((b = fn_test(array, b)) == 0)
		return (0);
	if ((b = fn_end(array, b, e)) == 0)
		return (0);
	*src = b;
	return (1);
}
