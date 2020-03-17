/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_path_canon.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static unsigned char	*fn_back(register unsigned char *current)
{
	current -= 2;
	while (current[0] != '/')
		current--;
	current++;
	return (current);
}

static unsigned char	*fn_while(register unsigned char *str,
register unsigned char *end, register unsigned char *out,
register unsigned char *current)
{
	register unsigned char			litter;

	while (str < end)
	{
		if ((litter = str[0]) == '.')
		{
			if ((litter = str[1]) == '/' || litter == 0)
			{
				str += 2;
				continue ;
			}
			else if (litter == '.' && ((litter = str[2]) == '/' || litter == 0))
			{
				str += 3;
				if (out + 1 != current)
					current = fn_back(current);
				continue ;
			}
		}
		while (str < end && (litter = str++[0]) != '/')
			current++[0] = litter;
		if (current[-1] != '/')
			current++[0] = '/';
	}
	return (current);
}

static void				fn_finish(register t_string *ret,
register unsigned char *current, register unsigned char *out)
{
	if (out + 1 != current)
		current--;
	current[0] = 0;
	ret->buff = (void *)out;
	ret->len = current - out;
}

void					ft_42sh_path_canon(register t_string *ret,
register unsigned char *str, register size_t n)
{
	register unsigned char			*out;
	register unsigned char			*current;

	ret->max_len = n + 1;
	if ((out = ft_malloc(n + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	if (str[0] == '/')
	{
		str++;
		n--;
		out[0] = '/';
		current = out + 1;
	}
	else
		current = out;
	current = fn_while(str, str + n, out, current);
	fn_finish(ret, current, out);
}
