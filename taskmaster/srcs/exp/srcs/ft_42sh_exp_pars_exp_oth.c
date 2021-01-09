/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_pars_exp_oth.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static unsigned char	*fn_plus(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src, register unsigned char *end)
{
	register t_env_42sh				*list;
	register unsigned char			*tmp;
	unsigned char					*start;
	register size_t					count;

	if ((list = in->exp.env) == 0 || ft_42sh_exp_parsing_value_count(in->array,
	list, in->b_mode) == 0)
	{
		ft_42sh_exp_pars_exp_skip(src, end);
		return (dest);
	}
	tmp = *src;
	start = tmp;
	count = ft_42sh_replase_exp_count(in, &start, src, end);
	ft_42sh_replase_exp(in, dest, tmp, end);
	tmp = dest + count;
	return (tmp);
}

static unsigned char	*fn_eq(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src, register unsigned char *end)
{
	register t_env_42sh				*list;

	if ((list = in->exp.env) != 0 && ft_42sh_exp_parsing_value_count(in->array,
	list, in->b_mode) != 0)
	{
		ft_42sh_exp_pars_exp_skip(src, end);
		return (ft_42sh_exp_parsing_value(in->array, list, dest, in->b_mode));
	}
	return (ft_42sh_exp_pars_exp_set(in, dest, src, end));
}

static unsigned char	*fn_minus(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src, register unsigned char *end)
{
	register t_env_42sh				*list;
	register unsigned char			*tmp;
	unsigned char					*start;
	register size_t					count;

	if ((list = in->exp.env) != 0 && ft_42sh_exp_parsing_value_count(in->array,
	list, in->b_mode) != 0)
	{
		ft_42sh_exp_pars_exp_skip(src, end);
		return (ft_42sh_exp_parsing_value(in->array, list, dest, in->b_mode));
	}
	tmp = *src;
	start = tmp;
	count = ft_42sh_replase_exp_count(in, &start, src, end);
	ft_42sh_replase_exp(in, dest, tmp, end);
	tmp = dest + count;
	return (tmp);
}

static unsigned char	*fn_question(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src, register unsigned char *end)
{
	register t_env_42sh				*list;

	ft_42sh_exp_pars_exp_skip(src, end);
	if ((list = in->exp.env) != 0 && ft_42sh_exp_parsing_value_count(in->array,
	list, in->b_mode) != 0)
		return (ft_42sh_exp_parsing_value(in->array, list, dest, in->b_mode));
	return (dest);
}

unsigned char			*ft_42sh_exp_pars_exp_oth(register
t_replase_in_42sh *in, register unsigned char *dest,
unsigned char **src, register unsigned char *end)
{
	unsigned char					*b;
	register unsigned char			litter;

	b = *src + 1;
	if ((litter = b++[0]) == '?')
		dest = fn_question(in, dest, &b, end);
	else if (litter == '+')
		dest = fn_plus(in, dest, &b, end);
	else if (litter == '-')
		dest = fn_minus(in, dest, &b, end);
	else
		dest = fn_eq(in, dest, &b, end);
	*src = b;
	return (dest);
}