/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_REPLASE_H
# define FT_42SH_REPLASE_H

# include "ft_42sh.h"

typedef struct		s_replase_in
{
	unsigned char	*s;
	size_t			exps_loop;
}					t_replase_in;

size_t				ft_42sh_replase_home_test(register t_main_42sh *array,
register unsigned char *start, register unsigned char *b,
register unsigned char *e);
size_t				ft_42sh_replase_home_count(register t_main_42sh *array,
register unsigned char **out);
void				*ft_42sh_replase_home(register t_main_42sh *array,
register unsigned char *dest, register unsigned char **out);
size_t				ft_42sh_replase_slesh_count(unsigned char **out,
register unsigned char *e);
void				*ft_42sh_replase_slesh(register unsigned char *dest,
unsigned char **out, register unsigned char *e);
size_t				ft_42sh_replase_slesh_exp_count(unsigned char **out,
register unsigned char *e);
void				*ft_42sh_replase_slesh_exp(register unsigned char *dest,
unsigned char **out, register unsigned char *e);
size_t				ft_42sh_replase_quotes_one_count(register
t_replase_in_42sh *in, register unsigned char **out);
unsigned char		*ft_42sh_replase_quotes_one(register
t_replase_in_42sh *in, register unsigned char *dest, unsigned char **src);
size_t				ft_42sh_replase_quotes_two_count(register
t_replase_in_42sh *in, register unsigned char **out,
register unsigned char *e);
unsigned char		*ft_42sh_replase_quotes_two(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src, register unsigned char *e);

size_t				ft_42sh_replase_add_tilda(register t_replase_in_42sh *in,
register unsigned char *start, register unsigned char *b,
register unsigned char *e);
void				ft_42sh_replase_add_finish(register t_replase_in_42sh *in,
size_t exps_loop);
size_t				ft_42sh_replase_add_test(register t_replase_in_42sh *in,
unsigned char **dest, unsigned char *b, register unsigned char lit);

size_t				ft_42sh_replase_hrdc_test_dq(unsigned char **out,
register unsigned char *e);

#endif
