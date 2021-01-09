/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_replase.h"

static size_t	fn_exp_count(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **out, register unsigned char *e)
{
	register size_t			count;

	count = ft_42sh_exp_parsing_count(in, s, out, e);
	if (*s == *out)
	{
		*out = ft_42sh_parsing_sp(*out, e);
		*s = *out;
	}
	return (count);
}

static size_t	fn_pre_count(unsigned char **s, unsigned char **out,
register unsigned char *e, unsigned char *lit)
{
	*s = ft_42sh_parsing_sp(*s, e);
	*out = *s;
	*lit = 0x20;
	return (0);
}

size_t			ft_42sh_replase_count(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **out, register unsigned char *e)
{
	unsigned char			lit;
	register size_t			count;

	count = fn_pre_count(s, out, e, &lit);
	while ((lit = ft_42sh_parsing_test_next(out, e, 0, lit)) != 0)
	{
		if (lit == '\\')
			count += ft_42sh_replase_slesh_count(out, e);
		else if (lit == '\'')
			count += ft_42sh_replase_quotes_one_count(in, out);
		else if (lit == '"')
			count += ft_42sh_replase_quotes_two_count(in, out, e);
		else if (lit == '$' && (in->b_mode & PARSING_MODE_HRDC_42SH) == 0)
		{
			count += fn_exp_count(in, s, out, e);
			if ((*out)[-1] == 0x20)
				break ;
		}
		else if (lit == '~' && ft_42sh_replase_add_tilda(in, *s, *out, e) != 0)
			count += ft_42sh_replase_home_count(in->array, out);
		else
			count++;
	}
	*out = ft_42sh_parsing_sp(*out, e);
	return (count);
}

static void		*fn_pre(register t_replase_in_42sh *in,
unsigned char **b, register unsigned char *e, size_t *exps_loop)
{
	if ((in->array->b_location & LOCATION_NOT_SET_42SH) == 0 &&
	(in->b_mode & PARSING_MODE_HRDC_42SH) == 0)
		*exps_loop = ((t_jobs_42sh *)in->array->pr.jb.last)->exps_loop++;
	*b = ft_42sh_parsing_sp(*b, e);
	return (*b);
}

void			ft_42sh_replase(register t_replase_in_42sh *in,
unsigned char *dest, unsigned char *b, register unsigned char *e)
{
	register unsigned char		lit;
	t_replase_in				st;

	st.s = fn_pre(in, &b, e, &st.exps_loop);
	lit = 0x20;
	while ((lit = ft_42sh_parsing_test_next(&b, e, 0, lit)) != 0)
	{
		if (lit == '\\')
			dest = ft_42sh_replase_slesh(dest, &b, e);
		else if (lit == '\'')
			dest = ft_42sh_replase_quotes_one(in, dest, &b);
		else if (lit == '"')
			dest = ft_42sh_replase_quotes_two(in, dest, &b, e);
		else if (lit == '$' && (in->b_mode & PARSING_MODE_HRDC_42SH) == 0)
		{
			dest = ft_42sh_exp_parsing(in, dest, &b, e);
			if (b[-1] == 0x20)
				break ;
		}
		else if (lit == '~' && ft_42sh_replase_add_tilda(in, st.s, b, e) != 0)
			dest = ft_42sh_replase_home(in->array, dest, &b);
		else
			dest++[0] = lit;
	}
	return (ft_42sh_replase_add_finish(in, st.exps_loop));
}
