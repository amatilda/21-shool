/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq_test_slh.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_dq.h"

unsigned char			ft_42sh_dq_test_slh(register t_main_42sh *array,
unsigned char *b, register size_t n)
{
	register unsigned char		*lp_current;
	unsigned char				*save;
	register size_t				tempos;

	lp_current = b + n - 1;
	tempos = 0;
	save = lp_current;
	while (n-- != 0 && lp_current--[0] == '\\')
		tempos++;
	if ((tempos & 0x1) == 0)
		return (0);
	if ((array->b_location & LOCATION_SCRIPT_42SH) != 0)
	{
		save[0] = 0x20;
		return (0);
	}
	return ('\\');
}
