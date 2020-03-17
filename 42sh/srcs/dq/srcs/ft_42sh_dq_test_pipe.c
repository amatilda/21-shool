/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static size_t		fn_test(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e)
{
	register unsigned char			litter;
	register unsigned char			*tmp;

	if ((litter = b[0]) == b[-1] && (++b == e || litter == b[0]))
		return (ft_42sh_dq_test_err_n(array, MSG_SINTAX_ERROR_42SH, (char *)b - 1, 1));
	if (b[0] == '&' && ++b == e)
		return (ft_42sh_dq_test_err_n(array, MSG_SINTAX_ERROR_42SH, (char *)b - 1, 1));
	tmp = b - 1;
	if (ft_42sh_parsing_litter_e_f((b = ft_42sh_parsing_sp(b, e)), e) == 0)
		return (ft_42sh_dq_test_err_n(array, MSG_SINTAX_ERROR_42SH, tmp, 1));
	return ((size_t)b);
}

size_t				ft_42sh_dq_test_pipe(register t_main_42sh *array,
unsigned char **out, register unsigned char *e)
{
	register unsigned char			*b;
	register unsigned char			*tmp;
	register unsigned char			litter;

	b = *out;
	while (ft_42sh_parsing_litter_e_f(b, e) != 0)
	{
		litter = b[0];
		if ((b += ft_42sh_parsing_test_pipe(b, e, 0x20)) == *out)
			break ;
		if (b == e)
			return (ft_42sh_dq_test_err_n(array, MSG_SINTAX_ERROR_42SH, b - 1, 1));
		if (litter == '&' || b - *out == 3)
			return (ft_42sh_dq_test_err_n(array, MSG_SINTAX_ERROR_42SH, b - 2, 1));
		if ((b = (void *)fn_test(array, b, e)) ==
		(unsigned char *)PARSING_FALTURE_42SH)
			return (PARSING_FALTURE_42SH);
		if ((tmp = ft_42sh_dq_test_word(array, b, e)) < b)
			return ((size_t)tmp);
		b = ft_42sh_parsing_sp(tmp, e);
		*out = b;
	}
	return (0);
}
