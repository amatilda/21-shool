/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_sh_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_sh.h"

void			*ft_42sh_sh_comment(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e)
{
	if ((array->b_location & LOCATION_SCRIPT_42SH) == 0)
		return (b);
	while ((b = ft_42sh_parsing_sp(b, e)) < e && b[0] == '#')
	{
		while (b < e && b[0] != '\n')
			b++[0] = ' ';
		b = ft_42sh_parsing_sp(b, e);
		if (b < e && b[0] == '\n')
			b++;
	}
	return (b);
}
