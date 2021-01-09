/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_cmd_env_close_while_exp.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_auto.h"

static void		*fn_finish(register unsigned char *dest,
unsigned char **out, unsigned char *b, register unsigned char litter)
{
	dest++[0] = '}';
	if (litter == '}')
		*out = b + 1;
	else
		*out = b;
	return (dest);
}

static void		*fn_set(register
unsigned char *dest, unsigned char **b, register unsigned char litter)
{
	dest++[0] = litter;
	dest++[0] = (*b)[0];
	*b = *b + 2;
	return (dest);
}

void			*ft_42sh_auto_cmd_env_close_while_exp(register
unsigned char *dest, unsigned char **out, register unsigned char *e)
{
	register unsigned char			litter;
	unsigned char					*b;

	b = *out + 2;
	dest++[0] = '$';
	dest++[0] = '{';
	litter = 0;
	while (b < e && (litter = b[0]) != '}')
	{
		if (litter == '\\')
			fn_set(dest, &b, litter);
		else if (litter == '$' && b + 1 < e && b[1] == '{')
			dest = ft_42sh_auto_cmd_env_close_while_exp(dest, &b, e);
		else if (litter == '\'')
			dest = ft_42sh_auto_cmd_env_close_dq(dest, &b, e);
		else if (litter == '"')
			dest = ft_42sh_auto_cmd_env_close_dq_two(dest, &b, e);
		else
		{
			dest++[0] = litter;
			b++;
		}
	}
	return (fn_finish(dest, out, b, litter));
}

void			*ft_42sh_auto_cmd_env_close_while(register
unsigned char *dest, unsigned char **out, register unsigned char *e)
{
	register unsigned char			litter;
	unsigned char					*b;

	b = *out;
	while (b < e)
	{
		if ((litter = b[0]) == '\\')
		{
			dest++[0] = litter;
			dest++[0] = b[0];
			b += 2;
		}
		else if (litter == '$' && b + 1 < e && b[1] == '{')
			dest = ft_42sh_auto_cmd_env_close_while_exp(dest, &b, e);
		else if (litter == '"')
			dest = ft_42sh_auto_cmd_env_close_dq_two(dest, &b, e);
		else
		{
			dest++[0] = litter;
			b++;
		}
	}
	*out = b;
	return (dest);
}
