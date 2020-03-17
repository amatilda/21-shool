/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_key.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_KEY_H
# define FT_42SH_KEY_H

# include "ft_42sh.h"

void				*ft_42sh_key_tab_word_end(register unsigned char *b,
register unsigned char *e);
void				*ft_42sh_key_tab_word_start(register unsigned char *start,
register unsigned char *current, register unsigned char *end);
void				*ft_42sh_key_tab_cmd_end(register unsigned char *b,
register unsigned char *e);
void				*ft_42sh_key_tab_cmd_start(register unsigned char *b,
register unsigned char *e);
void				*ft_42sh_key_tab_eq(register unsigned char *b,
register unsigned char *e);
size_t				ft_42sh_key_tab_dq(register unsigned char *b,
register unsigned char *e, register unsigned char litter);
void				*ft_42sh_key_tab_pipe(register unsigned char *b,
register unsigned char *e, register unsigned char litter);

#endif
