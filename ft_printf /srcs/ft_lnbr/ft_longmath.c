/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longmath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:17:32 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/09 16:17:35 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

t_lnbr	ft_long_sum(register t_lnbr nbr1, register t_lnbr nbr2)
{
	unsigned char	temp;
	register t_lnbr	res;

	if (nbr1.len < nbr2.len)
		return (ft_long_sum(nbr2, nbr1));
	temp = 0;
	res.len = nbr1.len + 1;
	res.num[res.len] = '\0';
	while (nbr2.len-- && nbr1.len-- && res.len--)
	{
		temp += nbr1.num[nbr1.len] - '0' + nbr2.num[nbr2.len] - '0';
		res.num[res.len] = temp % 10 + '0';
		temp /= 10;
	}
	while (nbr1.len-- && res.len--)
	{
		temp += nbr1.num[nbr1.len] - '0';
		res.num[res.len] = temp % 10 + '0';
		temp /= 10;
	}
	res.num[0] = temp % 10 + '0';
	res.len = nbr1.len + 1;
	return (ft_numtrim(res));
}

t_lnbr	ft_long_mul(register t_lnbr nbr1, register t_lnbr nbr2)
{
	size_t			i1;
	size_t			i2;
	unsigned char	temp;
	register t_lnbr	res;

	i1 = -1;
	i2 = -1;
	temp = 0;
	res = ft_numzero(nbr1.len + nbr2.len);
	while (++i2 < nbr2.len)
	{
		while (++i1 < nbr1.len)
		{
			temp += (nbr1.num[nbr1.len - i1 - 1] - '0')
				* (nbr2.num[nbr2.len - i2 - 1] - '0');
			temp += res.num[(nbr1.len + nbr2.len) - (i1 + i2) - 1] - '0';
			res.num[(nbr1.len + nbr2.len) - (i1 + i2) - 1] = temp % 10 + '0';
			temp /= 10;
		}
		res.num[(nbr1.len + nbr2.len) - (i1 + i2) - 1] = temp % 10 + '0';
		temp = 0;
		i1 = -1;
	}
	res.len = nbr1.len + nbr2.len + 1;
	return (ft_numtrim(res));
}

t_lnbr	ft_long_pow(register t_lnbr base, size_t pow)
{
	register t_lnbr	res;

	res = ft_numzero(1);
	res.num[0] = '1';
	while (pow--)
		res = ft_long_mul(base, res);
	return (res);
}
