/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inftopost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 13:26:44 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

long long		main_calc(t_cacl_in *in, t_calc_token *tmp_token,
int *error, t_int *l)
{
	while (tmp_token != NULL && tmp_token->type != CALC_END)
	{
		if (tmp_token->type == CALC_VAR)
			zam_var(in, tmp_token, error);
		if (*error == 0 && (tmp_token->type == CALC_NUMBER ||
		tmp_token->type == CALC_VAR))
		{
			addos(l->stackos, ft_atoi(tmp_token->var), l);
		}
		else if (*error == 0 && is_znak_type(tmp_token->type))
		{
			if (((in->lp_error = dostack(l->stackos,
			l->stackzn, tmp_token, l))) != 0)
				return (return_with_error(in, NULL, error, l));
		}
		if (*error != 0)
			return (return_with_error(in, NULL, error, l));
		tmp_token = tmp_token->next;
	}
	return (calcend(in, l, &l, error));
}

long long		eval_expr(t_cacl_in *in, char *s, int *error, char *rec_var)
{
	t_int			*l;
	t_calc_token	*tmp_token;

	if (!(l = cr_new_el(s, error)))
		return (c_e((t_calc){NULL, NULL, NULL, error, NULL}));
	tmp_token = ft_eval_parse(s, rec_var);
	l->first_token = tmp_token;
	if (get_last_token(tmp_token)->type == CALC_ERROR ||
	get_last_token(tmp_token)->type == CALC_REC_ERROR ||
	get_last_token(tmp_token)->type == CALC_NUM_OVERFLOW_ERROR)
		return (return_with_error(in, get_last_token(tmp_token), error, l));
	return (main_calc(in, tmp_token, error, l));
}
