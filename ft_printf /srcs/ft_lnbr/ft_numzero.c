/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:17:14 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/09 16:27:55 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

t_lnbr	ft_numzero(size_t len)
{
	size_t			i;
	register t_lnbr	res;

	i = -1;
	res.len = len;
	while (++i < len)
		res.num[i] = '0';
	res.num[i] = '\0';
	return (res);
}
