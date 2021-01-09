/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zam_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:44:37 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

void		zam_var_help(t_cacl_in *in, int res, int dop,
t_calc_token *var_token)
{
	char	*str_to_del;

	res += dop;
	str_to_del = var_token->var;
	var_token->var = ft_itoa_add(res);
	if (var_token->next && var_token->next->type == CALC_INC)
		res++;
	if (var_token->next && var_token->next->type == CALC_DEC)
		res--;
	if ((in->b_test & CALC_MODE_ENV_SET) != 0 && ((var_token->prev &&
	(var_token->prev->type == CALC_PRE_DEC ||
	var_token->prev->type == CALC_PRE_INC)) ||
	(var_token->next && (var_token->next->type == CALC_INC
	|| var_token->next->type == CALC_DEC))))
		ft_42sh_calc_set_env(in->array, str_to_del, (size_t)res);
	ft_strdel(&str_to_del);
}

void		zam_var(t_cacl_in *in, t_calc_token *var_token, int *error)
{
	char	*env_var;
	int		dop;
	int		res;

	dop = 0;
	res = 0;
	if (var_token->prev && var_token->prev->type == CALC_PRE_DEC)
		dop--;
	if (var_token->prev && var_token->prev->type == CALC_PRE_INC)
		dop++;
	if ((in->b_test & CALC_MODE_ENV_GET) != 0)
	{
		if ((env_var = ft_42sh_calc_get_env(in->array, var_token->var)) != 0)
		{
			res = eval_expr(in, env_var, error, var_token->var);
			ft_strdel(&env_var);
			if (*error != 0)
				return ;
		}
	}
	zam_var_help(in, res, dop, var_token);
}
