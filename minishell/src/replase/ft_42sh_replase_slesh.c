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

#include "ft_42sh.h"

size_t			ft_42sh_replase_slesh_count(unsigned char **out,
register unsigned char *e, register unsigned char dquote)
{
	register unsigned char			*b;
	register size_t					count;

	b = *out;
	count = 0;
	if (++b < e && b[0] == '\n')
		b++;
	else
		count = dquote == 0 ? 1 : 2;
	*out = b;
	return (count);
}

void			*ft_42sh_replase_slesh(register unsigned char *dest,
unsigned char **out, register unsigned char *e, register unsigned char dquote)
{
	register unsigned char			*b;

	b = *out;
	if (++b < e && b[0] == '\n')
		b++;
	else if (dquote == 0)
		dest++[0] = b[-1];
	else
	{
		dest++[0] = '\\';
		dest++[0] = b[-1];
	}
	*out = b;
	return (dest);
}
