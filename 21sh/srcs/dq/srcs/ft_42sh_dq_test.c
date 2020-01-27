/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static unsigned char	fn_finish(register t_main_42sh *array,
register t_in_42sh *list, unsigned char *start, register unsigned char *b)
{
	register unsigned char		litter;

	if ((litter = ft_42sh_dq_test_slh(start, b - start)) != 0)
		return (litter);
	if ((litter = ft_42sh_parsing_test(array, start, b)) != 0)
		return (litter);
	return (ft_42sh_dq_test_hrdc(array, list, &start, b));
}

unsigned char			ft_42sh_dq_test(register t_main_42sh *array,
register t_in_42sh *list, unsigned char *b, register unsigned char *e)
{
	register unsigned char		litter;
	unsigned char				*start;

	start = b;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if ((litter == '"' || litter == '\'') &&
		(litter = ft_42sh_dq_test_dq(&b, e, litter)) != 0)
			return (litter);
		else if (litter == '{' &&
		(litter = ft_42sh_dq_test_sub(&b, e, litter)) != 0)
			return (litter);
		else if (litter == '\n')
		{
			if ((litter = ft_42sh_parsing_test(array, start, b)) != 0)
				return (litter);
			if ((litter = ft_42sh_dq_test_hrdc(array, list, &start, b)) != 0)
				return (litter);
			b = start;
		}
	}
	return (fn_finish(array, list, start, b));
}
