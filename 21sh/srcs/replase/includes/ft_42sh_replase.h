/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_replase.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_REPLASE_H
# define FT_42SH_REPLASE_H

# include "ft_42sh.h"

size_t			ft_42sh_replase_home_count(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e);
void			*ft_42sh_replase_home(register t_main_42sh *array,
register unsigned char *dest, unsigned char *b, register unsigned char *e);
size_t			ft_42sh_replase_slesh_count(unsigned char **out,
register unsigned char *e, register unsigned char dquote);
void			*ft_42sh_replase_slesh(register unsigned char *dest,
unsigned char **out, register unsigned char *e, register unsigned char dquote);

#endif
