/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_cmd_env_close_dq_count.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_auto.h"

size_t			ft_42sh_auto_cmd_env_close_dq_count(register
unsigned char **out, register unsigned char *e, size_t *n)
{
	register unsigned char			*b;

	b = *out + 1;
	while (b < e)
	{
		if ('\'' == b[0])
		{
			b++;
			*n = *n + (b - *out);
			*out = b;
			return (0);
		}
		else
			b++;
	}
	*out = *out + 1;
	return (1);
}

size_t			ft_42sh_auto_cmd_env_close_dq_two_count(register
unsigned char **out, register unsigned char *e, size_t *n)
{
	register unsigned char			*end;
	unsigned char					*save;
	register unsigned char			litter;
	register unsigned char			*b;

	b = *out + 1;
	save = b;
	end = 0;
	while (b < e)
	{
		if ((litter = b[0]) == '\\')
			b += 2;
		else if (litter == '"')
		{
			*out = b + 1;
			*n = *n + 2;
			return (ft_42sh_auto_cmd_env_close_while_count(&save, b, n));
		}
		else
			b++;
	}
	*out = save;
	return (1);
}