/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_KEY_H
# define FT_42SH_KEY_H

# include "ft_42sh.h"

typedef struct			s_test_number_42sh
{
	void				*lp;
	uint_fast8_t		sig;
}						t_test_number_42sh;

void					*ft_42sh_cm_echo_number(register t_write_buff *out,
register unsigned char *str, unsigned char **save);

t_jobs_42sh				*ft_42sh_cm_jobs_number(register t_main_42sh *array,
register unsigned char *str, register size_t b_view);
t_jobs_42sh				*ft_42sh_cm_jobs_str(register t_main_42sh *array,
register unsigned char *str, register size_t b_view);
t_jobs_42sh				*ft_42sh_cm_jobs_find(register t_main_42sh *array,
register unsigned char *str, register size_t b_view);
void					ft_42sh_cm_jobs_killgrp(register t_jobs_42sh *jobs,
register int signo);

void					ft_42sh_cm_hash_arg(register t_main_42sh *array,
register char **lp_arg);

size_t					ft_42sh_cm_test_path(register t_main_42sh *array,
register char **lp_arg, register unsigned char *str,
register unsigned char litter);
size_t					ft_42sh_cm_test_three(register t_main_42sh *array,
register unsigned char *first, register unsigned char *eq,
register unsigned char *two);
size_t					ft_42sh_cm_test_three_number(register t_main_42sh
*array, register unsigned char *lp_number,register t_test_number_42sh *out);
size_t					ft_42sh_cm_test_three_err_unk(register t_main_42sh *array,
register unsigned char *eq);
size_t					ft_42sh_cm_test_two(register t_main_42sh *array,
register char **lp_arg, register unsigned char *str);

void					ft_42sh_cm_cd_set(register t_main_42sh *array,
register unsigned char *str, register size_t b_view);

void					ft_42sh_cm_export_set(register t_main_42sh *array,
register char **lp_arg);

#endif
