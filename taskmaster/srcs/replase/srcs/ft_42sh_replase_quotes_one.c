/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_quotes_one.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_replase.h"

size_t					ft_42sh_replase_quotes_one_count(register
t_replase_in_42sh *in, register unsigned char **out)
{
	unsigned char				*b;
	register unsigned char		lit;
	register size_t				count;

	b = *out;
	count = 0;
	while ((lit = b++[0]) != '\'')
	{
		if (lit == '\n')
			count += (in->b_mode & PARSING_MODE_CMD_42SH) != 0 ? 1 : 0;
		else
			count++;
	}
	*out = b;
	return (count);
}

unsigned char			*ft_42sh_replase_quotes_one(register
t_replase_in_42sh *in, register unsigned char *dest, unsigned char **src)
{
	unsigned char				*b;
	register unsigned char		lit;

	b = *src;
	while ((lit = b++[0]) != '\'')
	{
		if (lit == '\n')
		{
			if ((in->b_mode & PARSING_MODE_CMD_42SH) != 0)
				dest = ft_memcpy(dest - 1, "\\n", 2) + 2;
			else
				dest[-1] = '\n';
		}
		else
			dest++[0] = lit;
	}
	*src = b;
	return (dest);
}
