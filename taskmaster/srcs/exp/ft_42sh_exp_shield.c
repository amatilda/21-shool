/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_shield.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_exp.h"

size_t			ft_42sh_exp_shield(register unsigned char *value,
register unsigned char *value_e)
{
	register unsigned char			lit;

	lit = 0;
	while (value < value_e)
	{
		if ((lit = value[0]) < 0x20 || lit == '\'' || lit == '"' ||
		lit == '$' || lit == '\\' || lit == '[' || lit == ']' ||
		lit == '*' || lit == '?')
			break ;
		value++;
	}
	if (value != value_e || lit == 0)
		return (EXP_TYPE_CORECTION_42SH);
	return (0);
}
