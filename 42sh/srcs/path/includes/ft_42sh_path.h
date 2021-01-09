/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_path.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by amatilda          #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_PATH_H
# define FT_42SH_PATH_H

# include "ft_42sh.h"

t_logins_42sh	*ft_42sh_path_logins_list_create(register unsigned char *name,
register size_t name_count, register unsigned char *home_dir,
register size_t home_dir_count);
void			ft_42sh_path_logins_list_add(register t_main_42sh *array,
register t_logins_42sh *list);
void			ft_42sh_path_logins_test_empty(register t_main_42sh *array);

#endif
