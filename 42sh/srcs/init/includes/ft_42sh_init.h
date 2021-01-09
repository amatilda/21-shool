/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_INIT_H
# define FT_42SH_INIT_H

# include "ft_42sh.h"

void		ft_42sh_init_test_while(register t_main_42sh *array);
void		ft_42sh_init_test_add(register t_main_42sh *array);
void		ft_42sh_init_test(register t_main_42sh *array);
void		ft_42sh_init_event(register t_main_42sh *array);
void		ft_42sh_init_variable(register t_main_42sh *array,
register size_t b_location);
void		ft_42sh_init_variable_fun(register t_main_42sh *array);
void		ft_42sh_init_terminal(register t_main_42sh *array);
void		ft_42sh_init_fd(void);

void		ft_42sh_init_script_env(register t_main_42sh *array,
register char **env, register char **lp_arg);

void		ft_42sh_init_test_while_signal_ign(void);
void		ft_42sh_init_test_while_signal_dfl(void);

#endif
