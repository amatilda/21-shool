/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:33:38 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

void		*help_dos(long long *stackos, long long *stackzn, t_calc_token *c,
		t_int *lastint)
{
	void			*tmp;

	while (lastint->zl > 0 &&
	prior(stackzn[lastint->zl - 1]) >= prior(c->type))
	{
		if (((tmp = calc(stackos, lastint,
				stackzn[lastint->zl - 1], c->var))) != 0)
			return (tmp);
		subzn(stackzn, lastint);
	}
	addzn(stackzn, c->type, lastint);
	return (0);
}

void		*dostack(long long *stackos, long long *stackzn, t_calc_token *c,
		t_int *lastint)
{
	void				*tmp;

	if ((c->type == CALC_FIR_SC || (lastint->zl != 0 &&
	prior(stackzn[lastint->zl - 1])
	< prior(c->type))) && c->type != CALC_SEC_SC)
		addzn(stackzn, c->type, lastint);
	else if (c->type == CALC_SEC_SC)
	{
		while (stackzn[lastint->zl - 1] != CALC_FIR_SC)
		{
			if (((tmp = calc(stackos, lastint, stackzn[lastint->zl - 1],
					c->var))) != 0)
				return (tmp);
			subzn(stackzn, lastint);
		}
		subzn(stackzn, lastint);
	}
	else if ((tmp = help_dos(stackos, stackzn, c, lastint)) != 0)
		return (tmp);
	return (0);
}
