/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:30:10 by wstygg            #+#    #+#             */
/*   Updated: 2021/01/09 13:44:14 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONF_H
# define CONF_H

# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "conf_reader.h"
# include "structures.h"
# include "list.h"

# define IS_E		0
# define IS_R		1
# define IS_W		2
# define IS_X		4
# define IS_D		8

char				*create_name(char *conf, int i);
char				*create_command(char *conf, int i);
char				*create_directory(char *conf, int i, char *current);
int					create_umask(char *conf, int i);
int					create_copies(char *conf, int i);
char				*create_stdout(char *conf, int i, char *current);
char				*create_stderr(char *conf, int i, char *current);
int					create_restart(char *conf, int i);
int					create_retries(char *conf, int i);
int					create_on_start(char *conf, int i);
int					create_stop_signal(char *conf, int i);
int					create_stop_waiting(char *conf, int i);
int					create_success_waiting(char *conf, int i);
void				create_end_codes(int codes[END_CODES_N],
						char *conf, int i);
void				create_env(t_task *task, char **c, int *i);
t_task				*create_task(char **conf, int *i_p, t_list *tasks);

int					check_file(const char *file, unsigned check);
int					check_uniq(int p, int *uniq, int i, char *str);
int					tab_count(const char *str);
char				*skip_emptiness(char *str);
char				**add_to_text(char **text, char *add);

int					get_nl(int fd, char **line);
int					str_is_empty(const char *str);
void				*my_malloc(size_t size);
int					ft_split_size(char **split);
void				ft_free_split(char **split);
char				**ft_splitstr(char *str);
int					my_atoi(const char *str);
int					ft_error(const char *msg, ...);
void				*my_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*my_strjoin(const char *str, const char *str2,
								int to_free);
int					open_conf(const char *path);

int					check_task_name(const char *name, t_list *tasks, int i);
void				fill_task(char **conf, int *i, t_task *task,
								int uniq[PARAMS_N]);

t_log				*get_log(void);

#endif
