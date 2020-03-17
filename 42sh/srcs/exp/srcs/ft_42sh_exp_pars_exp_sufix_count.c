/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_pars_exp_sufix_count.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static void			*fn_str(register t_env_42sh *list, char *buff)
{
	if ((list->b_type & EXP_TYPE_NUMBER_42SH) == 0)
		return (list->lp_value);
	ft_itoa(buff, list->number, 10, ITOA_LOWER);
	return (buff);
}

static size_t		fn_finish(unsigned char **s, unsigned char **src,
register size_t count)
{
	if (count == 0)
	{
		*s = *src;
		return (0);
	}
	return (count);
}

static size_t		fn_one(register unsigned char *cmp,
register unsigned char *cmp_end, register unsigned char *pattern,
register unsigned char *pattern_end)
{
	register unsigned char 			*tmp;

	if (pattern == pattern_end)
		return (cmp_end - cmp);
	tmp = cmp_end;
	while (tmp > cmp)
		if (ft_42sh_pattern(--tmp, cmp_end, pattern, pattern_end) != 0)
			return (tmp - cmp);
	return (cmp_end - cmp);
}

static size_t		fn_two(register unsigned char *cmp,
register unsigned char *cmp_end, register unsigned char *pattern,
register unsigned char *pattern_end)
{
	register unsigned char 			*tmp;

	if (pattern == pattern_end)
		return (cmp_end - cmp);
	tmp = cmp;
	while (tmp < cmp_end)
	{
		if (ft_42sh_pattern(tmp, cmp_end, pattern, pattern_end) != 0)
			return (tmp - cmp);
		tmp++;
	}
	return (cmp_end - cmp);
}

size_t				ft_42sh_exp_pars_exp_sufix_count(register
t_replase_in_42sh *in, unsigned char **s, unsigned char **src,
register unsigned char *end)
{
	register size_t					count;
	register unsigned char 			*out;
	register unsigned char 			*cmp;
	uint_fast8_t					b_test;
	t_exp_in_exp_42sh				ptr;

	if (in->exp.env == 0 || (count = ft_42sh_exp_parsing_value_count(in->array,
	in->exp.env, in->b_mode)) == 0)
		return (fn_finish(s, ft_42sh_exp_pars_exp_skip(src, end), 0));
	out = *src;
	b_test = (out[1] == '%') ? 1 : 0;
	*src = out + b_test + 1;
	cmp = fn_str(in->exp.env, ptr.buff);
	ptr.start = *src;
	ptr.count = ft_42sh_replase_exp_count(in, &ptr.start, src, end);
	if ((out = ft_malloc(ptr.count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_42sh_replase_exp(in, out, ptr.start, end);
	end = cmp + count;
	if (b_test == 0)
		count = fn_finish(s, src, fn_one(cmp, end, out, out + ptr.count));
	else
		count = fn_finish(s, src, fn_two(cmp, end, out, out + ptr.count));
	ft_free(out);
	return (count);
}