/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:30:09 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/05 13:30:11 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	int		count;

	if (s == 0)
		return ;
	count = 0;
	while (s[count] != 0)
		count++;
	if (count == 0)
		return ;
	write(1, s, count);
}
