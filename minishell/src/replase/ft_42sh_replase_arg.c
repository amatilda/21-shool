/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		*fn_cmd_pre(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char			litter;

	while (b < e && ((litter = b[0]) == 0x20 ||
	(litter == '\\' && b[1] == 0x20)))
		b++;
	return (b);
}

size_t			ft_42sh_replase_arg_count(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register size_t count)
{
	register unsigned char	litter;
	register unsigned char	dquote;
	unsigned char			*b;

	b = fn_cmd_pre(*out, e);
	dquote = 0;
	while ((litter = ft_42sh_parsing_test_next(&b, e, dquote)) != 0)
	{
		if (litter == '\\')
			count += ft_42sh_replase_slesh_count(&b, e, dquote);
		else if (litter == '\n')
			count++;
		else if (litter == '$')
			count += ft_42sh_env_parsing_count(&array->env.env, &b, e);
		else if (litter == '~' && dquote == 0)
			count += ft_42sh_replase_home_count(array, b, e);
		else if (litter == '"' || litter == '\'')
			dquote = (litter == dquote) ? 0 : litter;
		else
			count++;
	}
	*out = b;
	return (count);
}

size_t			ft_42sh_replase_arg_big(register t_main_42sh *array,
unsigned char *b, register unsigned char *e)
{
	register size_t			count;
	register unsigned char	litter;

	count = 0;
	while (b < e && (litter = b[0]) != ';' && litter != '\n')
	{
		if (ft_42sh_replase_arg_count(array, &b, e, 0) != 0)
			count++;
	}
	return (count);
}

void			ft_42sh_replase_arg(register t_main_42sh *array,
register unsigned char *dest, unsigned char *b, register unsigned char *e)
{
	register unsigned char	litter;
	register unsigned char	dquote;

	b = fn_cmd_pre(b, e);
	dquote = 0;
	while ((litter = ft_42sh_parsing_test_next(&b, e, dquote)) != 0)
	{
		if (litter == '\\')
			dest = ft_42sh_replase_slesh(dest, &b, e, dquote);
		else if (litter == '\n')
			dest++[0] = '\n';
		else if (litter == '$')
			dest = ft_42sh_env_parsing(&array->env.env, dest, &b, e);
		else if (litter == '~' && dquote == 0)
			dest = ft_42sh_replase_home(array, dest, b, e);
		else if (litter == '"' || litter == '\'')
			dquote = (litter == dquote) ? 0 : litter;
		else
			dest++[0] = litter;
	}
}
