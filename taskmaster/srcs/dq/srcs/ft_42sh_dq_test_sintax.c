/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_sintax.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static size_t			fn_exp(register t_main_42sh *array,
register unsigned char *b, register unsigned char **out,
register unsigned char *e)
{
	if (b + 2 < e && b[0] == '(' && b[1] == '(')
		return (ft_42sh_calc_test(array, out, e));
	return (ft_42sh_dq_test_sintax_exp(array, out, e));
}

static size_t			fn_test(register t_main_42sh *array,
unsigned char **out, register unsigned char *e)
{
	register unsigned char	lit;
	unsigned char			*b;

	b = ft_42sh_parsing_sp(*out, e);
	lit = 0x20;
	while ((lit = ft_42sh_parsing_test_next(&b, e, 0, lit)) != 0)
	{
		if (lit == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (lit == '"' || lit == '\'')
		{
			if (ft_42sh_dq_test_sintax_dq(array, &b, e, lit) != 0)
				return (PARSING_FALTURE_42SH);
		}
		else if (lit == '$')
			if (fn_exp(array, b, &b, e) == 0)
				return (PARSING_FALTURE_42SH);
	}
	*out = ft_42sh_parsing_sp(b, e);
	return (0);
}

unsigned char			ft_42sh_dq_test_sintax(register t_main_42sh *array,
unsigned char **out, register unsigned char *e)
{
	unsigned char					*b;
	register size_t					tempos;

	b = ft_42sh_parsing_sp(*out, e);
	while (ft_42sh_parsing_litter_e_f(b, e) != 0)
	{
		if ((tempos = (size_t)ft_42sh_dq_test_word(array, b, e, 0)) < (size_t)b)
			return ((unsigned char)tempos);
		if ((tempos = fn_test(array, &b, e)) != 0)
			return ((unsigned char)tempos);
		if (ft_42sh_parsing_test_pipe(b, e, 0x20) != 0)
			if ((tempos = ft_42sh_dq_test_pipe(array, &b, e)) != 0)
				return ((unsigned char)tempos);
	}
	*out = b;
	return (0);
}
