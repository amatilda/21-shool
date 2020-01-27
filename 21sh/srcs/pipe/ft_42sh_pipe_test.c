/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static size_t		f(register t_main_42sh *array,
register void *str, register void *add, register size_t n)
{
	ft_42sh_dsp_err_msg_add_n(array, str, add, n);
	return (0);
}

static void			*fn_next_test(register t_main_42sh *array,
register unsigned char *b, register unsigned char *end,
register unsigned char old)
{
	register unsigned char			litter;
	unsigned char					*out;

	if (old == '|')
	{
		out = b;
		if (ft_42sh_replase_cmd_count(array, &out, end, 0) == 0)
			return ((void *)f(array, MSG_SINTAX_ERROR_42SH, (char *)b - 1, 1));
		ft_42sh_parsing_arg_empty(array, &out, end);
		return (out);
	}
	if ((litter = b[0]) == b[-1] && (++b == end || litter == b[0]))
		return ((void *)f(array, MSG_SINTAX_ERROR_42SH, (char *)b - 1, 1));
	if (b[0] == '&' && ++b == end)
		return ((void *)f(array, MSG_SINTAX_ERROR_42SH, (char *)b - 1, 1));
	out = b;
	if (ft_42sh_replase_cmd_count(array, &out, end, 0) == 0)
		return ((void *)f(array, MSG_SINTAX_ERROR_42SH, (char *)b - 1, 1));
	return (out);
}

static void			fn_while_arg(register t_main_42sh *array,
register unsigned char *b, unsigned char **out, register unsigned char *end)
{
	*out = b;
	while (0xFF)
	{
		ft_42sh_replase_arg_count(array, out, end, 0);
		if (*out == b)
			break ;
		b = *out;
	}
}

size_t				ft_42sh_pipe_test(register t_main_42sh *array,
unsigned char **out, register unsigned char *end, register size_t b_empty)
{
	register unsigned char			*b;
	register unsigned char			litter;

	while ((b = *out) != end)
	{
		litter = b[0];
		if ((b += ft_42sh_parsing_test_pipe(b, end, litter, 0x20)) == *out)
			break ;
		if (b == end || ((litter == '|' || litter == '<') && b_empty == 0))
			return (f(array, MSG_SINTAX_ERROR_42SH, b - 1, 1));
		if (litter == '&' || b - *out == 3)
			return (f(array, MSG_SINTAX_ERROR_42SH, b - 2, 1));
		if ((b = fn_next_test(array, b, end, litter)) == 0)
			return (0);
		fn_while_arg(array, b, out, end);
	}
	return (1);
}
