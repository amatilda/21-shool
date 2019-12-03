/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:26:16 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/05 13:26:18 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	intmax_t	value;
	int			count;
	char		buffer[sizeof(uintmax_t) * 4 + 1];

	value = n;
	count = ft_itoa_base(buffer, value, 10, ITOA_LOWER | ITOA_SIGNED);
	write(1, buffer, count);
}
