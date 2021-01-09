/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_signal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_SIGNAL_H
# define FT_42SH_SIGNAL_H

# include "ft_42sh.h"

void			ft_42sh_signal_winch(int signo);

void			ft_42sh_signal_child(int signo);
void			ft_42sh_signal_child_msg(register t_main_42sh *array,
register t_jobs_42sh *jobs, register size_t b_test);
void			ft_42sh_signal_child_msg_start(register t_main_42sh *array,
register t_write_buff *out, register t_in_42sh *list);
size_t			ft_42sh_signal_child_test_pipe(register t_jobs_42sh *jobs,
register pid_t pid, int stat_loc);

void			ft_42sh_signal_hup(int signo);

#endif
