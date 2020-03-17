/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_exp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_replase.h"

size_t			ft_42sh_replase_exp_count(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **out, register unsigned char *e)
{
	register unsigned char	lit;
	register size_t			count;

	*s = ft_42sh_parsing_sp(*s, e);
	*out = *s;
	count = 0;
	lit = 0x20;
	while ((lit = *out[0]) != '}')
	{
		*out = *out + 1;
		if (lit == '\\')
			count += ft_42sh_replase_slesh_count(out, e);
		else if (lit == '\'')
			count += ft_42sh_replase_quotes_one_count(in, out);
		else if (lit == '"')
			count += ft_42sh_replase_quotes_two_count(in, out, e);
		else if (lit == '$' && (in->b_mode & PARSING_MODE_HRDC_42SH) == 0)
			count += ft_42sh_exp_parsing_count(in, s, out, e);
		else if (lit == '~' && (in->b_mode & PARSING_MODE_HRDC_42SH) == 0 && ft_42sh_replase_home_test(*s, *out) != 0)
			count += ft_42sh_replase_home_count(in->array, out, e);
		else
			count++;
	}
	*out = ft_42sh_parsing_sp(*out + 1, e);
	return (count);
}

void			ft_42sh_replase_exp(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char *b, register unsigned char *e)
{
	register unsigned char		lit;
	register unsigned char		*start;

	b = ft_42sh_parsing_sp(b, e);
	start = b;
	lit = 0x20;
	while ((lit = b[0]) != '}')
	{
		b++;
		if (lit == '\\')
			dest = ft_42sh_replase_slesh(dest, &b, e);
		else if (lit == '\'')
			dest = ft_42sh_replase_quotes_one(in, dest, &b);
		else if (lit == '"')
			dest = ft_42sh_replase_quotes_two(in, dest, &b, e);
		else if (lit == '$' && (in->b_mode & PARSING_MODE_HRDC_42SH) == 0)
			dest = ft_42sh_exp_parsing(in, dest, &b, e);
		else if (lit == '~' && (in->b_mode & PARSING_MODE_HRDC_42SH) == 0 && ft_42sh_replase_home_test(start, b) != 0)
			dest = ft_42sh_replase_home(in->array, dest, &b, e);
		else
			dest++[0] = lit;
	}
}