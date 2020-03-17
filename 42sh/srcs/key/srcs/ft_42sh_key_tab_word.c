/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key_tab_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_key.h"

void				*ft_42sh_key_tab_word_end(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		litter;

	while ((litter = ft_42sh_parsing_litter_e_f(b, e)) != 0 && litter > 0x20)
	{
		b++;
		if (litter == '\\' && b < e)
			b += b + 1 < e && b[1] == '\n' ? 2 : 1;
		else if (litter == '<' || litter == '>')
			b = ft_42sh_key_tab_pipe(b, e, litter);
		else if ((litter == '"' || litter == '\''))
			b += ft_42sh_key_tab_dq(b, e, litter);
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
			if (litter == '<' || litter == '>')
				start = ft_42sh_key_tab_pipe(start, current, litter);
			else if (ft_42sh_parsing_litter_e_f(start++, current) == 0)
				tmp = ft_42sh_parsing_litter_e_f_l(start - 1, current);
			else if (litter == '\\' && start < current)
				start++;
			else if ((litter == '"' || litter == '\''))
				start += ft_42sh_key_tab_dq(start, end, litter);
		}
	}
	return (tmp);
}

void				*ft_42sh_key_tab_cmd_end(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		litter;

	while ((litter = ft_42sh_parsing_litter_e_f(b++, e)) != 0)
	{
		if (litter == '\\' && b < e)
			b++;
		else if (litter == '<' || litter == '>')
			b = ft_42sh_key_tab_pipe(b, e, litter);
		else if ((litter == '"' || litter == '\''))
			b += ft_42sh_key_tab_dq(b, e, litter);
	}
	return (b - 1);
}

void				*ft_42sh_key_tab_cmd_start(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		litter;
	register unsigned char		*tmp;

	tmp = b;
	while (b < e)
	{
		if ((litter = ft_42sh_parsing_litter_e_f(b++, e)) == 0)
			tmp = ft_42sh_parsing_litter_e_f_l(b - 1, e);
		else if (litter == '<' || litter == '>')
			b = ft_42sh_key_tab_pipe(b, e, litter);
		else if (litter == '\\' && b < e)
			b++;
		else if ((litter == '"' || litter == '\''))
			b += ft_42sh_key_tab_dq(b, e, litter);
	}
	return (tmp);
}
