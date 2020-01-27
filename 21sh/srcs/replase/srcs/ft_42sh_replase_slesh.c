/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_slesh.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_replase.h"

static size_t	fn_set_count(unsigned char **out, register unsigned char *b,
register unsigned char *e, register size_t count)
{
	if (++b < e && b[0] == '\n')
		b++;
	else
		count = 1;
	*out = b;
	return (count);
}

size_t			ft_42sh_replase_slesh_count(unsigned char **out,
register unsigned char *e, register unsigned char dquote)
{
	register unsigned char			*b;
	register size_t					count;

	b = *out;
	count = 0;
	if (dquote == 0)
		return (fn_set_count(out, b, e, count));
	else if (dquote == '"')
	{
		if (b + 1 < e && b[1] == '\n')
			b += 2;
		else
		{
			count = 1;
			if (b[0] == '\\')
				b++;
		}
	}
	else
		count = 1;
	*out = b;
	return (count);
}

void			*ft_42sh_replase_slesh(register unsigned char *dest,
unsigned char **out, register unsigned char *e, register unsigned char dquote)
{
	register unsigned char			*b;

	b = *out;
	if (dquote == 0)
	{
		if (++b < e && b[0] == '\n')
			b++;
		else
			dest++[0] = b[-1];
	}
	else if (dquote == '"')
	{
		if (b + 1 < e && b[1] == '\n')
			b += 2;
		else
		{
			dest++[0] = '\\';
			if (b[0] == '\\')
				b++;
		}
	}
	else
		dest++[0] = '\\';
	*out = b;
	return (dest);
}
