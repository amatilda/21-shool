/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_slesh2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_replase.h"

size_t			ft_42sh_replase_slesh_count(unsigned char **out,
register unsigned char *e)
{
	register unsigned char			*b;
	register size_t					count;

	b = *out;
	if (b + 1 < e && b[1] == '\n')
	{
		b += 2;
		count = 0;
	}
	else
	{
		b++;
		count = 1;
	}
	*out = b;
	return (count);
}

void			*ft_42sh_replase_slesh(register unsigned char *dest,
unsigned char **src, register unsigned char *e)
{
	register unsigned char			*b;

	b = *src;
	if (b + 1 < e && b[1] == '\n')
		b += 2;
	else
		dest++[0] = b++[0];
	*src = b;
	return (dest);
}

size_t			ft_42sh_replase_slesh_exp_count(unsigned char **out,
register unsigned char *e)
{
	register unsigned char			*b;

	b = *out;
	if (b + 1 < e && b[1] == '\n')
		b += 2;
	else
		b++;
	*out = b;
	return (2);
}

void			*ft_42sh_replase_slesh_exp(register unsigned char *dest,
unsigned char **src, register unsigned char *e)
{
	register unsigned char			*b;

	b = *src;
	if (b + 1 < e && b[1] == '\n')
		b++;
	dest++[0] = '\\';
	dest++[0] = b++[0];
	*src = b;
	return (dest);
}
