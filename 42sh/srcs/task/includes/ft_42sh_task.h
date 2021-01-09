/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by amatilda          #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_TASK_H
# define FT_42SH_TASK_H

# include "ft_42sh.h"

typedef	struct			s_task_find_cmd
{
	char				*cmd;
	void				(*f)(register t_main_42sh *array,
	register char **lp_arg);
}						t_task_find_cmd;

void					ft_42sh_task_cmd(register t_main_42sh *array,
register char **lp_arg);
void					ft_42sh_task_cmd_load(register t_main_42sh *array,
register char **lp_arg);
void					ft_42sh_task_cmd_reload(register t_main_42sh *array,
register char **lp_arg);
void					ft_42sh_task_cmd_help(register t_main_42sh *array,
register char **lp_arg);
void					ft_42sh_task_cmd_print(register t_main_42sh *array,
register char **lp_arg);
void					ft_42sh_task_cmd_delete(register t_main_42sh *array,
register char **lp_arg);

#endif
