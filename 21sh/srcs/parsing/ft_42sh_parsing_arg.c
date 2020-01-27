/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static size_t		fn_cout_arg(register t_main_42sh *array,
unsigned char *b, register unsigned char *e)
{
	register size_t			count;

	count = 0;
	while (b < e && ft_42sh_parsing_litter_e_f(b[0]) != 0)
	{
		if (ft_42sh_pipe_next(array, &b, e) != 0)
			continue ;
		ft_42sh_replase_arg_count(array, &b, e, 0);
		count++;
	}
	return (count);
}

char				**ft_42sh_parsing_arg_empty(register t_main_42sh *array,
unsigned char **out, register unsigned char *end)
{
	register unsigned char	*b;

	b = *out;
	while (b < end && ft_42sh_parsing_litter_e(b[0]) != 0)
	{
		ft_42sh_replase_arg_count(array, out, end, 0);
		b = *out;
		if (b == end || ft_42sh_parsing_test_pipe(b, end, b[0], 0x20) != 0)
			return (0);
	}
	return (0);
}

static void			*fn_set_arg(register t_main_42sh *array,
register char **lp_arg, unsigned char **out, register unsigned char *end)
{
	register unsigned char	*b;
	register unsigned char	*tmp;
	register size_t			count;

	b = *out;
	count = ft_42sh_replase_arg_count(array, out, end, 0);
	if ((tmp = ft_malloc(count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	lp_arg[0] = (char *)tmp;
	tmp[count] = 0;
	ft_42sh_replase_arg(array, tmp, b, end);
	return (*out);
}

char				**ft_42sh_parsing_arg(register t_main_42sh *array,
unsigned char **out, register unsigned char *end, size_t b_empty)
{
	register char			**lp_arg;
	register unsigned char	litter;
	register size_t			count;
	register unsigned char	*b;
	unsigned char			*tmp;

	if (b_empty == 0)
		return (ft_42sh_parsing_arg_empty(array, out, end));
	b = *out;
	count = fn_cout_arg(array, b, end);
	if ((lp_arg = ft_malloc(sizeof(char *) * (count + 1 + 1))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	b_empty = (size_t)lp_arg;
	lp_arg++[0] = 0;
	lp_arg[count] = 0;
	b = ft_42sh_parsing_sp(b, end);
	while (b < end && (litter = ft_42sh_parsing_litter_e(b[0])) != 0 &&
	ft_42sh_parsing_test_pipe(b, end, litter, 0x20) == 0)
		b = fn_set_arg(array, lp_arg++, out, end);
	tmp = b;
	while (b < end && ft_42sh_parsing_litter_e_f(b[0]) != 0)
		b = ft_42sh_pipe_next(array, out, end) != 0 ?
		*out : fn_set_arg(array, lp_arg++, out, end);
	*out = tmp;
	return ((char **)b_empty);
}
