/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_time.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/11/02 15:12:47 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_STR_TIME_H
# define FN_STR_TIME_H

# include "libft.h"

# define STR_TIME_YEAR_		0x1
# define STR_TIME_MONTH_	0x2
# define STR_TIME_HOUR_		0x4
# define STR_TIME_MIN_		0x8
# define STR_TIME_SEC_		0x16

typedef struct				s_ft_str_time
{
	char					*str_format;
	size_t					tmp;
	uint_fast8_t			b_test;
	char *restrict			s;
	const char *restrict	f;
}							t_ft_str_time;

#endif
