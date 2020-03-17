/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_while_logic.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_parsing.h"

static unsigned char	*fn_end(register t_main_42sh *array,
unsigned char *b, register unsigned char *e)
{
	ft_42sh_parsing_end(array, &b, e, ft_42sh_parsing_litter_e);
	return (ft_42sh_parsing_while_logic(array, b, e));
}

unsigned char			*ft_42sh_parsing_while_logic(
register t_main_42sh *array, register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		litter;
	register size_t				tempos;

	if (b + 1 >= e)
		return (b);
	if (((litter = b[0]) == '&' || litter == '|') && b[1] == litter)
	{
		b += 2;
		tempos = array->env.exit_status->number;
		if (litter == '&')
		{
			if (tempos == 0)
				return (b);
			return (fn_end(array, b, e));
		}
		if (tempos != 0)
			return (b);
		return (fn_end(array, b, e));
	}
	return (b);
}
