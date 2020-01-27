/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_dq.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_DQ_H
# define FT_42SH_DQ_H

# include "ft_42sh.h"

unsigned char	ft_42sh_dq_test(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b,
register unsigned char *e);
unsigned char	ft_42sh_dq_test_dq(unsigned char **out,
register unsigned char *e, register unsigned char litter);
unsigned char	ft_42sh_dq_test_sub(unsigned char **out,
register unsigned char *e, register unsigned char litter);
unsigned char	ft_42sh_dq_test_slh(register unsigned char *b,
register size_t n);
unsigned char	ft_42sh_dq_test_hrdc(register t_main_42sh *array,
register t_in_42sh *list, unsigned char **b, register unsigned char *e);
void			ft_42sh_dq_combi_date(register t_main_42sh *array,
register t_in_42sh *dest, register t_in_42sh *src);

#endif
