/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_glb.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by amatilda          #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_GLB_H
# define FT_42SH_GLB_H

# include "ft_42sh.h"

void		ft_42sh_glb_list_add(register t_main_42sh *array,
register unsigned char *path, register char *name, register const char *src);
void		ft_42sh_glb_while_dir(register t_main_42sh *array,
register const char *src, register unsigned char *path,
register char *path_dir);
void		ft_42sh_glb_list_add_only(register t_main_42sh *array,
t_glb_list *list);

#endif
