/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_replase.h"

size_t			ft_42sh_replase_cmd_count(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register size_t count)
{
	register unsigned char	litter;
	register unsigned char	dquote;
	unsigned char			*b;

	b = ft_42sh_parsing_sp(*out, e);
	dquote = 0;
	litter = 0x20;
	while ((litter = ft_42sh_parsing_test_next(&b, e, dquote, litter)) != 0)
	{
		if (litter == '\\')
			count += ft_42sh_replase_slesh_count(&b, e, dquote);
		else if (litter == '\n')
			count++;
		else if (litter == '$')
			count += ft_42sh_exp_parsing_count(&array->env.env, &b, e);
		else if (litter == '~' && dquote == 0)
			count += ft_42sh_replase_home_count(array, b, e);
		else if (dquote == litter || (dquote == 0 &&
		(litter == '"' || litter == '\'')))
			dquote = (litter == dquote) ? 0 : litter;
		else
			count++;
	}
	*out = ft_42sh_parsing_sp(b, e);
	return (count);
}

void			ft_42sh_replase_cmd(register t_main_42sh *array,
register unsigned char *dest, unsigned char *b, register unsigned char *e)
{
	register unsigned char	litter;
	register unsigned char	dquote;

	b = ft_42sh_parsing_sp(b, e);
	dquote = 0;
	litter = 0x20;
	while ((litter = ft_42sh_parsing_test_next(&b, e, dquote, litter)) != 0)
	{
		if (litter == '\\')
			dest = ft_42sh_replase_slesh(dest, &b, e, dquote);
		else if (litter == '\n')
			dest = ft_memcpy(dest - 1, "\\n", 2) + 2;
		else if (litter == '$')
			dest = ft_42sh_exp_parsing(&array->env.env, dest, &b, e);
		else if (litter == '~' && dquote == 0)
			dest = ft_42sh_replase_home(array, dest, b, e);
		else if (dquote == litter || (dquote == 0 &&
		(litter == '"' || litter == '\'')))
			dquote = (litter == dquote) ? 0 : litter;
		else
			dest++[0] = litter;
	}
}
