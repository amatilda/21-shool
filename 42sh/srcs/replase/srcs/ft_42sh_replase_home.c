/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_home.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_replase.h"

static void		*fn_test_end(register unsigned char *b,
register unsigned char *e)
{
	unsigned char				*end;
	register unsigned char		lit;

	end = b;
	lit = '~';
	while ((lit = ft_42sh_parsing_test_next(&end, e, 0, lit)) != 0)
	{
		if (lit == '"' || lit == '\'')
			return (0);
		if (lit == '/' || lit == ':')
		{
			end--;
			break ;
		}
	}
	return (end);
}

static size_t	fn_test_start(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char		lit;

	if (b == e)
		return (1);
	while (b < e && (lit = b++[0]) != '=')
		if (lit == '\\')
			b++;
	if (lit != '=')
		return (0);
	if (b == e)
		return (1);
	if (e[-1] != ':')
		return (0);
	if (e - b == 1 || e[-2] != '\\')
		return (1);
	e--;
	while (b < e)
		if ((lit = b++[0]) == '\\')
			b++;
	if (b == e)
		return (1);
	return (0);
}

size_t			ft_42sh_replase_home_test(register t_main_42sh *array,
register unsigned char *start, register unsigned char *b,
register unsigned char *e)
{
	if ((e = fn_test_end(b, e)) == 0)
		return (0);
	if (fn_test_start(start, b - 1) == 0)
		return (0);
	array->home.lp_home_tmp_b = b;
	array->home.lp_home_tmp_e = e;
	return (1);
}

size_t			ft_42sh_replase_home_count(register t_main_42sh *array,
register unsigned char **out)
{
	register t_logins_42sh				*list;
	register unsigned char				*b;
	register unsigned char				*e;

	b = array->home.lp_home_tmp_b;
	e = array->home.lp_home_tmp_e;
	if (b == e)
		return ((array->home.lp_home == 0) ? 0 : array->home.count_home);
	list = ft_42sh_list_find_key(&array->login, b, e - b);
	if ((array->home.list = list) == 0)
		return (1);
	*out = e;
	return (list->home_dir_count);
}

void			*ft_42sh_replase_home(register t_main_42sh *array,
register unsigned char *dest, register unsigned char **out)
{
	register t_logins_42sh				*list;
	register unsigned char				*b;
	register unsigned char				*e;
	register size_t						count;

	b = array->home.lp_home_tmp_b;
	e = array->home.lp_home_tmp_e;
	if (b == e)
	{
		if ((b = (void *)array->home.lp_home) == 0)
			return (dest);
		ft_memcpy(dest, b, (count = array->home.count_home));
		return (dest + count);
	}
	if ((list = array->home.list) == 0)
	{
		dest++[0] = '~';
		return (dest);
	}
	*out = e;
	ft_memcpy(dest, list->home_dir, (count = list->home_dir_count));
	return (dest + count);
}
