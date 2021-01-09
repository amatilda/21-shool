/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_cmd_env_close_while_exp_count.c       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_auto.h"

static void		*fn_slesh(unsigned char *b, size_t *n)
{
	*n = *n + 2;
	b += 2;
	return (b);
}

static size_t	fn_finish(register unsigned char litter,
register size_t count, unsigned char **out, unsigned char *b)
{
	if (litter != '}')
	{
		*out = b;
		count++;
	}
	else
		*out = b + 1;
	return (count);
}

static size_t	fn_pre(unsigned char **b, unsigned char **out,
size_t *n)
{
	*b = *out + 2;
	*n = *n + 2;
	return (0);
}

size_t			ft_42sh_auto_cmd_env_close_while_exp_count(register
unsigned char **out, register unsigned char *e, size_t *n)
{
	register unsigned char			litter;
	unsigned char					*b;
	register size_t					count;

	count = fn_pre(&b, out, n);
	litter = 0;
	while (b < e && (litter = b[0]) != '}')
	{
		if (litter == '\\')
			b = fn_slesh(b, n);
		else if (litter == '$' && b + 1 < e && b[1] == '{')
			count += ft_42sh_auto_cmd_env_close_while_exp_count(&b, e, n);
		else if (litter == '\'')
			count += ft_42sh_auto_cmd_env_close_dq_count(&b, e, n);
		else if (litter == '"')
			count += ft_42sh_auto_cmd_env_close_dq_two_count(&b, e, n);
		else
		{
			b++;
			*n = *n + 1;
		}
	}
	*n = *n + 1;
	return (fn_finish(litter, count, out, b));
}

size_t			ft_42sh_auto_cmd_env_close_while_count(register
unsigned char **out, register unsigned char *e, size_t *n)
{
	register unsigned char			litter;
	unsigned char					*b;
	register size_t					count;

	count = 0;
	b = *out;
	while (b < e)
	{
		if ((litter = b[0]) == '\\')
			b = fn_slesh(b, n);
		else if (litter == '$' && b + 1 < e && b[1] == '{')
			count += ft_42sh_auto_cmd_env_close_while_exp_count(&b, e, n);
		else if (litter == '"')
			count += ft_42sh_auto_cmd_env_close_dq_two_count(&b, e, n);
		else
		{
			b++;
			*n = *n + 1;
		}
	}
	*out = b;
	return (count);
}
