/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_JOBS_H
# define FT_42SH_JOBS_H

# include "ft_42sh.h"

void				ft_42sh_jobs_msg_pid(register t_write_buff *out,
register pid_t pid);
void				ft_42sh_jobs_msg_id(register t_write_buff *out,
register t_jobs_42sh *jobs, register size_t b_test);
t_jobs_42sh			*ft_42sh_jobs_msg_exit(register t_write_buff *out,
register t_jobs_42sh *jobs, register size_t b_test);
t_jobs_42sh			*ft_42sh_jobs_msg_signal(register t_main_42sh *array,
register t_write_buff *out, register t_jobs_42sh *jobs,
register size_t b_test);
void				ft_42sh_jobs_list_create_id(register t_main_42sh *array,
register t_jobs_42sh *out, register size_t count);
void				ft_42sh_jobs_free(register t_jobs_42sh *jobs);

#endif
