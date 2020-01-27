/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_tab_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_key.h"

static size_t		fn_test_dq(register unsigned char *b,
register unsigned char *e, register unsigned char litter)
{
	register unsigned char		*start;

	start = b;
	while (b < e)
		if (litter == b++[0])
			return (b - start);
	return (0);
}

void				*ft_42sh_key_tab_word_end(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		litter;

	while (b < e &&
	ft_42sh_parsing_litter_e_f((litter = b[0])) != 0 && (litter) > 0x20)
	{
		b++;
		if (litter == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if ((litter == '"' || litter == '\''))
			b += fn_test_dq(b, e, litter);
	}
	return (b);
}

void				*ft_42sh_key_tab_word_start(register unsigned char *start,
register unsigned char *current, register unsigned char *end)
{
	register unsigned char		litter;
	register unsigned char		*tmp;

	tmp = start;
	while (start < current)
	{
		start = ft_42sh_parsing_sp(start, current);
		tmp = start;
		while (start < current && (litter = start[0]) != 0x20)
		{
			start++;
			if (litter == '\\' && start < current)
				start++;
			else if ((litter == '"' || litter == '\''))
				start += fn_test_dq(start, end, litter);
			else if (ft_42sh_parsing_litter_e_f(litter) == 0)
				tmp = start;
		}
	}
	return (tmp);
}

void				*ft_42sh_key_tab_cmd_end(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		litter;

	while (b < e)
	{
		if ((litter = b++[0]) == '\\' && b < e)
			b++;
		else if ((litter == '"' || litter == '\''))
			b += fn_test_dq(b, e, litter);
		else if (ft_42sh_parsing_litter_e_f(litter) == 0)
			return (b - 1);
	}
	return (b);
}

void				*ft_42sh_key_tab_cmd_start(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		litter;
	register unsigned char		*tmp;

	tmp = b;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\' && b < e)
			b++;
		else if ((litter == '"' || litter == '\''))
			b += fn_test_dq(b, e, litter);
		else if (ft_42sh_parsing_litter_e_f(litter) == 0)
			tmp = b;
	}
	return (tmp);
}
