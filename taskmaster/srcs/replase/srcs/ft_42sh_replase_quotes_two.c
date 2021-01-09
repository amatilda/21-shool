/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_quotes_two.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_replase.h"

static size_t			fn_slesh_count(register unsigned char **out)
{
	register unsigned char		*b;
	register unsigned char		lit;
	register size_t				count;

	b = *out;
	count = 0;
	if ((lit = b++[0]) == '\\' || lit == '`' || lit == '$' || lit == '"')
		count++;
	else if (lit == ' ' && b[0] == '\n')
		b++;
	else
		count += 2;
	*out = b;
	return (count);
}

size_t					ft_42sh_replase_quotes_two_count(register
t_replase_in_42sh *in, register unsigned char **out,
register unsigned char *e)
{
	unsigned char				*b;
	unsigned char				*start;
	register unsigned char		lit;
	register size_t				count;

	b = *out;
	start = b;
	count = 0;
	while ((lit = b++[0]) != '"')
	{
		if (lit == '\\')
			count += fn_slesh_count(&b);
		else if (lit == '\n')
			count += (in->b_mode & PARSING_MODE_CMD_42SH) != 0 ? 1 : 0;
		else if (lit == '$' && (in->b_mode & PARSING_MODE_HRDC_42SH) == 0)
			count += ft_42sh_exp_parsing_count(in, &start, &b, e);
		else
			count++;
	}
	*out = b;
	return (count);
}

static unsigned char	*fn_slesh(register unsigned char *dest,
register unsigned char **src)
{
	register unsigned char		*b;
	register unsigned char		lit;

	b = *src;
	if ((lit = b++[0]) == '\\' || lit == '`' || lit == '$' || lit == '"')
		dest++[0] = lit;
	else if (lit == ' ' && b[0] == '\n')
		b++;
	else
	{
		dest++[0] = '\\';
		dest++[0] = lit;
	}
	*src = b;
	return (dest);
}

unsigned char			*ft_42sh_replase_quotes_two(register
t_replase_in_42sh *in, register unsigned char *dest, unsigned char **src,
register unsigned char *e)
{
	unsigned char				*b;
	register unsigned char		lit;

	b = *src;
	while ((lit = b++[0]) != '"')
	{
		if (lit == '\\')
			dest = fn_slesh(dest, &b);
		else if (lit == '\n')
		{
			if ((in->b_mode & PARSING_MODE_CMD_42SH) != 0)
				dest = ft_memcpy(dest - 1, "\\n", 2) + 2;
			else
				dest[-1] = '\n';
		}
		else if (lit == '$' && (in->b_mode & PARSING_MODE_HRDC_42SH) == 0)
			dest = ft_42sh_exp_parsing(in, dest, &b, e);
		else
			dest++[0] = lit;
	}
	*src = b;
	return (dest);
}