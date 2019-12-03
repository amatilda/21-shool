/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:13:42 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_H
# define FT_ITOA_H

# include "libft.h"

typedef struct		s_itoa
{
	char			*str;
	char			*start;
	char			*buffer;
	char			*alphabet;
	uintmax_t		tmp;
	uintmax_t		value;
	uint_fast8_t	i;
	uint_fast8_t	b_op;
	uint_fast8_t	base;
	uint_fast8_t	count;
	uint_fast8_t	option;
}					t_itoa;

#endif
