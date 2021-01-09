/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:09:35 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:09:37 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_EXE_H
# define FT_42SH_EXE_H

# include "ft_42sh.h"

void			ft_42sh_exe_fork(register t_main_42sh *array,
register t_jobs_42sh *jobs, int *fds);
void			ft_42sh_exe_grup(register t_main_42sh *array,
register t_jobs_42sh *jobs, pid_t pid, int *fds);
size_t			ft_42sh_exe_fun(register t_main_42sh *array,
register t_jobs_42sh *jobs, char **lp_arg,
void (*f)(register t_main_42sh *array, register char **lp_arg));
void			ft_42sh_exe_fun_run(register t_main_42sh *array,
register t_jobs_42sh *jobs, char **lp_arg,
void (*f)(register t_main_42sh *array, register char **lp_arg));
void			ft_42sh_exe_err(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_exe_set(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_exe_set_(register t_main_42sh *array,
register t_exp_set_42sh *exp_set, size_t b_type);
size_t			ft_42sh_exe_while(register t_main_42sh *array,
register t_jobs_42sh *jobs, register size_t b_test);
size_t			ft_42sh_exe_err_foor(register t_main_42sh *array,
register t_jobs_42sh *jobs);

size_t			ft_42sh_exe_wait_finish(register t_main_42sh *array,
register t_jobs_42sh *jobs, t_jobs_42sh *jobs_cl, register size_t b_test);

#endif
