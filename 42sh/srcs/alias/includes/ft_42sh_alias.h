/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_alias.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_ALIAS_H
# define FT_42SH_ALIAS_H

# include "ft_42sh.h"

void	ft_42sh_alias_pars(register t_main_42sh *array,
		register char **lp_arg);
char	*ft_42sh_alias_pars_value(register t_main_42sh *array,
		register char *arg, size_t *v_cnt);
char	*ft_42sh_alias_pars_name(register char *arg, size_t *n_cnt,
		register t_main_42sh *array);
void	ft_42sh_alias_fill_list(t_pguitar_alias_42sh *list,
		register char *arg, register char *lp_arg);
void	ft_42sh_alias_pars_dsp_all(t_main_42sh *array);
void	ft_42sh_alias_pars_dsp_one(char **lp_arg, t_main_42sh *array);
void	ft_42sh_unalias(register t_main_42sh *array,
		register char **lp_arg);
size_t	ft_42sh_alias_pars_name_error(size_t i, char *arg,
		char *tmp_arg, register t_main_42sh *array);
void	ft_42sh_alias_pars_dsp_write_v(t_main_42sh *array,
register t_pguitar_alias_42sh *list);

#endif
