/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_comp.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_AUTO_COMP_H
# define FT_42SH_AUTO_COMP_H

# include "ft_42sh.h"

void	ft_42sh_auto_comp_pars_without_quote(register char *cur,
register t_main_42sh *array, register char *end);
void	ft_42sh_auto_comp_free_strdup(register t_main_42sh *array);
size_t	ft_42sh_auto_comp_pars_dir(register t_main_42sh *array,
register t_in_42sh *list);
void	ft_42sh_auto_comp_free_struct(register t_main_42sh *array);
size_t	ft_42sh_auto_comp_check_dir(register t_main_42sh *array,
register t_in_42sh *list, char *tmp);
size_t	ft_42sh_auto_comp_search_cmp(register t_main_42sh
*array, char *d_name);
size_t	ft_42sh_auto_comp_type_file(char *d_name, register
t_main_42sh *array);
void	ft_42sh_auto_comp_fill_exist_dir(register t_main_42sh
*array, char *tmp, size_t i);
size_t	ft_42sh_auto_comp_free_not_exist_dir(register t_main_42sh
*array, char *tmp);
void	ft_42sh_auto_comp_right_pars_quote(register t_main_42sh *array,
register t_in_42sh *list, register char *start, register char *end);
void	ft_42sh_auto_comp_pars_dol(char **cur,
register t_main_42sh *array, register char **end);
size_t	ft_42sh_auto_comp_exp_str(register t_main_42sh *array,
char *str, register t_in_42sh *list);
size_t	ft_42sh_replase_home_test(register t_main_42sh *array,
register unsigned char *start, register unsigned char *b,
register unsigned char *e);
size_t	ft_42sh_auto_comp_pars_dir_tilda(register t_main_42sh *array,
register t_in_42sh *list);
int		ft_42sh_auto_comp_strncmp(register char *s1, register char *s2,
register size_t n);
size_t	ft_42sh_auto_comp_pars_dir_tilda_slash(register t_main_42sh *array,
size_t i);

#endif
