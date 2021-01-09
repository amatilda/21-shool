/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_cmd_env_close_dq.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_auto.h"

void		*ft_42sh_auto_cmd_env_close_dq(register unsigned char *dest,
unsigned char **out, register unsigned char *e)
{
	register unsigned char			*b;
	register unsigned char			*tmp;
	register size_t					count;

	b = *out + 1;
	while (b < e)
	{
		if ('\'' == b[0])
		{
			b++;
			tmp = *out;
			count = b - tmp;
			ft_memcpy(dest, tmp, count);
			*out = b;
			return (dest + count);
		}
		else
			b++;
	}
	*out = *out + 1;
	return (dest);
}

void		*ft_42sh_auto_cmd_env_close_dq_two(register
unsigned char *dest, unsigned char **out, register unsigned char *e)
{
	unsigned char					*save;
	register unsigned char			litter;
	register unsigned char			*b;

	b = *out + 1;
	save = b;
	while (b < e)
	{
		if ((litter = b++[0]) == '\\')
			b += 2;
		else if (litter == '"')
		{
			*out = b + 1;
			dest++[0] = '"';
			dest = ft_42sh_auto_cmd_env_close_while(dest, &save, b);
			dest++[0] = '"';
			return (dest);
		}
	}
	*out = save;
	return (dest);
}
