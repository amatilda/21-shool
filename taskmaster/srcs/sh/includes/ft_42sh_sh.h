/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_sh.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_SH_H
# define FT_42SH_SH_H

# include "ft_42sh.h"

t_in_42sh		*ft_42sh_sh_get(register t_main_42sh *array,
register char **env_spl, register unsigned char *path, register char **lp_arg);
void			ft_42sh_sh_exit(register t_main_42sh *array,
register size_t exit_code);
t_main_42sh		*ft_42sh_sh_exit_zero_crit(register t_main_42sh *array,
register void *msg);
void			ft_42sh_sh_standart(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b, register unsigned char *e);

#endif
