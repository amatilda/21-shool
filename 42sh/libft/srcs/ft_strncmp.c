/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:01:55 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/10 21:12:45 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(register void *s1, register void *s2, register size_t n)
{
	register size_t				i;
	register unsigned char		litter;

	if (n == 0)
		return (0);
	i = 0;
	n--;
	while ((litter = ((unsigned char *)s1)[i]) != 0 &&
	litter == ((unsigned char *)s2)[i] && i < n)
		i++;
	return (litter - ((unsigned char *)s2)[i]);
}
