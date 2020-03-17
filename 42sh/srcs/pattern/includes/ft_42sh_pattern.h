/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pattern.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_PATTERN_H
# define FT_42SH_PATTERN_H

# include "ft_42sh.h"

size_t			ft_42sh_pattern_star(register unsigned char *b,
register unsigned char *e, register unsigned char *b_ptt,
register unsigned char *e_ptt);

size_t			ft_42sh_pattern_slesh(unsigned char **out,
unsigned char **out_ptt, register unsigned char *e_ptt);
size_t			ft_42sh_pattern_slesh_litter(register unsigned char *b_ptt,
register unsigned char *e_ptt, register uint32_t cmp_lit);
void			ft_42sh_pattern_slesh_next(unsigned char **out_ptt,
register unsigned char *e_ptt);

size_t			ft_42sh_pattern_interval(unsigned char **out,
unsigned char **out_ptt, register unsigned char *e_ptt);
size_t			ft_42sh_pattern_interval_while(register uint32_t cmp_lit,
register unsigned char *b_ptt, register unsigned char *e_ptt);
unsigned char	*ft_42sh_pattern_interval_end(register unsigned
char *b_ptt, register unsigned char *e_ptt);

#endif
