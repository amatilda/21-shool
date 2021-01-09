/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 17:21:36 by pro               #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

static int	ispar(char c)
{
	return (c == 34 || c == 39);
}

int			issc(char c)
{
	if (c == '(' || c == ')')
		return (1);
	else
		return (0);
}

static int	isoperator(char c)
{
	return (c == '<' || c == '&' || c == '|' || c == '>' || c == ';');
}

static int	isword(char c)
{
	if (ispar(c) == 1)
		return (2);
	if (issc(c))
		return (3);
	if (c == '$')
		return (4);
	if (!isoperator(c) && c != ' ' && c != '\t' && c != '\0')
		return (1);
	return (0);
}

char		*ft_get_next_word(char *str, int i)
{
	char	*newstr;
	int		d;

	d = 0;
	if (!str)
		return (NULL);
	i++;
	while (str[i] != '\0' && isword(str[i]) == 1)
		i++;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] != '\0' && (isword(str[i]) == 1))
	{
		i++;
		d++;
	}
	newstr = ft_strsub(str, i - d, d);
	return (newstr);
}
