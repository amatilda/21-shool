/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_def_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 19:53:08 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

t_calc_token		*ft_ntoken(char *line, t_calc_tkntype type)
{
	t_calc_token	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_calc_token))))
		return (NULL);
	if (line != NULL)
		tmp->var = ft_strdup(line);
	else
		tmp->var = NULL;
	tmp->type = type;
	tmp->next = NULL;
	return (tmp);
}

t_calc_token		*add_token_cr(t_calc_token *start,
		t_calc_token *token_to_add)
{
	t_calc_token	*tmp;

	tmp = start;
	while (tmp->next != NULL)
		tmp = tmp->next;
	start = tmp;
	tmp = token_to_add;
	start->next = tmp;
	tmp->prev = start;
	return (tmp);
}
