/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_hrdc_find.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

unsigned char	ft_42sh_dq_test_hrdc_find(unsigned char **out,
register unsigned char *e)
{
	unsigned char					*b;
	register unsigned char			litter;

	b = *out;
	litter = 0;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (litter == '"' || litter == '\'')
			ft_42sh_dq_skip_dq(&b, e, litter);
		else if (litter == '$' && b < e && b[0] == '{')
			ft_42sh_exp_pars_exp_skip(&b, e);
		else if (litter == '<' && b[0] == '<')
			break ;
	}
	*out = b + 1;
	return (litter);
}
