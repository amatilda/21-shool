/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase_home.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_replase.h"

size_t		ft_42sh_replase_home_count(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e)
{
	if ((b == e || (b < e && (b[0] <= 0x20 || b[0] == '/' || b[0] == ';')))
	&& b[-2] <= 0x20)
		return (array->count_home);
	return (1);
}

void		*ft_42sh_replase_home(register t_main_42sh *array,
register unsigned char *dest, unsigned char *b, register unsigned char *e)
{
	register size_t		count;

	if ((b == e || (b < e && (b[0] <= 0x20 || b[0] == '/' || b[0] == ';')))
	&& b[-2] <= 0x20)
	{
		count = array->count_home;
		ft_memcpy(dest, array->lp_home, count);
		return (dest + count);
	}
	return (dest);
}
