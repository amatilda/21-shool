/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_str_shield.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_str.h"

static void		*fn_n(register unsigned char *dest,
register uint_fast8_t b_test)
{
	if ((b_test & SHIELD_EXTERNALLY) != 0)
	{
		dest[0] = '$';
		dest[1] = '\'';
		dest[2] = '\\';
		dest[3] = 'n';
		dest[4] = '\'';
		dest += 5;
	}
	else
	{
		dest[-2] = '$';
		dest[-1] = '\'';
		dest[0] = '\\';
		dest[1] = 'n';
		dest[2] = '\'';
		dest += 3;
	}
	return (dest);
}

static void		fn_replase(register unsigned char *dest,
register unsigned char *b, register unsigned char *e,
register uint_fast8_t b_test)
{
	register size_t				count;
	register unsigned char		lit;

	count = 0;
	while (b < e)
	{
		if ((lit = b++[0]) == '\n')
			dest = fn_n(dest, b_test);
		else if (lit == '\'' || lit == '"' || lit == '$' || lit == '\\' ||
		lit == ' ' || lit == '[' || lit == ']' || lit == '*'  || lit == '?')
		{
			dest++[0] = '\\';
			dest++[0] = lit;
		}
		else 
			dest++[0] = lit;
	}
}

void			*ft_42sh_str_shield(register unsigned char *b,
register unsigned char *e, register uint_fast8_t b_test,
register t_shield_out_42sh *lp)
{
	register size_t				count;
	register unsigned char		*out;

	count = ft_42sh_str_shield_count(b, e, b_test, lp);
	if ((out = ft_malloc(count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	out[count] = 0;
	fn_replase(out, b, e, b_test);
	return (out);
}