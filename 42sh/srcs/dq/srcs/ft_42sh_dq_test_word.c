/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

unsigned char		*ft_42sh_dq_test_word(register t_main_42sh *array,
unsigned char *b, register unsigned char *e)
{
	register size_t			litter;

	while ((litter = ft_42sh_parsing_litter_e_f(b, e)) != 0 && litter > 0x20)
	{
		b++;
		if (litter == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if ((litter == '"' || litter == '\'') &&
		(litter = ft_42sh_dq_test_dq(array, &b, e, litter)) != 0)
			return ((void *)litter);
		else if (litter == '#')
			b = ft_42sh_sh_comment(array, b, e);
		else if (litter == '$' )
			if ((litter = ft_42sh_dq_test_dq_exp(array, &b, e)) != 0)
				return ((void *)litter);
	}
	return(b);
}
