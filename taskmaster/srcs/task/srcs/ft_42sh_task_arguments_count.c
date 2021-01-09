/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_arguments_count.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void			*fn_slesh(register unsigned char *dest,
register unsigned char **out, register unsigned char *e)
{
	register unsigned char				*b;

	if ((b = *out) < e)
	{
		dest++[0] = b[0];
		*out = b + 1;
	}
	return (dest);
}

static void			*fn_space(register unsigned char *dest,
register unsigned char **out, register unsigned char *e, size_t *count)
{
	register unsigned char				*b;

	b = *out;
	dest++[0] = 0;
	while (b < e && b[0] == 0x20)
		b++;
	*out = b;
	*count = *count + 1;
	return (dest);
}

static void			*fn_quote(register unsigned char *dest,
register unsigned char **out, register unsigned char *e)
{
	register unsigned char				*b;
	register unsigned char				*save;
	register unsigned char				litter;

	b = *out;
	save = dest;
	litter = 0;
	while (b < e && (litter = b[0]) != '\'')
	{
		dest++[0] = litter;
		b++;
	}
	if (litter != '\'')
	{
		save++[0] = '\'';
		return (save);
	}
	*out = b;
	return (dest);
}

static void			*fn_dquote(register unsigned char *dest,
register unsigned char **out, register unsigned char *e)
{
	register unsigned char				*b;
	register unsigned char				*save;
	register unsigned char				litter;

	b = *out;
	save = dest;
	litter = 0;
	while (b < e && (litter = b[0]) != '"')
	{
		if (litter == '\\' && b + 1 < e)
			litter = (++b)[0];
		dest++[0] = litter;
		b++;
	}
	if (litter != '"')
	{
		save++[0] = '"';
		return (save);
	}
	*out = b;
	return (dest);
}

size_t				ft_42sh_task_arguments_count(register unsigned char *dest,
unsigned char *b, unsigned char **end)
{
	register unsigned char				*e;
	size_t								count;
	register unsigned char				litter;

	e = *end;
	count = 1;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\')
			dest = fn_slesh(dest, &b, e);
		else if (litter == '\'')
			dest = fn_quote(dest, &b, e);
		else if (litter == '"')
			dest = fn_dquote(dest, &b, e);
		else if (litter == 0x20)
			dest = fn_space(dest, &b, e, &count);
		else
			dest++[0] = litter;
	}
	*end = dest;
	return (count);
}
