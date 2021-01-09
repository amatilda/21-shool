/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_pars_exp_skip.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

unsigned char	**ft_42sh_exp_pars_exp_skip(unsigned char **out,
register unsigned char *e)
{
	register unsigned char	lit;
	unsigned char			*b;

	b = *out;
	while ((lit = b++[0]) != '}')
	{
		if (lit == '\\')
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (lit == '"' || lit == '\'')
			ft_42sh_dq_skip_dq(&b, e, lit);
		else if (lit == '$' && b[0] == '{')
			ft_42sh_exp_pars_exp_skip(&b, e);
	}
	*out = ft_42sh_parsing_sp(b, e);
	return ((unsigned char **)out);
}