/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_tab_eq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_key.h"

size_t				ft_42sh_key_tab_dq(register unsigned char *b,
register unsigned char *e, register unsigned char litter)
{
	register unsigned char		*start;

	start = b;
	while (b < e)
		if (litter == b++[0])
			return (b - start);
	return (0);
}

void				*ft_42sh_key_tab_pipe(register unsigned char *b,
register unsigned char *e, register unsigned char litter)
{
	while (b < e && b[0] == litter)
		b++;
	while (b < e && b[0] == '&')
		b++;
	return (b);
}

void				*ft_42sh_key_tab_eq(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		*tmp;
	register unsigned char		litter;

	litter = 0;
	tmp = b;
	while (b < e && (litter = b[0]) != '$' && litter != '/' &&
	litter != '=' && litter != '<' && litter != '>')
	{
		b++;
		if (litter == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if ((litter == '"' || litter == '\''))
			b += ft_42sh_key_tab_dq(b, e, litter);
	}
	if (litter == '=')
		return (b + 1);
	if (litter == '<' || litter == '>')
		return (ft_42sh_key_tab_pipe(b, e, litter));
	return (tmp);
}