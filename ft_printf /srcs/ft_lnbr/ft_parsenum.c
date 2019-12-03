/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsenum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:41:48 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/10 15:58:59 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static t_lnbr	ft_addzero_b(register t_lnbr nbr)
{
	size_t			j;
	register t_lnbr	res;

	j = -1;
	res = ft_numzero(nbr.len + 1);
	while (++j < nbr.len)
		res.num[j] = nbr.num[j];
	res.num[j] = '0';
	return (res);
}

static t_lnbr	ft_addzero_f(register t_lnbr nbr, size_t i)
{
	size_t			j;
	register t_lnbr	res;

	j = -1;
	res = ft_numzero(nbr.len + i);
	while (++j < nbr.len)
		res.num[j + i] = nbr.num[j];
	return (res);
}

t_lnbr			ft_parse_sing(register t_lnbr nbr)
{
	size_t			i;
	register t_lnbr	res;
	register t_lnbr	base;

	i = 0;
	res = ft_numzero(1);
	base = ft_numzero(1);
	base.num[0] = '2';
	i = nbr.len;
	while (i--)
		if (nbr.num[i] != '0')
			res = ft_long_sum(res, ft_long_pow(base, nbr.len - i - 1));
	return (res);
}

t_lnbr			ft_parse_fract(register t_lnbr nbr)
{
	size_t			i;
	register t_lnbr	res;
	register t_lnbr	base;

	i = 0;
	res = ft_numzero(1);
	base = ft_numzero(1);
	base.num[0] = '5';
	while (i < nbr.len)
	{
		res = ft_addzero_b(res);
		if (nbr.num[i++] != '0')
			res = ft_long_sum(ft_long_pow(base, i), res);
	}
	if (res.len < i)
		res = ft_addzero_f(res, i - res.len);
	return (res);
}
