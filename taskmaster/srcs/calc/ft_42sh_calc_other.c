/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_calc_other.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_calc.h"

unsigned char	*ft_42sh_calc_end(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char	lit;

	while ((lit = b++[0]) != ')')
	{
		if (lit == '\\' || lit == '"' || lit == '\'')
			return (0);
		else if (lit == '(')
			b = ft_42sh_calc_end(b, e);
		else if (lit == '$' && b + 1 < e && b[0] == '(' && b[1] == '(')
			b = ft_42sh_calc_end(b + 1, e);
	}
	return (b);
}

void			*ft_42sh_calc_error_pre(register char *s1, register char *s2,
register char *s3)
{
	register size_t			n1;
	register size_t			n2;
	register size_t			n3;
	register void			*out;
	register char			*tmp;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	n3 = ft_strlen(s3);
	if ((tmp = ft_malloc(n1 + n2 + n3 + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	out = tmp;
	ft_memcpy(tmp, s1, n1);
	tmp = tmp + n1;
	ft_memcpy(tmp, s2, n2);
	tmp = tmp + n2;
	ft_memcpy(tmp, s3, n3);
	tmp[n3] = 0;
	return (out);
}