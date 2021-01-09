/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_pars_exp_oth_count.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static size_t		fn_plus(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **src, register unsigned char *end)
{
	register size_t					count;
	register t_env_42sh				*list;
	unsigned char					*start;

	list = in->exp.env;
	if (list == 0 ||
	ft_42sh_exp_parsing_value_count(in->array, list, in->b_mode) == 0)
	{
		ft_42sh_exp_pars_exp_skip(src, end);
		*s = *src;
		return (0);
	}
	start = *src;
	if ((count = ft_42sh_replase_exp_count(in, &start, src, end)) == 0)
		*s = *src;
	return (count);
}

static size_t		fn_eq(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **src, register unsigned char *end)
{
	register size_t					count;
	register t_env_42sh				*list;

	list = in->exp.env;
	if (list != 0 && (count = ft_42sh_exp_parsing_value_count(in->array,
	list, in->b_mode)) != 0)
	{
		ft_42sh_exp_pars_exp_skip(src, end);
		return (count);
	}
	return (ft_42sh_exp_pars_exp_set_count(in, s, src, end));
}

static size_t		fn_minus(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **src, register unsigned char *end)
{
	register size_t					count;
	register t_env_42sh				*list;
	unsigned char					*start;

	list = in->exp.env;
	if (list != 0 && (count = ft_42sh_exp_parsing_value_count(in->array,
	list, in->b_mode)) != 0)
	{
		ft_42sh_exp_pars_exp_skip(src, end);
		return (count);
	}
	start = *src;
	if ((count = ft_42sh_replase_exp_count(in, &start, src, end)) == 0)
		*s = *src;
	return (count);
}

size_t				ft_42sh_exp_pars_exp_oth_count(register
t_replase_in_42sh *in, unsigned char **s, unsigned char **src,
register unsigned char *end)
{
	unsigned char					*b;
	register unsigned char			litter;
	register size_t					count;

	b = *src + 1;
	if ((litter = b++[0]) == '?')
		count = ft_42sh_exp_pars_exp_oth_count_question(in, s, &b, end);
	else if (litter == '+')
		count = fn_plus(in, s, &b, end);
	else if (litter == '-')
		count = fn_minus(in, s, &b, end);
	else
		count = fn_eq(in, s, &b, end);
	*src = b;
	return (count);
}
