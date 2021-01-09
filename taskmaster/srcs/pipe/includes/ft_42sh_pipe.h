/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pipe.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_PIPE_H
# define FT_42SH_PIPE_H

# include "ft_42sh.h"

typedef struct		s_pipe_in_42sh
{
	t_in_42sh		*list;
	unsigned char	*end;
	size_t			litter;
}					t_pipe_in_42sh;

typedef struct		s_pipe_search_in_42sh
{
	t_main_42sh		*array;
	t_pipe_42sh		*pipe;
	size_t			b_fd_left;
	size_t			b_fd_right;
	size_t			count;
	void			*b;
}					t_pipe_search_in_42sh;

void				ft_42sh_pipe_close_fd(register t_jobs_42sh *jobs);
void				ft_42sh_pipe_close_fd_left(register t_main_42sh *array,
register t_jobs_42sh *jobs);
void				ft_42sh_pipe_close_fd_right(register t_main_42sh *array,
register t_jobs_42sh *jobs);
size_t				ft_42sh_pipe_pre_heredoc(register t_main_42sh *array,
register t_pipe_42sh *pipe, unsigned char **out, t_pipe_in_42sh *in);
size_t				ft_42sh_pipe_pre_heredoc_set(register t_main_42sh *array,
register t_pipe_42sh *pipe, register t_slesh_42sh **spl,
register unsigned char *e);
t_slesh_42sh		**ft_42sh_pipe_pre_heredoc_spl(t_pipe_in_42sh *in,
register char *end, register size_t tempos);
void				*ft_42sh_pipe_pre_heredoc_end(register t_main_42sh *array,
unsigned char *out, register unsigned char *e,
register size_t tempos);
size_t				ft_42sh_pipe_pre_number(register t_main_42sh *array,
register t_pipe_42sh *pipe, register unsigned char *dest,
register unsigned char *end);
size_t				ft_42sh_pipe_pre_set(register t_main_42sh *array,
register t_pipe_42sh *pipe, unsigned char **out, t_pipe_in_42sh *in);
size_t				ft_42sh_pipe_pre_set_add(register t_main_42sh *array,
register t_pipe_42sh *pipe, unsigned char **out, t_pipe_in_42sh *in);
size_t				ft_42sh_pipe_pre_set_open(register t_main_42sh *array,
register t_pipe_42sh *pipe, register unsigned char *dest);
void				ft_42sh_pipe_pre_close(register t_jobs_42sh *jobs,
register t_pipe_42sh *pipe_end);
size_t				ft_42sh_pipe_pre_and_left(register t_jobs_42sh *jobs,
register t_pipe_42sh *pipe_end);
size_t				ft_42sh_pipe_pre_and_right(register t_jobs_42sh *jobs,
register t_pipe_42sh *pipe, register t_pipe_42sh *pipe_end);
t_pipe_42sh			*ft_42sh_pipe_pre_pipe(register t_jobs_42sh *jobs,
register t_pipe_42sh *pipes);
size_t				ft_42sh_pipe_pre_finish(register t_main_42sh *array,
register t_jobs_42sh *jobs, register t_pipe_42sh *pipe,
register size_t b_flag);

void				ft_42sh_pipe_left_hrdc(register t_main_42sh *array,
register t_pipe_42sh *pipe, register int fd_write);
#endif
