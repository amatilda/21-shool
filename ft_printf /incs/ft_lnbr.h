/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnbr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkrypto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:19:47 by jkrypto           #+#    #+#             */
/*   Updated: 2019/11/09 16:38:14 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LNBR_H
# define FT_LNBR_H

# include "libft.h"

# define NUM_SIZE 0x5000

typedef struct	s_lnbr
{
	char		num[NUM_SIZE];
	size_t		len;
}				t_lnbr;

t_lnbr			ft_numzero(size_t len);
t_lnbr			ft_numtrim(register t_lnbr nbr);

t_lnbr			ft_long_pow(register t_lnbr base, size_t pow);
t_lnbr			ft_long_sum(register t_lnbr nbr1, register t_lnbr nbr2);
t_lnbr			ft_long_mul(register t_lnbr nbr1, register t_lnbr nbr2);

t_lnbr			ft_parse_sing(register t_lnbr nbr);
t_lnbr			ft_parse_fract(register t_lnbr nbr);
t_lnbr			ft_round(register t_lnbr sing, register t_lnbr fract,
						size_t prec);

#endif
