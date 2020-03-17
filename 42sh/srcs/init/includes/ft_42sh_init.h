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

void		ft_42sh_init_event(register t_main_42sh *array);
void		ft_42sh_init_variable(register t_main_42sh *array);
void		ft_42sh_init_terminal(register t_main_42sh *array);
void		ft_42sh_init_fd(register t_main_42sh *array);

#endif
