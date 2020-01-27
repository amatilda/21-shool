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
size_t	ft_42sh_auto_comp_pars_dir(register t_main_42sh *array);
void	ft_42sh_auto_comp_free_struct(register t_main_42sh *array);
size_t	ft_42sh_auto_comp_check_dir(register t_main_42sh *array);
size_t	ft_42sh_auto_comp_search_cmp(register t_main_42sh
*array, char *d_name);
size_t	ft_42sh_auto_comp_type_file(char *d_name, register
t_main_42sh *array);
void	ft_42sh_auto_comp_fill_exist_dir(register t_main_42sh
*array, char *tmp, size_t i);
size_t	ft_42sh_auto_comp_free_not_exist_dir(register t_main_42sh
*array, char *tmp);

#endif
