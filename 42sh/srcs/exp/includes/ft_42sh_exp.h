/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_EXP_H
# define FT_42SH_EXP_H

# include "ft_42sh.h"

typedef struct		s_exp_in_exp_42sh
{
	unsigned char	*start;
	size_t			count;
	char			buff[sizeof(uintmax_t) * 8];
}					t_exp_in_exp_42sh;

void				ft_42sh_exp_standart(register t_main_42sh *array);
t_env_42sh			*ft_42sh_exp_create(register t_main_42sh *array,
register unsigned char *key, register unsigned char *key_end,
register t_add_exp_42sh *in);
t_env_42sh			*ft_42sh_exp_sort_paste(register t_main_42sh *array,
register unsigned char *key, register unsigned char *key_end,
register t_add_exp_42sh *in);
t_env_42sh			*ft_42sh_exp_sort_paste_cut(register t_env_main_42sh *env,
register t_std_key_42sh *cur, register t_env_42sh *list);
t_env_42sh			*ft_42sh_exp_spc_add(register t_main_42sh *array,
register t_env_42sh *list);
void				ft_42sh_exp_spc_del(register t_main_42sh *array,
register unsigned char *key, register size_t n);
void				ft_42sh_exp_spc_correction(register t_main_42sh *array,
register t_env_42sh *list);
unsigned char		*ft_42sh_exp_pars_exp(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src,
register unsigned char *end);
size_t				ft_42sh_exp_pars_exp_count(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **src, register unsigned char *end);
size_t				ft_42sh_exp_pars_exp_litter_count(
register t_main_42sh *array, register unsigned char *key,
register unsigned char *key_end);
unsigned char		*ft_42sh_exp_pars_exp_litter(register t_main_42sh *array,
register unsigned char *dest, register unsigned char *key,
register unsigned char *key_end);
size_t				ft_42sh_exp_pars_exp_oth_count(register
t_replase_in_42sh *in, unsigned char **s, unsigned char **src,
register unsigned char *end);
size_t				ft_42sh_exp_pars_exp_oth_count_question(register
t_replase_in_42sh *in, unsigned char **s, unsigned char **src,
register unsigned char *end);
unsigned char		*ft_42sh_exp_pars_exp_oth(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src,
register unsigned char *end);
size_t				ft_42sh_exp_pars_exp_sufix_count(register
t_replase_in_42sh *in, unsigned char **s, unsigned char **src,
register unsigned char *end);
unsigned char		*ft_42sh_exp_pars_exp_sufix(register
t_replase_in_42sh *in, register unsigned char *dest, unsigned char **src,
register unsigned char *end);
size_t				ft_42sh_exp_pars_exp_prefix_count(register
t_replase_in_42sh *in, unsigned char **s, unsigned char **src,
register unsigned char *end);
unsigned char		*ft_42sh_exp_pars_exp_prefix(register
t_replase_in_42sh *in, register unsigned char *dest, unsigned char **src,
register unsigned char *end);
void				*ft_42sh_exp_pars_exp_set(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src,
register unsigned char *end);
size_t				ft_42sh_exp_pars_exp_set_count(register
t_replase_in_42sh *in, unsigned char **s, unsigned char **src,
register unsigned char *end);

void				*ft_42sh_exp_pars_exp_prefix_add_str(register
t_env_42sh *list, char *buff);
void				*ft_42sh_exp_pars_exp_prefix_add_set(register
t_replase_in_42sh *in, t_exp_in_exp_42sh *ptr, unsigned char **src,
register unsigned char *end);
void				*ft_42sh_exp_pars_exp_sufix_add_str(register
t_env_42sh *list, char *buff);
void				*ft_42sh_exp_pars_exp_sufix_add_set(register
t_replase_in_42sh *in, t_exp_in_exp_42sh *ptr, unsigned char **src,
register unsigned char *end);

#endif
