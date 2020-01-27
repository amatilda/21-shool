/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 19:16:51 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/10 16:44:00 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

int		ft_atoi(const char *str)
{
	register int		tmp;
	register uintmax_t	out;
	register size_t		i;

	out = 0;
	tmp = 1;
	while (str[0] == ' ' || str[0] == '\n' || str[0] == '\t' ||
			str[0] == '\v' || str[0] == '\f' || str[0] == '\r')
		str++;
	if (str[0] == '-')
	{
		tmp = -1;
		str++;
	}
	else if (str[0] == '+')
		str++;
	i = 0;
	while (str[i] >= 0x30 && str[i] <= 0x39)
		out = out * 10 + str[i++] - 0x30;
	if (i <= 19)
		return ((int)(out * tmp));
	if (out - 9223372036854775807 >= 1)
		return ((tmp == -1) ? 0 : -1);
	return (tmp > 0 ? -1 : 0);
}
