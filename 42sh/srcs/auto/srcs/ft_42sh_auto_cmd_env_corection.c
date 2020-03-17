/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_cmd_env_corection.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_auto.h"

static size_t	fn_test(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char			litter;

	if (b == e)
		return (1);
	if ((litter = b++[0]) == '#' || litter == '%')
		return (1);
	else if (litter == '=')
		return (1);
	else if (litter == ':' && b < e && ((litter = b[0]) == '?' || litter == '+' ||
	litter == '=' || litter == '-'))
		return (1);
	return (0);
}

static size_t		fn_len(register t_main_42sh *array,
register unsigned char *tmp, register unsigned char *b,
register unsigned char *e)
{
	if (tmp == e || tmp[0] == '}')
	{
		array->env.offset_auto = 3;
		return (tmp - b);
	}
	else
		return (e - b);
}

size_t				ft_42sh_auto_cmd_env_corection(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b, register size_t n)
{
	register unsigned char			*e;
	register unsigned char			*tmp;
	register unsigned char			litter;

	array->env.offset_auto = 2;
	if (array->lp_auto != &array->auto_env || b == 0 || n == 0 ||
	array->pguitar.comp.figure == 0)
		return (n);
	if ((litter = b[0]) == '#')
		b++;
	e = (void *)list->lp_current;
	if (b < e && b[0] == '?')
		tmp = b + 1;
	else
		tmp = ft_42sh_exp_test_exp_auto(b, e);
	if (litter == '#')
		return (fn_len(array, tmp, b, e));
	if (tmp < e && tmp[0] == '}')
		return (tmp - b);
	if (fn_test(tmp, e) == 0)
		return (e - b);
	return (tmp - b);
}