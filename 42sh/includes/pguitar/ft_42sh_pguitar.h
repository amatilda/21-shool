/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pguitar.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:11:23 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:11:26 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_PGUITAR_H
# define FT_42SH_PGUITAR_H

void			ft_42sh_auto_comp_init_struct(register t_main_42sh *array,
				register t_in_42sh *list, register char *start,
				register char *end);

void			ft_42sh_alias(register t_main_42sh *array,
				register char **lp_arg);
void			ft_42sh_alias_un(register t_main_42sh *array,
				register char **lp_arg);
void			ft_42sh_alias_file(register t_main_42sh *array);
void			ft_42sh_alias_read_file(register t_main_42sh *array, int fd);
void			ft_42sh_alias_pars_home(register t_main_42sh *array);

size_t			ft_42sh_arith_test(register t_main_42sh *array,
unsigned char **src, register unsigned char *e);

#endif
