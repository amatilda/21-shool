/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_calc_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 19:53:08 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

static void		*error_utf8(t_calc_token *token)
{
	t_calc_token	*tmp_token;

	while (token != 0)
	{
		tmp_token = token;
		token = token->next;
		if (tmp_token->var != 0)
			ft_strdel(&tmp_token->var);
		free(tmp_token);
	}
	return (ft_ntoken("error symbol", CALC_ERROR));
}

t_calc_token	*define_standart_token(char *str, int *i)
{
	int				size;
	char			*tmp;
	t_calc_token	*tmp_token;

	size = calc_word_size(str, 0);
	if (is_incr_sym(str[0]))
		size = 1;
	tmp = ft_strsub(str, 0, size);
	tmp_token = calc_define_token(tmp);
	if (tmp_token == NULL)
	{
		size = 1;
		ft_strdel(&tmp);
		tmp = ft_strsub(str, 0, size);
		tmp_token = calc_define_token(tmp);
	}
	if (tmp_token == NULL)
		tmp_token = ft_ntoken(tmp, CALC_ERROR);
	if (size <= 0)
		tmp_token = error_utf8(tmp_token);
	ft_strdel(&tmp);
	*i += size;
	return (tmp_token);
}

t_calc_token	*calc_define_token(char *str)
{
	if (!str)
		return (NULL);
	else if (!*str)
		return (ft_ntoken(NULL, CALC_END));
	else if (ft_strncmp(str, "&&", 2) == 0)
		return (ft_ntoken(str, CALC_AND));
	else if (ft_strncmp(str, "||", 2) == 0)
		return (ft_ntoken(str, CALC_OR));
	else if (!ft_strncmp(str, "==", 2))
		return (ft_ntoken(str, CALC_EQ));
	else if (!ft_strncmp(str, "!=", 2))
		return (ft_ntoken(str, CALC_DIFF));
	else if (!ft_strncmp(str, "<=", 2))
		return (ft_ntoken(str, CALC_LESSOREQ));
	else if (!ft_strncmp(str, ">=", 2))
		return (ft_ntoken(str, CALC_MOREOREQ));
	else if (*str == '<')
		return (ft_ntoken(str, CALC_LESS));
	else if (*str == '>')
		return (ft_ntoken(str, CALC_MORE));
	else if (!ft_strncmp(str, "++", 2))
		return (ft_ntoken(str, CALC_INC));
	else
		return (calc_define_token_next(str));
}

static int		fn_test_var(char *str)
{
	if (str[0] == '$')
		return ((str[1]));
	else
		return (ft_isalpha(str[0]));
}

t_calc_token	*calc_define_token_next(char *str)
{
	if (!ft_strncmp(str, "--", 2))
		return (ft_ntoken(str, CALC_DEC));
	else if (*str == '+')
		return (ft_ntoken(str, CALC_PLUS));
	else if (*str == '-')
		return (ft_ntoken(str, CALC_MINUS));
	else if (!ft_strcmp(str, "*"))
		return (ft_ntoken(str, CALC_MUL));
	else if (!ft_strcmp(str, "/"))
		return (ft_ntoken(str, CALC_DIV));
	else if (!ft_strcmp(str, "%"))
		return (ft_ntoken(str, CALC_MOD));
	else if (*str == '(')
		return (ft_ntoken(str, CALC_FIR_SC));
	else if (*str == ')')
		return (ft_ntoken(str, CALC_SEC_SC));
	else if (ft_isdigit(*str))
		return (ft_ntoken(str, CALC_NUMBER));
	else if (fn_test_var(str))
		return (ft_ntoken(str, CALC_VAR));
	else
		return (NULL);
}
