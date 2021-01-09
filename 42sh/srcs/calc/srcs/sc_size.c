/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:47:39 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

static char		find_pair_sc(char c)
{
	if (c == '(')
		return (')');
	if (c == '{')
		return ('}');
	return (0);
}

int				sc_size(char *str, char b)
{
	int		i;
	int		cn;
	char	dop;

	i = 0;
	dop = b;
	cn = 1;
	b = find_pair_sc(b);
	if (*str == b)
		return (-2);
	while (*str != '\0' && cn != 0)
	{
		i++;
		str++;
		if (*str == dop)
			cn++;
		if (*str == b)
			cn--;
	}
	if (*str == '\0' && cn != 0)
		return (-1);
	return (i + 2);
}
