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

t_calc_token	*calc_prev_mean_calc_token(t_calc_token *tmp)
{
	while (tmp && (tmp->type == CALC_FIR_SC || tmp->type == CALC_SEC_SC))
	{
		tmp = tmp->prev;
	}
	return (tmp);
}

t_int			*cr_new_el(char *s, int *error)
{
	t_int	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_int))))
		return (NULL);
	tmp = tmp_0(tmp, s);
	if (!(tmp->stackos = (long long*)ft_memalloc(20 * ft_strlen(tmp->s))))
		return (NULL);
	if (!(tmp->stackzn = (long long*)ft_memalloc(20 * ft_strlen(tmp->s))))
		return (NULL);
	return (tmp);
	(void)error;
}

int				prior(int c)
{
	if (c == CALC_MUL)
		return (3);
	else if (c == CALC_DIV)
		return (3);
	else if (c == CALC_MOD)
		return (3);
	else if (c == CALC_PLUS)
		return (3);
	else if (c == CALC_MINUS)
		return (3);
	else if (c == CALC_FIR_SC || c == CALC_SEC_SC)
		return (0);
	else if (is_znak_type(c))
		return (1);
	else
		return (0);
}

int				is_znak(int c)
{
	if (c == '-' || c == '+' || c == '<' || c == '>' || c == '=' ||
	c == '&' || c == '|' || c == '*' || c == '/' || c == '%' || c == '!')
		return (1);
	else
		return (0);
}

long long		calcend(t_cacl_in *in, t_int *l, t_int **str,
		int *error)
{
	long long		result;
	long long		*dop_stackos;
	long long		*dop_stackzn;

	dop_stackos = *(&l->stackos);
	dop_stackzn = *(&l->stackzn);
	while ((*str)->ol > 1)
	{
		if (((in->lp_error = calc(dop_stackos, *str,
		dop_stackzn[(*str)->zl - 1],
				(*str)->s))) != 0)
			return (return_with_error(in, NULL, error, (*str)));
		subzn(dop_stackzn, *str);
	}
	if ((*str)->ol <= 0)
		result = 0;
	else
		result = dop_stackos[0];
	free_calc_tokens((*str)->first_token);
	free(dop_stackos);
	free(dop_stackzn);
	free(*str);
	return (result);
}
