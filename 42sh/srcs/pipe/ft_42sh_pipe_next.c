/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		*fn_next(register t_main_42sh *array,
register unsigned char *b, register unsigned char *end)
{
	register unsigned char			litter;
	unsigned char					*out;

	if ((litter = b[0]) == b[-1])
		b++;
	if (b[0] == '&')
		b++;
	out = b;
	ft_42sh_replase_skip(array, &out, end);
	return (out);
}

size_t			ft_42sh_pipe_next(register t_main_42sh *array,
unsigned char **out, register unsigned char *end)
{
	register unsigned char			*b;
	register unsigned char			litter;
	register size_t					tempos;

	b = ft_42sh_parsing_sp(*out, end);
	litter = b[0];
	if (b == end ||
	(tempos = ft_42sh_parsing_test_pipe(b, end, 0x20)) == 0)
		return (0);
	b += tempos;
	if (litter != '|')
		b = fn_next(array, b, end);
	*out = b;
	return (tempos);
}

uintmax_t		ft_42sh_pipe_next_count(register t_main_42sh *array,
unsigned char *b, register unsigned char *end)
{
	register uintmax_t		count;

	count = 0;
	ft_42sh_parsing_arg_skip(array, &b, end);
	while (ft_42sh_parsing_litter_e_f(b, end) != 0
	&& ft_42sh_pipe_next(array, &b, end) != 0)
	{
		count++;
		ft_42sh_parsing_arg_skip(array, &b, end);
	}
	if (b < end && b[0] == '|' && b[1] != '|')
		count |= (((uintmax_t)1) << (sizeof(uintmax_t) * 8 - 1));
	return (count);
}
