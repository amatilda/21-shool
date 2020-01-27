/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_H
# define FT_42SH_H

# include "libft.h"
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <errno.h>

# include <stdio.h>

# include "ft_42sh_define.h"
# include "ft_42sh_struct.h"
# include "pguitar/ft_42sh_pguitar.h"

void			ft_42sh_init(register t_main_42sh *array);
void			ft_42sh_msg_change(register t_main_42sh *array,
register unsigned char litter, unsigned char litter_prev);
void			ft_42sh_read(register t_main_42sh *array);
void			**ft_42sh_spl_find(register void **spl,
register size_t max_spl, register char *str, register size_t n);
void			ft_42sh_exit(register size_t exit_code);

void			ft_42sh_dq(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_dq_paste(register t_main_42sh *array);
void			ft_42sh_dq_cut(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_dq_split(register t_in_42sh *list,
register size_t count);
t_slesh_42sh	**ft_42sh_dq_split_dup(register t_slesh_42sh **spl,
register size_t n);
void			ft_42sh_dq_split_add_empty(register t_in_42sh *list,
register t_slesh_42sh **spl_slesh);

void			ft_42sh_key_backspace(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_delete(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_up(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_down(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_tab(register t_main_42sh *array,
register t_in_42sh *list);
size_t			ft_42sh_key_left(register t_main_42sh *array,
register t_in_42sh *list);
size_t			ft_42sh_key_right(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_home(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_end(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_word_left(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_word_right(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_eof(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_select_left(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_select_right(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_str_delete(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_str_copy(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_str_paste(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_str_cut(register t_main_42sh *array,
register t_in_42sh *list);

void			ft_42sh_env_start(register t_main_42sh *array,
register char **env);
t_env_42sh		*ft_42sh_env_create(register char *key,
register size_t key_count, register char *value,
register size_t value_count);
void			ft_42sh_env_free(register void *list);
size_t			ft_42sh_exp_parsing_count(register t_past_sort_42sh *root,
unsigned char **src, register unsigned char *end);
unsigned char	*ft_42sh_exp_parsing(register t_past_sort_42sh *root,
register unsigned char *dest, unsigned char **src,
register unsigned char *end);
char			**ft_42sh_env_split(register t_std_key_42sh *list,
register size_t count);

t_in_42sh		*ft_42sh_list_in_create(register t_main_42sh *array,
register size_t max);
t_in_42sh		*ft_42sh_list_in_create_dup(register t_main_42sh *array,
register t_in_42sh *list);
t_in_42sh		*ft_42sh_list_in_create_dup_full(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_list_in_free(register t_in_42sh *list);
void			ft_42sh_list_in_default(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_list_in_last(register t_main_42sh *array);
void			ft_42sh_list_in_dup(register t_in_42sh *list);
void			ft_42sh_list_in_dup_restore(register t_main_42sh *array);
void			ft_42sh_list_in_limit(register t_main_42sh *array);

int				ft_42sh_list_sort_paste(register t_past_sort_42sh *root,
register t_std_key_42sh *list, void (*fn_free)(register void *));
void			ft_42sh_list_fun(register t_past_sort_42sh *root,
void (*f)(register void *));
void			ft_42sh_list_cut(register t_past_sort_42sh *root,
register t_std_key_42sh *list);
void			*ft_42sh_list_find_key(t_past_sort_42sh *root,
register char *key, register size_t n);

void			ft_42sh_auto_create(register t_main_42sh *array);
void			ft_42sh_auto_create_array(register t_main_42sh *array);
void			*ft_42sh_auto_add_list(register t_main_42sh *array,
register char *lp_key, char add_litter);
void			ft_42sh_auto_free_all_cmd(register t_main_42sh *array);
void			ft_42sh_auto_toogle(register t_main_42sh *array);
void			ft_42sh_auto_cmd(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *str, register size_t n);
t_all_cmd_42sh	**ft_42sh_auto_cmd_test(register t_main_42sh *array,
register t_in_42sh *list, register t_all_cmd_42sh **spl,
register t_all_cmd_42sh **spl_end);
size_t			ft_42sh_auto_dsp_cmd(t_main_42sh *array, size_t max_litter,
t_all_cmd_42sh **spl, size_t max_cmd);
size_t			ft_42sh_auto_dsp_cmd_raw(register t_main_42sh *array,
register size_t max_litter, register size_t max_cmd);
void			ft_42sh_auto_limit(register t_main_42sh *array,
register size_t max_litter, register t_all_cmd_42sh **spl,
register size_t max_cmd);
void			ft_42sh_auto_dsp_next_cmd(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_auto_dsp_next_cmd_pre(register t_main_42sh *array,
register t_in_42sh *list);

size_t			ft_42sh_exe_availability(register t_main_42sh *array,
register char *cmd);
size_t			ft_42sh_exe(register t_main_42sh *array);

void			ft_42sh_cm_exit(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_env(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_echo(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_setenv(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_unsetenv(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_cd(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_clear(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_clear_key(register t_main_42sh *array,
register t_in_42sh *list);

void			ft_42sh_parsing(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char litter);
unsigned char	ft_42sh_parsing_test(register t_main_42sh *array,
unsigned char *b, register unsigned char *end);
unsigned char	ft_42sh_parsing_test_pipe(register unsigned char *b,
register unsigned char *e, register unsigned char litter, unsigned char old);
unsigned char	ft_42sh_parsing_test_next(unsigned char **out,
register unsigned char *e, register unsigned char dquote, unsigned char old);
void			ft_42sh_parsing_cmd(register t_main_42sh *array,
register t_string *string, unsigned char **b, register unsigned char *end);
char			**ft_42sh_parsing_arg(register t_main_42sh *array,
unsigned char **b, register unsigned char *end, size_t b_empty);
char			**ft_42sh_parsing_arg_empty(register t_main_42sh *array,
unsigned char **out, register unsigned char *end);
void			ft_42sh_parsing_path(register t_string *ret,
register t_string *root, register char *str, register size_t n);
size_t			ft_42sh_parsing_path_test(register char *b, register char *e);
size_t			ft_42sh_parsing_end(register t_main_42sh *array,
unsigned char **out, register unsigned char *e, register size_t count);
void			*ft_42sh_parsing_sp(register unsigned char *b,
register unsigned char *e);
unsigned char	ft_42sh_parsing_litter_e(register unsigned char litter);
unsigned char	ft_42sh_parsing_litter_e_f(register unsigned char litter);

size_t			ft_42sh_pipe_test(register t_main_42sh *array,
unsigned char **out, register unsigned char *end, register size_t b_empty);
size_t			ft_42sh_pipe_pre(register t_main_42sh *array,
register t_in_42sh *list, unsigned char **out, register unsigned char *end);
size_t			ft_42sh_pipe_next(register t_main_42sh *array,
unsigned char **out, register unsigned char *end);
uintmax_t		ft_42sh_pipe_next_count(register t_main_42sh *array,
unsigned char *b, register unsigned char *end);
void			ft_42sh_pipe_run(register t_main_42sh *array,
register t_jobs_42sh *list);
void			ft_42sh_pipe_left(register t_main_42sh *array,
register t_jobs_42sh *list);
void			ft_42sh_pipe_right(register t_main_42sh *array,
register t_jobs_42sh *jobs);
void			ft_42sh_pipe_fun(register t_main_42sh *array,
register t_jobs_42sh *jobs, char **lp_arg,
void (*f)(register t_main_42sh *array, register char **lp_arg));
size_t			ft_42sh_pipe_test_fd(register t_main_42sh *array,
register int fd);
size_t			ft_42sh_pipe_test_fd_dsp(register t_main_42sh *array,
register int fd, void *name);

void			ft_42sh_replase_cmd(register t_main_42sh *array,
register unsigned char *dest, unsigned char *b, register unsigned char *e);
size_t			ft_42sh_replase_cmd_count(register t_main_42sh *array,
unsigned char **out, register unsigned char *end, register size_t count);
void			ft_42sh_replase_arg(register t_main_42sh *array,
register unsigned char *dest, unsigned char *b, register unsigned char *e);
size_t			ft_42sh_replase_arg_count(register t_main_42sh *array,
unsigned char **out, register unsigned char *end, register size_t count);

void			ft_42sh_signal_initilization(void);

void			ft_42sh_str(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *litter,
t_add_litter_42sh *in);
void			ft_42sh_str_delete(register t_main_42sh *array,
register t_in_42sh *list, register char *e, register size_t count_litter);
size_t			ft_42sh_str_test_read(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b, register size_t count);
void			ft_42sh_str_add(register t_main_42sh *array,
register char *str, register char *end, uint_fast8_t corr);
void			ft_42sh_str_full_home(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_str_full_end(register t_main_42sh *array,
register t_in_42sh *list);

void			ft_42sh_dsp_start(register t_main_42sh *array);
void			ft_42sh_dsp_err_msg(register t_main_42sh *array,
register char *str);
uintmax_t		ft_42sh_dsp_position(void);
void			ft_42sh_dsp_err_msg_add(register t_main_42sh *array,
register void *str, register char *add);
void			ft_42sh_dsp_err_msg_add_n(register t_main_42sh *array,
register void *str, register void *add, register size_t n);
void			ft_42sh_dsp_raw(register t_main_42sh *array,
register size_t raw);
void			ft_42sh_dsp_data(register t_main_42sh *array,
register size_t count_litter);
void			ft_42sh_dsp_default_line(register t_main_42sh *array,
register t_in_42sh *list);
size_t			ft_42sh_dsp_caret_raw_up(register t_main_42sh *array,
register t_in_42sh *list);
size_t			ft_42sh_dsp_caret_raw_down(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_dsp_caret_left(register t_main_42sh *array,
register t_in_42sh *list, register size_t count_litter, register size_t count);
void			ft_42sh_dsp_caret_right(register t_main_42sh *array,
register t_in_42sh *list, register size_t count_litter, register size_t count);
void			ft_42sh_dsp_clear_auto(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_dsp_clear_select(register t_main_42sh *array,
register t_in_42sh *list);

t_jobs_42sh		*ft_42sh_jobs_create_add_list(register t_main_42sh *array,
register char **lp_arg, register t_all_cmd_42sh **spl, uintmax_t count);
void			ft_42sh_jobs_free_list_count(register t_main_42sh *array,
register t_jobs_42sh *jobs);
void			ft_42sh_jobs_free_list_count_err(register t_main_42sh *array,
register t_jobs_42sh *jobs);
void			ft_42sh_jobs_fd_close(register t_jobs_42sh *jobs,
uint_fast8_t b_pipe_close);
void			ft_42sh_jobs_fd_close_future(register t_jobs_42sh *jobs);

#endif
