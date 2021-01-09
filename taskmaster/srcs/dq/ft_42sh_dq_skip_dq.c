/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_skip_dq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_dq.h"

static void		fn_dq(unsigned char **out, register unsigned char *e)
{
	register unsigned char		*b;

	b = *out;
	while (b < e)
	{
		if ('\'' == b++[0])
			break ;
	}
	*out = b;
	return ;
}

void			ft_42sh_dq_skip_dq(unsigned char **out,
register unsigned char *e, register unsigned char lit)
{
	unsigned char				*b;
	register unsigned char		litter;

	if (lit == '\'')
		return (fn_dq(out, e));
	b = *out;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\')
			b++;
		else if (lit == '$' && b < e && b[0] == '{')
			ft_42sh_exp_pars_exp_skip(&b, e);
		else if (litter == '"')
			break ;
	}
	*out = b;
	return ;
}
