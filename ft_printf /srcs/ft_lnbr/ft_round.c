/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:10:01 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/11 21:28:09 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

#include <stdio.h>

static t_lnbr	ft_pre_round(register t_lnbr sing, register t_lnbr fract,
							size_t prec)
{
	size_t			i;
	size_t			j;
	register t_lnbr res;

	i = -1;
	j = -1;
	res = ft_numzero(sing.len + prec + 1);
	while (++i < sing.len)
		res.num[i] = sing.num[i];
	while (++j <= prec)
		if (fract.num[j])
			res.num[i++] = fract.num[j];
		else
			res.num[i++] = '0';
	res.num[i] = '\0';
	return (res);
}

static t_lnbr	ft_return_zeros(register t_lnbr pre, register t_lnbr nbr)
{
	size_t			i;
	size_t			j;
	register t_lnbr	res;

	i = -1;
	j = -1;
	while (pre.num[++i] == '0')
		res.num[i] = '0';
	while (i + ++j < pre.len)
		res.num[i + j] = nbr.num[j];
	res.num[i + j] = '\0';
	res.len = i + j;
	return (res);
}

static t_lnbr	ft_add_dot(register t_lnbr nbr, size_t slen)
{
	size_t			i;
	register t_lnbr	res;

	i = -1;
	while (++i < slen)
		res.num[i] = nbr.num[i];
	res.num[i] = '.';
	while (++i < nbr.len)
		res.num[i] = nbr.num[i - 1];
	res.num[i] = '\0';
	res.len = nbr.len;
	return (res);
}

t_lnbr			ft_round(register t_lnbr sing, register t_lnbr fract,
						size_t prec)
{
	t_lnbr			add;
	register t_lnbr	pre;
	register t_lnbr	res;

	add = ft_numzero(2);
	add.num[0] = '1';
	pre = ft_pre_round(sing, fract, prec);
	if (pre.num[pre.len - 1] >= '5' && pre.num[pre.len - 1] <= '9')
		res = ft_long_sum(pre, add);
	else
		res = ft_numtrim(pre);
	res = ft_return_zeros(pre, res);
	if (prec - 1)
		res = ft_add_dot(res, sing.len);
	res.num[--res.len] = '\0';
	return (res);
}
