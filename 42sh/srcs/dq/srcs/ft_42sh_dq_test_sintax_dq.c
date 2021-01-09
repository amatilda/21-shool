/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_sintax_dq.c                        :+:      :+:    :+:   */
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

unsigned char			ft_42sh_dq_test_sintax_dq(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register unsigned char lit)
{
	unsigned char			*b;

	if (lit == '\'')
		return (ft_42sh_dq_test_dq(array, out, e, '\''));
	b = *out;
	while (b < e)
	{
		if ((lit = b++[0]) == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (lit == '"')
		{
			*out = b;
			return (0);
		}
		else if (lit == '$')
			if (fn_exp(array, b, &b, e) == 0)
				return (PARSING_FALTURE_42SH);
	}
	*out = b;
	return (0);
}
