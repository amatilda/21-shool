/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_H
# define FT_ITOA_H

# include "libft.h"

# define FT_ITOA_ALPH	"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef struct		s_itoa
{
	char			*str;
	char			*start;
	char			*buffer;
	uintmax_t		value;
	uint_fast8_t	base;
	uint_fast8_t	option;
	uintmax_t		tmp;
	uint_fast8_t	b_op;
	uint_fast8_t	i;
	uint_fast8_t	count;
	char			*alphabet;
}					t_itoa;

#endif
