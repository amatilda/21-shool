/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_litter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

unsigned char		ft_42sh_parsing_litter_e(register unsigned char litter)
{
	if (litter == ';' || litter == '\n')
		return (0);
	return (litter);
}

unsigned char		ft_42sh_parsing_litter_e_f(register unsigned char litter)
{
	if (litter == ';' || litter == '\n' || litter == '|')
		return (0);
	return (litter);
}
