/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static char			*fn_back(register char *current)
{
	current -= 2;
	while (current[0] != '/')
		current--;
	current++;
	return (current);
}

static char			*fn_while(register char *str, register char *end,
register char *out,
register char *current)
{
	register char			litter;

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

static void			fn_finish(register t_string *ret,
register char *current, register char *out)
{
	if (out + 1 != current)
		current--;
	current[0] = 0;
	ret->buff = out;
	ret->len = current - out;
}

void				ft_42sh_parsing_path(register t_string *ret,
register t_string *root, register char *str, register size_t n)
{
	register char			*out;
	register size_t			len;
	register char			*current;

	len = root->len;
	ret->max_len = n + len + 2;
	if ((out = ft_malloc(ret->max_len)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	if (str[0] == '/')
	{
		str++;
		n--;
		out[0] = '/';
		current = out + 1;
	}
	else
	{
		ft_memcpy(out, root->buff, len);
		current = out + len;
		if (len > 1)
			current++[0] = '/';
	}
	current = fn_while(str, str + n, out, current);
	fn_finish(ret, current, out);
}

size_t				ft_42sh_parsing_path_test(register char *b,
register char *e)
{
	register size_t			tempos;

	tempos = 0;
	while (b < e && (tempos = b[0]) != '/')
		b++;
	if (tempos == '/')
		return (1);
	return (0);
}
