/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 19:53:08 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

void			free_calc_tokens(t_calc_token *tmp)
{
	t_calc_token	*dop;

	while (tmp != NULL)
	{
		ft_strdel(&tmp->var);
		dop = tmp;
		tmp = tmp->next;
		free(dop);
	}
}

int				return_with_error(t_cacl_in *in, t_calc_token *error_token,
int *error, t_int *l)
{
	*error = 1;
	if (error_token != NULL &&
	error_token->type == CALC_ERROR)
		in->lp_error = ft_42sh_calc_error_pre(
			": error in expression (error token is \"",
			error_token->var, """\")");
	else if (error_token != NULL &&
	error_token->type == CALC_REC_ERROR)
		in->lp_error = ft_42sh_calc_error_pre(
			": expression level exceeded (error token is \"",
			error_token->var, """\")");
	else if (error_token != NULL &&
	error_token->type == CALC_NUM_OVERFLOW_ERROR)
		in->lp_error = ft_42sh_calc_error_pre(
			": number is too big (error token is \"",
			error_token->var, """\")");
	if (l != NULL)
		free_calc_tokens(l->first_token);
	if (l != NULL)
	{
		free(l->stackos);
		free(l->stackzn);
		free(l);
	}
	return (0);
}

int				is_znak_type(t_calc_tkntype type)
{
	return ((type > CALC_NUMBER && type <= CALC_SEC_SC) && type != CALC_VAR &&
			type != CALC_INC && type != CALC_DEC &&
			type != CALC_PRE_INC && type != CALC_PRE_DEC);
}

t_calc_token	*get_last_token(t_calc_token *tmp)
{
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}
