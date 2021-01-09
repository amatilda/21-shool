/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 19:53:08 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

t_int	*tmp_0(t_int *tmp, char *s)
{
	tmp->ol = 0;
	tmp->zl = 0;
	tmp->i = 0;
	tmp->d = 0;
	tmp->s = s;
	return (tmp);
}

int		c_e(t_calc calce)
{
	if (calce.stackos != NULL)
		free(calce.stackos);
	if (calce.stackzn != NULL)
		free(calce.stackzn);
	if (calce.str != NULL)
		free(calce.str);
	ft_strdel(&calce.delstr);
	*calce.error = 1;
	return (-1);
}
