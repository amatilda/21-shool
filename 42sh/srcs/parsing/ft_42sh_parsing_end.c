/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_end.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

size_t			ft_42sh_parsing_end(register t_main_42sh *array,
unsigned char **out, register unsigned char *e,
unsigned char (*f)(register unsigned char *b, register unsigned char *e))
{
	register unsigned char	old;
	register unsigned char	litter;
	unsigned char			*b;

	b = *out;
	old = 0x20;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\')
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (litter == '"' || litter == '\'')
			ft_42sh_dq_skip_dq(&b, e, litter);
		else if (litter == '$' && b < e && b[0] == '{')
			ft_42sh_exp_pars_exp_skip(&b, e);
		else if (litter != '|' && (old = ft_42sh_parsing_test_pipe(b - 1, e, old)) != 0)
			b += old;
		else if (f(b - 1, e) == 0)
		{
			b--;
			break ;
		}
		old = litter;
	}
	*out = b;
	return (0);
	(void)array;
}
