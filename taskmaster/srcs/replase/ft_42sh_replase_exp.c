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

static size_t	fn_add_count(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **out, register unsigned char *e)
{
	register unsigned char	lit;
	register size_t			count;
	unsigned char			*b;

	if ((in->b_mode & PARSING_MODE_HRDC_42SH) == 0)
	{
		in->hrdc.b_test = 1;
		*s = ft_42sh_parsing_sp(*s, e);
		*out = *s;
		return (0);
	}
	in->hrdc.b_test = 0;
	count = 0;
	b = *out;
	while (b < e && (lit = b[0]) != '}')
	{
		b++;
		if (lit == '$')
			count += ft_42sh_exp_parsing_count(in, s, &b, e);
		else if (lit != '\n')
			count++;
	}
	*out = b + 1;
	return (count);
}

size_t			ft_42sh_replase_exp_count(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **out, register unsigned char *e)
{
	register unsigned char	lit;
	register size_t			count;

	count = fn_add_count(in, s, out, e);
	if (in->hrdc.b_test == 0)
		return (count);
	while ((lit = *out[0]) != '}')
	{
		*out = *out + 1;
		if (lit == '\\')
			count += ft_42sh_replase_slesh_exp_count(out, e);
		else if (lit == '\'')
			count += ft_42sh_replase_quotes_one_count(in, out);
		else if (lit == '"')
			count += ft_42sh_replase_quotes_two_count(in, out, e);
		else if (lit == '$')
			count += ft_42sh_exp_parsing_count(in, s, out, e);
		else if (lit == '~' && ft_42sh_replase_home_test(in->array,
		*s, *out, e) != 0)
			count += ft_42sh_replase_home_count(in->array, out);
		else if (lit != '\n')
			count++;
	}
	*out = ft_42sh_parsing_sp(*out + 1, e);
	return (count);
}

static void		*fn_add(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char *b, register unsigned char *e)
{
	register unsigned char		lit;

	if ((in->b_mode & PARSING_MODE_HRDC_42SH) == 0)
		return (b);
	while ((lit = b[0]) != '}')
	{
		b++;
		if (lit == '$')
			dest = ft_42sh_exp_parsing(in, dest, &b, e);
		else if (lit == '\n')
			dest[-1] = '\n';
		else
			dest++[0] = lit;
	}
	return (0);
}

void			ft_42sh_replase_exp(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char *b, register unsigned char *e)
{
	register unsigned char		lit;
	register unsigned char		*start;

	b = ft_42sh_parsing_sp(b, e);
	if ((start = fn_add(in, dest, b, e)) == 0)
		return ;
	while ((lit = b[0]) != '}')
	{
		b++;
		if (lit == '\\')
			dest = ft_42sh_replase_slesh_exp(dest, &b, e);
		else if (lit == '\'')
			dest = ft_42sh_replase_quotes_one(in, dest, &b);
		else if (lit == '"')
			dest = ft_42sh_replase_quotes_two(in, dest, &b, e);
		else if (lit == '$')
			dest = ft_42sh_exp_parsing(in, dest, &b, e);
		else if (lit == '~' && ft_42sh_replase_home_test(in->array,
		start, b, e) != 0)
			dest = ft_42sh_replase_home(in->array, dest, &b);
		else if (lit == '\n')
			dest[-1] = '\n';
		else
			dest++[0] = lit;
	}
}