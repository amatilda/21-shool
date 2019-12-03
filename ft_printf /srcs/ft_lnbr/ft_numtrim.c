/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:49:53 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/09 17:45:19 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

static int	ft_iszero(register t_lnbr nbr)
{
	size_t	i;

	i = -1;
	while (++i < nbr.len - 1)
		if (nbr.num[i] != '0')
			return (0);
	return (1);
}

t_lnbr		ft_numtrim(t_lnbr nbr)
{
	size_t			i;
	size_t			j;
	register t_lnbr	res;

	res = ft_numzero(1);
	if (ft_iszero(nbr))
		return (res);
	i = 0;
	j = -1;
	while (nbr.num[i] == '0' && i < nbr.len - 1 && nbr.num[i + 1] != '.')
		i++;
	while (nbr.num[i + ++j])
		res.num[j] = nbr.num[i + j];
	res.num[j] = '\0';
	res.len = j;
	return (res);
}
