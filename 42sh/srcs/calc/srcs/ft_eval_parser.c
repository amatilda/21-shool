/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 19:53:08 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

t_calc_token		*ft_make_token_from_str(char *str, int *i,
		t_calc_token *prev_token)
{
	t_calc_token	*tmp_token;

	if ((tmp_token = check_and_define_pre_incr(str, i, prev_token)))
		return (tmp_token);
	else if ((tmp_token = check_calc_incr_after(str, i, prev_token)))
		return (tmp_token);
	else if ((tmp_token = check_calc_error(str, i, prev_token)))
		return (tmp_token);
	else if ((tmp_token = check_if_incr_with_num(str, i, prev_token)))
		return (tmp_token);
	else
	{
		return (define_standart_token(str, i));
	}
}

void				*decide_how_to_parse(t_calc_token *tmp_token,
		t_calc_token *first_token, char *rec_var)
{
	if (tmp_token)
	{
		add_token_cr(first_token, tmp_token);
	}
	if (tmp_token && tmp_token->type == CALC_ERROR)
	{
		return (first_token);
	}
	if (tmp_token && tmp_token->type == CALC_NUMBER &&
	ft_strlen(tmp_token->var) > 19)
	{
		add_token_cr(first_token,
				ft_ntoken(tmp_token->var, CALC_NUM_OVERFLOW_ERROR));
		return (first_token);
	}
	if (tmp_token && rec_var && !ft_strcmp(tmp_token->var, rec_var))
	{
		add_token_cr(first_token, ft_ntoken(tmp_token->var, CALC_REC_ERROR));
		return (first_token);
	}
	return (NULL);
}

t_calc_token		*ft_eval_parse(char *str, char *rec_var)
{
	int				i;
	t_calc_token	*f_token;
	t_calc_token	*tmp_token;

	i = 0;
	tmp_token = NULL;
	if (!(f_token = ft_ntoken(NULL, CALC_START)))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			tmp_token = ft_make_token_from_str(&str[i], &i, tmp_token);
			if (decide_how_to_parse(tmp_token, f_token, rec_var) != NULL)
				return (f_token);
		}
		else
			i++;
	}
	return (f_token);
}
