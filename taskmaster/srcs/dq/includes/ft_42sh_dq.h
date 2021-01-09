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

typedef struct			s_dq_test_in_42sh
{
	t_main_42sh			*array;
	t_in_42sh			*list;
	unsigned char		*start;
}						t_dq_test_in_42sh;

typedef struct			s_heredoc_in_42sh
{
	t_main_42sh			*array;
	size_t				n;
	unsigned char		*end;
	unsigned char		*cmp;
}						t_heredoc_in_42sh;

unsigned char			ft_42sh_dq_test_dq(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register unsigned char litter);
unsigned char			ft_42sh_dq_test_dq_exp(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register uint_fast8_t b_test);
unsigned char			ft_42sh_dq_test_err_n(register t_main_42sh *array,
register void *str, register void *add, register size_t n);

unsigned char			ft_42sh_dq_test_slh(register t_main_42sh *array,
register unsigned char *b, register size_t n);
void					ft_42sh_dq_combi_date(register t_main_42sh *array,
register t_in_42sh *dest, register t_in_42sh *src);
size_t					ft_42sh_dq_test_alias(register t_dq_test_in_42sh *in,
unsigned char **out, unsigned char **end, register size_t n);
size_t					ft_42sh_dq_test_pipe(register t_main_42sh *array,
unsigned char **out, register unsigned char *e);
unsigned char			ft_42sh_dq_test_sintax_dq(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register unsigned char lit);
size_t					ft_42sh_dq_test_end(register t_main_42sh *array,
t_dq_test_in_42sh *in, unsigned char **out, register unsigned char *e);
void					*ft_42sh_dq_test_hrdc_cmp(register t_heredoc_in_42sh
*in, register size_t n, unsigned char **out, register unsigned char *end);
unsigned char			ft_42sh_dq_test_hrdc_find(unsigned char **out,
register unsigned char *e);

#endif
