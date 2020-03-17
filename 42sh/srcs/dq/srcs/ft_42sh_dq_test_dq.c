/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_dq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

static unsigned char	fn_finish(register t_main_42sh *array,
unsigned char *tmp, register unsigned char litter)
{
	if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
		ft_42sh_dq_test_err_n(array, MSG_SINTAX_ERROR_42SH, tmp, 1);
	return (litter);
}

static unsigned char	fn_dq(register t_main_42sh *array,
unsigned char **out, register unsigned char *e)
{
	register unsigned char		*b;
	unsigned char				*tmp;

	b = *out;
	tmp = b - 1;
	while (b < e)
	{
		if ('\'' == b++[0])
		{
			*out = b;
			return (0);
		}
	}
	*out = b;
	return (fn_finish(array, tmp, '\''));
}

unsigned char			ft_42sh_dq_test_dq(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register unsigned char litter)
{
	unsigned char			*b;
	unsigned char			*tmp;

	if (litter == '\'')
		return (fn_dq(array, out, e));
	b = *out;
	tmp = b - 1;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (litter == '"')
		{
			*out = b;
			return (0);
		}
		else if (litter == '$' )
			if ((litter = ft_42sh_dq_test_dq_exp(array, &b, e)) != 0)
				return (litter);
	}
	*out = b;
	return (fn_finish(array, tmp, '"'));
}
