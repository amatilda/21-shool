/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 19:28:22 by qmartina          #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "eval_expr.h"

static int	ft_lennb(int n)
{
	int	nb;

	nb = 0;
	if (n == 0)
		nb = 1;
	if (n < 0)
		nb++;
	while (n != 0)
	{
		n /= 10;
		nb++;
	}
	return (nb - 1);
}

char		*ft_itoa_add(int n)
{
	char	*arr;
	int		i;
	size_t	nb;

	nb = ft_lennb(n);
	arr = ft_strnew(nb + 1);
	if (!arr)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(arr, "-2147483648"));
	i = n;
	if (i < 0)
	{
		i *= -1;
		arr[0] = '-';
	}
	arr[nb] = (i % 10) + '0';
	while (i /= 10)
	{
		nb--;
		arr[nb] = (i % 10) + '0';
	}
	return (arr);
}
