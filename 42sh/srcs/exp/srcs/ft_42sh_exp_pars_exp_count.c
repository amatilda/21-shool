/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_pars_exp_count.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static size_t			fn_cmp_count(register t_replase_in_42sh *in,
register unsigned char *b, register size_t tempos)
{
	register t_env_42sh				*list;

	if ((list = ft_42sh_list_find_key(&in->array->env.root,
	(void *)b, tempos)) != 0 &&
	(tempos = ft_42sh_exp_parsing_value_count(in->array, list, in->b_mode)) != 0)
		return (tempos);
	return (0);
}

static size_t			fn_not_count(unsigned char **s, unsigned char **src,
register unsigned char *end)
{
	*src = ft_42sh_parsing_sp(*src, end);
	*s = *src;
	return (0);
}

static size_t		fn_eq(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **src, register unsigned char *end)
{
	register size_t					count;
	register t_env_42sh				*list;
	unsigned char					*start;

	*src = *src + 1;
	if ((list = in->exp.env) != 0)
	{
		ft_42sh_exp_pars_exp_skip(src, end);
		if ((count = ft_42sh_exp_parsing_value_count(in->array, list, in->b_mode)) == 0)
			*s = *src;
		return (count);
	}
	start = *src;
	if ((count = ft_42sh_replase_exp_count(in, &start, src, end)) == 0)
	{
		ft_42sh_exp_pars_exp_set_count(in);
		*s = *src;
	}
	return (count);
}

static size_t			ft_other_count(register t_replase_in_42sh *in,
 unsigned char **s, unsigned char **src, register unsigned char *end)
{
	register unsigned char			*b;
	register unsigned char			litter;

	b = *src;
	if ((litter = b[0]) == ':')
		return (ft_42sh_exp_pars_exp_oth_count(in, s, src, end));
	else if (litter == '=')
		return (fn_eq(in, s, src, end));
	else if (litter == '%')
		return (ft_42sh_exp_pars_exp_sufix_count(in, s, src, end));
	else if (litter == '#')
		return (ft_42sh_exp_pars_exp_prefix_count(in, s, src, end));
	return (fn_not_count(s, src, end));
}

size_t					ft_42sh_exp_pars_exp_count(
register t_replase_in_42sh *in, unsigned char **s, unsigned char **src,
register unsigned char *end)
{
	register unsigned char			*b;
	register unsigned char			*tmp;
	register unsigned char			litter;
	register size_t					tempos;

	b = *src + 1;
	if ((litter = b[0]) == '#')
		b++;
	tmp = (b[0] == '?') ?  b + 1 : ft_42sh_exp_name(b, end);
	if (tmp[0] != '}')
	{
		tempos = tmp - b;
		in->exp.key = b;
		in->exp.key_count = tempos;
		in->exp.env = ft_42sh_list_find_key(&in->array->env.root, b, tempos);
		*src = tmp;
		return (ft_other_count(in, s, src, end));
	}
	*src = tmp + 1;
	if (litter == '#')
		return (ft_42sh_exp_pars_exp_litter_count(in->array, b, tmp));
	if ((tempos = fn_cmp_count(in, b, tmp - b)) != 0)
		return (tempos);
	return (fn_not_count(s, src, end));
}
