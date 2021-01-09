/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_pars_exp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static unsigned char	*fn_cmp(register t_replase_in_42sh *in,
register unsigned char *dest, register unsigned char *b, register size_t tempos)
{
	register t_env_42sh				*list;

	if ((list = ft_42sh_list_find_key(&in->array->env.root,
	(void *)b, tempos)) != 0 &&
	(tempos = (size_t)ft_42sh_exp_parsing_value(in->array,
	list, dest, in->b_mode)) != (size_t)dest)
		return ((void *)tempos);
	return (0);
}

static unsigned char	*fn_eq(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src, register unsigned char *end)
{
	register t_env_42sh				*list;

	*src = *src + 1;
	if ((list = in->exp.env) != 0)
	{
		ft_42sh_exp_pars_exp_skip(src, end);
		return (ft_42sh_exp_parsing_value(in->array, list, dest, in->b_mode));
	}
	return (ft_42sh_exp_pars_exp_set(in, dest, src, end));
}

static unsigned char	*ft_other(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src, register unsigned char *end)
{
	register unsigned char			*b;
	register unsigned char			litter;

	b = *src;
	if ((litter = b[0]) == ':')
		return (ft_42sh_exp_pars_exp_oth(in, dest, src, end));
	else if (litter == '=')
		return (fn_eq(in, dest, src, end));
	else if (litter == '%')
		return (ft_42sh_exp_pars_exp_sufix(in, dest, src, end));
	else if (litter == '#')
		return (ft_42sh_exp_pars_exp_prefix(in, dest, src, end));
	return (dest);
}

unsigned char			*ft_42sh_exp_pars_exp(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src, register unsigned char *end)
{
	register unsigned char			*b;
	register unsigned char			*tmp;
	register unsigned char			litter;
	register size_t					tempos;

	b = *src + 1;
	if ((litter = b[0]) == '#')
		b++;
	tmp = ft_42sh_exp_name_special(b, end);
	if (tmp[0] != '}')
	{
		tempos = tmp - b;
		in->exp.key = b;
		in->exp.key_count = tempos;
		in->exp.env = ft_42sh_list_find_key(&in->array->env.root, b, tempos);
		*src = tmp;
		return (ft_other(in, dest, src, end));
	}
	*src = tmp + 1;
	if (litter == '#')
		return (ft_42sh_exp_pars_exp_litter(in->array, dest, b, tmp));
	if ((b = fn_cmp(in, dest, b, tmp - b)) != 0)
		return (b);
	return (dest);
}
