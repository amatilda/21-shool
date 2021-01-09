/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_AUTO_H
# define FT_42SH_AUTO_H

# include "ft_42sh.h"

t_all_cmd_42sh	*ft_42sh_auto_list_create(register t_main_42sh *array,
register char *key, register char add_litter);
void			*ft_42sh_auto_list_add(register t_main_42sh *array,
register t_all_cmd_42sh *list, register void *str, register size_t b_type);
t_all_cmd_42sh	**ft_42sh_auto_cmd_test(register t_main_42sh *array,
register t_in_42sh *list, register t_all_cmd_42sh **spl,
register t_all_cmd_42sh **spl_end);
size_t			ft_42sh_auto_cmd_test_env(register t_main_42sh *array,
register t_in_42sh *list, register t_all_cmd_42sh **spl,
register t_all_cmd_42sh **spl_end);
size_t			ft_42sh_auto_cmd_env_corection(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b, register size_t n);

size_t			ft_42sh_auto_cmd_env_replase(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b);
void			ft_42sh_auto_cmd_env_replase_del(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b,
register unsigned char *e);
void			*ft_42sh_auto_cmd_env_replase_get(register t_main_42sh *array,
register unsigned char *b, register unsigned char **e);

void			ft_42sh_auto_cmd_env_close(register t_main_42sh *array,
register t_in_42sh *list, register size_t n);
void			*ft_42sh_auto_cmd_env_close_while_exp(register
unsigned char *dest, unsigned char **out, register unsigned char *e);
void			*ft_42sh_auto_cmd_env_close_dq_two(register
unsigned char *dest, unsigned char **out, register unsigned char *e);
void			*ft_42sh_auto_cmd_env_close_dq(register unsigned char *dest,
unsigned char **out, register unsigned char *e);
size_t			ft_42sh_auto_cmd_env_close_while_exp_count(register
unsigned char **out, register unsigned char *e, size_t *n);
size_t			ft_42sh_auto_cmd_env_close_dq_two_count(register
unsigned char **out, register unsigned char *e, size_t *n);
size_t			ft_42sh_auto_cmd_env_close_dq_count(register
unsigned char **out, register unsigned char *e, size_t *n);
void			*ft_42sh_auto_cmd_env_close_while(register
unsigned char *dest, unsigned char **out, register unsigned char *e);
size_t			ft_42sh_auto_cmd_env_close_while_count(register
unsigned char **out, register unsigned char *e, size_t *n);

#endif
