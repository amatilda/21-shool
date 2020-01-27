/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:23:41 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/17 12:01:39 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strcmp(register char *s1, register char *s2)
{
	register size_t		i;
	register char		litter;

	i = 0;
	while ((litter = s1[i]) != 0 && litter == s2[i])
		i++;
	return ((unsigned char)litter - (unsigned char)s2[i]);
}
