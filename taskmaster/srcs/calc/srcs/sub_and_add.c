/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_and_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 19:49:02 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

void	addos(long long *stackos, int c, t_int *lastint)
{
	stackos[lastint->ol] = c;
	(lastint->ol)++;
}

void	subos(long long *stackos, t_int *lastint)
{
	stackos[lastint->ol - 1] = 0;
	(lastint->ol)--;
}

void	addzn(long long *stackzn, t_calc_tkntype c, t_int *lastint)
{
	stackzn[lastint->zl] = c;
	(lastint->zl)++;
}

void	subzn(long long *stackzn, t_int *lastint)
{
	stackzn[lastint->zl - 1] = 0;
	(lastint->zl)--;
}
