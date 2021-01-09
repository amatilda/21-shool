/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 19:53:08 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int			is_incr_sym(char c)
{
	return (c == '+' || c == '-');
}

int			var_size(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isalpha(str[i]))
			return (i);
		i++;
	}
	return (i);
}

int			num_size(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (i);
		i++;
	}
	return (i);
}

int			znak_size(char *str)
{
	int		i;

	i = 0;
	if (issc(str[i]))
	{
		i++;
		return (i);
	}
	while (str[i] && (is_znak(str[i]) && !issc(str[i])) && i < 2)
	{
		i++;
	}
	return (i);
}

int			calc_word_size(char *str, int type)
{
	int		i;

	i = 0;
	if (ft_isalpha(*str))
		return (var_size(str));
	if (ft_isdigit(*str))
		return (num_size(str));
	if (is_znak(*str))
		return (znak_size(str));
	if (str[0] == '$' && ft_isalpha(str[1]))
		return (var_size(str + 1) + 1);
	if ((*str > 31 && *str < 127))
		return (1);
	return (i);
	(void)type;
}
