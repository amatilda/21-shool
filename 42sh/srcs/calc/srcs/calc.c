/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:25:00 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

static int	calc_znaks(long long *stackzn, int zl)
{
	int		i;
	int		calc_znaks;

	i = 0;
	calc_znaks = 0;
	while (i < zl)
	{
		if (stackzn[i] != CALC_FIR_SC && stackzn[i] != CALC_SEC_SC)
			calc_znaks++;
		i++;
	}
	return (calc_znaks);
}

static void	*error_return_calc(int error, char *error_str)
{
	if (error == 1)
	{
		return (ft_42sh_calc_error_pre(": calc: division by zero error",
		"", ""));
	}
	if (error == 2)
	{
		return (ft_42sh_calc_error_pre(": calc: (error token is \"",
		error_str, "\")"));
	}
	return (0);
}

static void	calc_next(long long *stackos, t_int *str, t_calc_tkntype c)
{
	if (c == CALC_DIFF)
		stackos[str->ol - 2] = stackos[str->ol - 2] != stackos[str->ol - 1];
	else if (c == CALC_EQ)
		stackos[str->ol - 2] = stackos[str->ol - 2] == stackos[str->ol - 1];
	else if (c == CALC_MOREOREQ)
		stackos[str->ol - 2] = stackos[str->ol - 2] >= stackos[str->ol - 1];
	else if (c == CALC_LESSOREQ)
		stackos[str->ol - 2] = stackos[str->ol - 2] <= stackos[str->ol - 1];
	else if (c == CALC_AND)
		stackos[str->ol - 2] = stackos[str->ol - 2] && stackos[str->ol - 1];
	else if (c == CALC_OR)
		stackos[str->ol - 2] = stackos[str->ol - 2] || stackos[str->ol - 1];
	subos(stackos, str);
}

void		*calc(long long *stackos, t_int *str, t_calc_tkntype c,
		char *error_var)
{
	if (str->ol - calc_znaks(str->stackzn, str->zl) < 1)
		return (error_return_calc(2, error_var));
	if ((c == CALC_DIV || c == CALC_MOD) && stackos[str->ol - 1] == 0)
		return (error_return_calc(1, error_var));
	if (c == CALC_MINUS)
		stackos[str->ol - 2] = stackos[str->ol - 2] - stackos[str->ol - 1];
	else if (c == CALC_PLUS)
		stackos[str->ol - 2] = stackos[str->ol - 2] + stackos[str->ol - 1];
	else if (c == CALC_MUL)
		stackos[str->ol - 2] = stackos[str->ol - 2] * stackos[str->ol - 1];
	else if (c == CALC_DIV)
		stackos[str->ol - 2] = stackos[str->ol - 2] / stackos[str->ol - 1];
	else if (c == CALC_MOD)
		stackos[str->ol - 2] = stackos[str->ol - 2] % stackos[str->ol - 1];
	else if (c == CALC_MORE)
		stackos[str->ol - 2] = stackos[str->ol - 2] > stackos[str->ol - 1];
	else if (c == CALC_LESS)
		stackos[str->ol - 2] = stackos[str->ol - 2] < stackos[str->ol - 1];
	calc_next(stackos, str, c);
	return (0);
}
