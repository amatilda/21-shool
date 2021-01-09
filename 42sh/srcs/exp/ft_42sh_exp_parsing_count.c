/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_parsing_count.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_exp.h"

static size_t			fn_finish_count(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **src, register unsigned char *end)
{
	register unsigned char			*b;
	register unsigned char			*tmp;
	register size_t					tempos;
	register t_env_42sh				*list;

	b = *src;
	tmp = ft_42sh_exp_name_special(b, end);
	if ((tempos = tmp - b) == 0)
	{
		if (tmp == end || (tmp[0] != '\'' && tmp[0] != '"'))
			return (1);
		*s = tmp;
		return (0);
	}
	*src = tmp;
	if ((list = ft_42sh_list_find_key(&in->array->env.root,
	(void *)b, tempos)) != 0 &&
	(tempos = ft_42sh_exp_parsing_value_count(in->array,
	list, in->b_mode)) != 0)
		return (tempos);
	*s = *src;
	return (0);
}

static size_t			fn_shield(t_replase_in_42sh *in,
unsigned char **src, register unsigned char *b,
register unsigned char *end)
{
	if (b + 4 <= end && ft_strncmp(b, "'\\n'", 4) == 0)
	{
		*src = b + 4;
		if ((in->b_mode & PARSING_MODE_CMD_42SH) != 0)
			return (2);
		else
			return (1);
	}
	return (0);
}

size_t					ft_42sh_exp_parsing_count(register
t_replase_in_42sh *in, unsigned char **s, unsigned char **src,
register unsigned char *end)
{
	register unsigned char			*b;
	register unsigned char			litter;

	b = *src;
	if ((litter = fn_shield(in, src, b, end)) != 0)
		return (litter);
	if (b + 1 < end && b[0] == '(' && b[1] == '(')
		return (ft_42sh_calc_count(in, s, src, end));
	if (b == end || in->array->env.root.first == 0)
		return (1);
	if ((litter = b[0]) == '{')
		return (ft_42sh_exp_pars_exp_count(in, s, src, end));
	return (fn_finish_count(in, s, src, end));
}
