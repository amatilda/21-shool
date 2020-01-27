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

void			ft_42sh_signal_term(int signo);
void			ft_42sh_signal_winch(int signo);
void			ft_42sh_signal_int(int signo);
void			ft_42sh_signal_pipe(int signo);

#endif
