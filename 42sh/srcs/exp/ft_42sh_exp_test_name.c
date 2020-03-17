/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_test_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_exp.h"

void			*ft_42sh_exp_test_exp_auto(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char			litter;

	if (b == e || ((litter = b[0]) >= 0x30 && litter <= 0x39))
		return (b);
	return (ft_42sh_exp_name(b, e));
}

void			*ft_42sh_exp_test_exp(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char			*tmp;
	register unsigned char			litter;

	if (b == e || ((litter = b[0]) >= 0x30 && litter <= 0x39))
		return (0);
	tmp = ft_42sh_exp_name(b, e);
	if (tmp == e)
		return (0);
	if (b[0] == '=' || tmp[0] != '=')
		return (0);
	return (tmp + 1);
}

void			*ft_42sh_exp_test_name_arith(register unsigned char *b,
register unsigned char *e)
{
	register unsigned char			*tmp;
	register unsigned char			litter;

	if (b == e || ((litter = b[0]) >= 0x30 && litter <= 0x39))
		return (0);
	tmp = ft_42sh_exp_name(b, e);
	if (tmp == e)
		return (tmp);
	return (0);
}
