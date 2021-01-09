/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_CM_H
# define FT_42SH_CM_H

# include "ft_42sh.h"

typedef struct			s_test_number_42sh
{
	void				*lp;
	size_t				n;
	uint_fast8_t		sig;
}						t_test_number_42sh;

void					ft_42sh_cm_bg_process(register t_main_42sh *array,
register t_jobs_42sh *jobs);

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
void					ft_42sh_cm_hash_reset(register t_main_42sh *array,
register char **lp_arg);

size_t					ft_42sh_cm_test_path(register t_main_42sh *array,
register char **lp_arg, register unsigned char *str,
register unsigned char litter);
size_t					ft_42sh_cm_test_three(register t_main_42sh *array,
register unsigned char *first, register unsigned char *eq,
register unsigned char *two);
size_t					ft_42sh_cm_test_three_number(register t_main_42sh
*array, register unsigned char *lp_number, register t_test_number_42sh *out);
size_t					ft_42sh_cm_test_three_err_unk(register
t_main_42sh *array, register unsigned char *eq);
size_t					ft_42sh_cm_test_three_err_unk_not(register
t_main_42sh *array, register unsigned char *eq);
size_t					ft_42sh_cm_test_two(register t_main_42sh *array,
register char **lp_arg, register unsigned char *str);

void					ft_42sh_cm_cd_set(register t_main_42sh *array,
register unsigned char *str, register unsigned char *dir,
register size_t b_view);
void					ft_42sh_cm_cd_process(register t_main_42sh *array,
register char **spl, register void *str, register size_t b_view);

void					ft_42sh_cm_export_set(register t_main_42sh *array,
register char **lp_arg);

void					ft_42sh_cm_type_msg(register t_main_42sh *array,
register t_write_buff *out, register t_all_cmd_42sh **spl,
register unsigned char *b);

t_env_42sh				*ft_42sh_exp_add_task(register t_main_42sh *array,
register unsigned char *key, register unsigned char *key_end,
register t_add_exp_42sh *in);

#endif
