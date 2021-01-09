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
unsigned char *b, register unsigned char *e, register uint_fast8_t b_test)
{
	register size_t			litter;

	while ((litter = ft_42sh_parsing_litter_e_f(b, e)) != 0 && litter > 0x20)
	{
		b++;
		if (litter == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if ((litter == '"' || litter == '\'') &&
		(b_test & DQ_HRDC_42SH) == 0 &&
		(litter = ft_42sh_dq_test_dq(array, &b, e, litter)) != 0)
			return ((void *)litter);
		else if (litter == '#' && (array->b_location & LOCATION_SCRIPT_42SH)
		!= 0 && (b_test & DQ_HRDC_42SH) == 0)
			b = ft_42sh_sh_comment(array, b - 1, e);
		else if (litter == '$')
			if ((litter = ft_42sh_dq_test_dq_exp(array, &b, e, b_test)) != 0)
				return ((void *)litter);
	}
	return (b);
}
