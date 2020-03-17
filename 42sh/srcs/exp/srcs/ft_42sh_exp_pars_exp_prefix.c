/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_pars_exp_prefix.c                      :+:      :+:    :+:   */
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

static void		*fn_finish(register unsigned char *dest, 
register unsigned char *b, register unsigned char *e)
{
	register size_t					count;

	count = e - b;
	ft_memcpy(dest, b, count);
	return (dest + count);
}

static void		*fn_one(register unsigned char *cmp,
register unsigned char *cmp_end, register unsigned char *pattern,
register unsigned char *pattern_end)
{
	register unsigned char 			*tmp;

	if (pattern == pattern_end)
		return (cmp);
	tmp = cmp;
	while (tmp < cmp_end)
	{
		if (ft_42sh_pattern(cmp, tmp, pattern, pattern_end) != 0)
			return (tmp);
		tmp++;
	}
	return (cmp);
}

static void		*fn_two(register unsigned char *cmp,
register unsigned char *cmp_end, register unsigned char *pattern,
register unsigned char *pattern_end)
{
	register unsigned char 			*tmp;

	if (pattern == pattern_end)
		return (cmp);
	tmp = cmp_end;
	while (cmp < tmp)
	{
		if (ft_42sh_pattern(cmp, tmp, pattern, pattern_end) != 0)
			return (tmp);
		tmp--;
	}
	return (cmp);
}

unsigned char		*ft_42sh_exp_pars_exp_prefix(register
t_replase_in_42sh *in, register unsigned char *dest, unsigned char **src,
register unsigned char *end)
{
	register size_t					count;
	register unsigned char 			*out;
	register unsigned char 			*cmp;
	uint_fast8_t					b_test;
	t_exp_in_exp_42sh				ptr;

	if (in->exp.env == 0 || (count = ft_42sh_exp_parsing_value_count(in->array,
	in->exp.env, in->b_mode)) == 0)
		return (dest);
	out = *src;
	b_test = (out[1] == '#') ? 1 : 0;
	*src = out + b_test + 1;
	cmp = fn_str(in->exp.env, ptr.buff);
	ptr.start = *src;
	ptr.count = ft_42sh_replase_exp_count(in, &ptr.start, src, end);
	if ((out = ft_malloc(ptr.count)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_42sh_replase_exp(in, out, ptr.start, end);
	end = cmp + count;
	if (b_test == 0)
		dest = fn_finish(dest, fn_one(cmp, end, out, out + ptr.count), end);
	else
		dest = fn_finish(dest, fn_two(cmp, end, out, out + ptr.count), end);
	ft_free(out);
	return (dest);
}