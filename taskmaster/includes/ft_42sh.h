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
# include <signal.h>
# include <pwd.h>
# include <pthread.h>

# include <stdio.h>

# include "ft_42sh_define.h"
# include "ft_42sh_struct.h"
# include "pguitar/ft_42sh_pguitar.h"

void			*ft_42sh_glb(register t_main_42sh *array,
register const char *src);
char			**ft_42sh_glb_args_parser(register t_main_42sh *array,
register char **args, register size_t count);
void			*ft_42sh_glb_parser(register t_main_42sh *array,
register unsigned char *b, size_t *n);
size_t			ft_42sh_glb_auto_cmd(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *str, register size_t n);
void			ft_42sh_glb_auto_other(register t_main_42sh *array,
register t_in_42sh *list, register char *start, register char *end);

size_t			ft_42sh_calc_test(register t_main_42sh *array,
unsigned char **out, register unsigned char *e);
size_t			ft_42sh_calc_count(t_replase_in_42sh *in_rep,
unsigned char **s, unsigned char **out, register unsigned char *e);
void			*ft_42sh_calc(t_replase_in_42sh *in_rep,
register unsigned char *dest, unsigned char **out, register unsigned char *e);

void			ft_42sh_auto_create(register t_main_42sh *array);
void			*ft_42sh_auto_cmd_expension(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e, register size_t b_test);
void			ft_42sh_auto_create_array(register t_main_42sh *array,
register t_all_cmd_42sh *list, register size_t count);
void			*ft_42sh_auto_add_list(register t_main_42sh *array,
register char *lp_key, char add_litter);
void			ft_42sh_auto_free_list(register t_all_cmd_42sh *list);
void			ft_42sh_auto_free_all_cmd(register t_main_42sh *array);
void			ft_42sh_auto_free_all_cmd_full(register t_main_42sh *array);
void			ft_42sh_auto_toogle(register t_main_42sh *array);
void			ft_42sh_auto_cmd(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *str, register size_t n);
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
void			*ft_42sh_auto_sort_paste(register t_main_42sh *array,
register char *lp_key, register void *str, uint_fast8_t b_type);

void			ft_42sh_dsp_start(register t_main_42sh *array);
void			ft_42sh_dsp_err_msg(register t_main_42sh *array,
register char *str);
uintmax_t		ft_42sh_dsp_position(void);
void			ft_42sh_dsp_err_msg_add_n(register t_main_42sh *array,
register void *str, register void *add, register size_t n);
void			ft_42sh_dsp_err_msg_adds(register t_main_42sh *array,
register char *str, register void *add, register void *adds);
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
void			*ft_42sh_dsp_err_script(register t_main_42sh *array,
register void *msg, register void *cmd, register size_t n_cmd);
void			*ft_42sh_dsp_err_standart(register void *msg,
register void *cmd, register size_t n_cmd);

void			ft_42sh_dq(register t_main_42sh *array,
register t_in_42sh *list);
unsigned char	ft_42sh_dq_test(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b,
register unsigned char *e);
unsigned char	ft_42sh_dq_test_sintax(register t_main_42sh *array,
unsigned char **out, register unsigned char *e);
unsigned char	*ft_42sh_dq_test_word(register t_main_42sh *array,
unsigned char *b, register unsigned char *e, register uint_fast8_t b_test);
void			ft_42sh_dq_skip_dq(unsigned char **out,
register unsigned char *e, register unsigned char lit);
unsigned char	ft_42sh_dq_test_hrdc(register t_main_42sh *array,
register t_in_42sh *list, unsigned char **b, register unsigned char *e);
void			ft_42sh_dq_paste(register t_main_42sh *array);
void			ft_42sh_dq_cut(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_dq_split(register t_in_42sh *list,
register size_t count);
t_slesh_42sh	**ft_42sh_dq_split_dup(register t_slesh_42sh **spl,
register size_t n);
void			ft_42sh_dq_split_add_empty(register t_in_42sh *list,
register t_slesh_42sh **spl_slesh);
void			ft_42sh_dq_alias_spl(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_dq_unalias(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_dq_unalias_split_re(register t_main_42sh *array,
register t_in_42sh *list);

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
void			ft_42sh_key_clear(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_key_int(register t_main_42sh *array,
register t_in_42sh *list);

size_t			ft_42sh_dq_test_sintax_exp(register t_main_42sh *array,
unsigned char **src, register unsigned char *e);
unsigned char	**ft_42sh_exp_pars_exp_skip(unsigned char **out,
register unsigned char *e);
char			**ft_42sh_exp_split_env(register t_main_42sh *array,
size_t b_exit);
void			*ft_42sh_exp_parsing_value(register t_main_42sh *array,
register t_env_42sh *list, register unsigned char *dest,
register size_t b_mode);
size_t			ft_42sh_exp_parsing_value_count(register t_main_42sh *array,
register t_env_42sh *list, register size_t b_mode);
size_t			ft_42sh_exp_parsing_count(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **src, register unsigned char *end);
unsigned char	*ft_42sh_exp_parsing(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char **src,
register unsigned char *end);
void			*ft_42sh_exp_test_exp(register unsigned char *b,
register unsigned char *e);
t_env_42sh		*ft_42sh_exp_add(register t_main_42sh *array,
register unsigned char *key, register unsigned char *key_end,
register t_add_exp_42sh *in);
void			ft_42sh_exp_del(register t_main_42sh *array,
register t_past_sort_42sh *root, register t_env_42sh *list);
void			ft_42sh_exp_start(register t_main_42sh *array,
register char **env);
void			*ft_42sh_exp_name(register unsigned char *b,
register unsigned char *e);
void			*ft_42sh_exp_name_special(register unsigned char *b,
register unsigned char *e);
size_t			ft_42sh_exp_shield(register unsigned char *value,
register unsigned char *value_e);
void			ft_42sh_exp_corection(register t_replase_in_42sh *in);

void			ft_42sh_init(register t_main_42sh *array, register int argc,
register char **argv, register char **env);
void			ft_42sh_init_script(register t_main_42sh *array,
register char **env, register char **lp_arg);

t_in_42sh		*ft_42sh_list_in_create(register t_main_42sh *array,
register size_t max);
t_in_42sh		*ft_42sh_list_in_create_dup(register t_main_42sh *array,
register t_in_42sh *list);
t_in_42sh		*ft_42sh_list_in_create_dup_full(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_list_in_free(register t_in_42sh *list);
void			ft_42sh_list_in_free_all(register t_main_42sh *array);
void			ft_42sh_list_in_free_all_save(register t_main_42sh *array);
void			ft_42sh_list_in_open(register t_main_42sh *array);
void			ft_42sh_list_in_default(register t_main_42sh *array,
register t_in_42sh *list);
void			ft_42sh_list_in_last(register t_main_42sh *array);
void			ft_42sh_list_in_dup(register t_in_42sh *list);
void			ft_42sh_list_in_dup_restore(register t_main_42sh *array);
void			ft_42sh_list_in_limit(register t_main_42sh *array);
void			ft_42sh_list_in_overlow_byte(register t_in_42sh *list,
register t_overlow_byte_in_42sh *rep, register unsigned char *b,
register size_t n_org);

int				ft_42sh_list_sort_paste(register t_past_sort_42sh *root,
register t_std_key_42sh *list, void (*fn_free)(register void *));
void			ft_42sh_list_fun(register t_past_sort_42sh *root,
void (*f)(register void *));
void			ft_42sh_list_cut(register t_past_sort_42sh *root,
register t_std_key_42sh *list);
void			*ft_42sh_list_find_key(t_past_sort_42sh *root,
register void *key, register size_t n);

size_t			ft_42sh_exe(register t_main_42sh *array,
register size_t b_test);
size_t			ft_42sh_exe_wait(register t_main_42sh *array,
register t_jobs_42sh *jobs, t_jobs_42sh *jobs_cl);

void			ft_42sh_cm_exit(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_exit_fun(register t_main_42sh *array,
register size_t exit_code);
void			ft_42sh_cm_export(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_echo(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_cd(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_set(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_unset(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_false(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_true(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_type(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_jobs(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_bg(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_fg(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_hash(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_cm_test(register t_main_42sh *array,
register char **lp_arg);

void			ft_42sh_parsing(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char litter);
void			ft_42sh_parsing_grup(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char litter);
unsigned char	ft_42sh_parsing_test_pipe(register unsigned char *b,
register unsigned char *e, unsigned char old);
unsigned char	ft_42sh_parsing_test_next(unsigned char **out,
register unsigned char *e, register unsigned char dquote, unsigned char old);
void			*ft_42sh_parsing_cmd(register t_main_42sh *array,
register t_jobs_42sh *jobs, unsigned char **b, register unsigned char *e);
void			ft_42sh_parsing_arg(register t_main_42sh *array,
register t_jobs_42sh *jobs, unsigned char **out, register unsigned char *end);
void			ft_42sh_parsing_arg_skip(register t_main_42sh *array,
unsigned char **out, register unsigned char *end);
void			ft_42sh_parsing_path(register t_string *ret,
register t_string *root, register char *str, register size_t n);
size_t			ft_42sh_parsing_path_test(register char *b, register char *e);
size_t			ft_42sh_parsing_end(register t_main_42sh *array,
unsigned char **out, register unsigned char *e,
unsigned char (*f)(register unsigned char *b, register unsigned char *e));
void			*ft_42sh_parsing_sp(register unsigned char *b,
register unsigned char *e);
size_t			ft_42sh_parsing_litter_n(register const char *s,
register const char *e);
size_t			ft_42sh_parsing_litter(register const char *s);
unsigned char	ft_42sh_parsing_litter_e_f(register unsigned char *b,
register unsigned char *e);
void			*ft_42sh_parsing_litter_e_f_l(register unsigned char *b,
register unsigned char *e);
size_t			ft_42sh_parsing_litter_e_f_v(register unsigned char *b,
register unsigned char *e);
unsigned char	ft_42sh_parsing_litter_e(register unsigned char *b,
register unsigned char *e);
void			*ft_42sh_parsing_litter_e_l(register unsigned char *b,
register unsigned char *e);
size_t			ft_42sh_parsing_litter_e_v(register unsigned char *b,
register unsigned char *e);

size_t			ft_42sh_pattern(unsigned char *b, unsigned char *e,
unsigned char *b_ptt, unsigned char *e_ptt);

char			*ft_42sh_path_join(register char const *s1,
register char const *s2);
void			ft_42sh_path_canon(register t_string *ret,
register unsigned char *str, register size_t n);
void			ft_42sh_path_view(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e);
void			ft_42sh_path_logins(register t_main_42sh *array);
void			ft_42sh_path_logins_list_free(register t_main_42sh *array);

size_t			ft_42sh_pipe_pre(register t_main_42sh *array,
register t_in_42sh *list, unsigned char *out, register unsigned char *end);
size_t			ft_42sh_pipe_next(register t_main_42sh *array,
unsigned char **out, register unsigned char *end);
uintmax_t		ft_42sh_pipe_next_count(register t_main_42sh *array,
unsigned char *b, register unsigned char *end);
void			ft_42sh_pipe_run(register t_main_42sh *array,
register t_jobs_42sh *list);
size_t			ft_42sh_pipe_left(register t_main_42sh *array,
register t_jobs_42sh *list);
size_t			ft_42sh_pipe_right(register t_main_42sh *array,
register t_jobs_42sh *jobs);
size_t			ft_42sh_pipe_test_fd(register t_main_42sh *array,
register int fd);
size_t			ft_42sh_pipe_test_fd_dsp(register t_main_42sh *array,
register int fd, void *name);
void			ft_42sh_pipe_find(register t_main_42sh *array,
register t_jobs_42sh *jobs, register int *fds, register int fd);
size_t			ft_42sh_pipe_find_count(register t_pipe_42sh *pipe_b,
register t_pipe_42sh *pipe_e, register int fd);

void			ft_42sh_replase_hrdc_name(register t_main_42sh *array,
register unsigned char *dest, unsigned char *b, register unsigned char *e);
size_t			ft_42sh_replase_hrdc_name_count(register t_main_42sh *array,
unsigned char **out, register unsigned char *e);
size_t			ft_42sh_replase_hrdc_count(register t_main_42sh *array,
unsigned char *b, register unsigned char *e);
void			ft_42sh_replase_hrdc(register t_main_42sh *array,
register unsigned char *dest, unsigned char *b, register unsigned char *e);
void			ft_42sh_replase_skip(register t_main_42sh *array,
unsigned char **out, register unsigned char *e);
void			ft_42sh_replase(register t_replase_in_42sh *in,
unsigned char *dest, unsigned char *b, register unsigned char *e);
size_t			ft_42sh_replase_count(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **out, register unsigned char *e);
void			ft_42sh_replase_exp(register t_replase_in_42sh *in,
register unsigned char *dest, unsigned char *b, register unsigned char *e);
size_t			ft_42sh_replase_exp_count(register t_replase_in_42sh *in,
unsigned char **s, unsigned char **out, register unsigned char *e);

void			ft_42sh_signal_initilization_script(register
t_main_42sh *array);
void			ft_42sh_signal_initilization(register t_main_42sh *array);
void			ft_42sh_signal_default(register t_main_42sh *array,
register t_jobs_42sh *jobs);

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
void			*ft_42sh_str_shield(register unsigned char *b,
register unsigned char *e, register uint_fast8_t b_test,
register t_shield_out_42sh *lp);
void			*ft_42sh_str_shield_(register unsigned char *b,
register unsigned char *e, register uint_fast8_t b_test,
register t_shield_out_42sh *lp);

void			ft_42sh_jobs_list_create_cmd(register t_main_42sh *array,
register unsigned char *b, register unsigned char *end);
t_jobs_42sh		*ft_42sh_jobs_create_add_list(register t_main_42sh *array,
unsigned char *b, register unsigned char *e, size_t n);
void			ft_42sh_jobs_free_list_count(register t_main_42sh *array,
register t_jobs_42sh *jobs);
void			ft_42sh_jobs_free_list_count_err(register t_main_42sh *array,
register t_jobs_42sh *jobs);
void			ft_42sh_jobs_fd_close(register t_jobs_42sh *jobs,
uint_fast8_t b_pipe_close);
void			ft_42sh_jobs_fd_close_future(register t_jobs_42sh *jobs);
t_jobs_42sh		*ft_42sh_jobs_cut(register t_main_42sh *array,
register t_jobs_42sh *jobs);
void			ft_42sh_jobs_clean(register t_main_42sh *array);
void			ft_42sh_jobs_msg(register t_main_42sh *array,
register t_jobs_42sh *jobs, register size_t b_test);
void			ft_42sh_jobs_set_current(register t_main_42sh *array);
void			ft_42sh_jobs_list_set_type(register t_jobs_42sh *jobs,
register t_all_cmd_42sh **spl, register void *cmd);
void			ft_42sh_jobs_free_all(register t_main_42sh *array);
void			ft_42sh_jobs_up(register t_main_42sh *array,
register t_jobs_42sh *jobs);
void			ft_42sh_jobs_set_err(register t_main_42sh *array,
register void *msg, register void *cmd, uint_fast8_t error);
void			ft_42sh_jobs_set_err_n(register t_main_42sh *array,
register void *msg, register void *cmd, register size_t n);
size_t			ft_42sh_jobs_exit_test(register t_main_42sh *array,
register char **lp_arg);
void			ft_42sh_jobs_exit_clear(register t_main_42sh *array,
register t_in_42sh *list, register uintmax_t litter);

void			ft_42sh_sh(register t_main_42sh *array,
register t_jobs_42sh *jobs, register char **env_spl, register char **lp_arg);
void			*ft_42sh_sh_comment(register t_main_42sh *array,
register unsigned char *b, register unsigned char *e);

void			ft_42sh_msg_change(register t_main_42sh *array,
register unsigned char litter, unsigned char litter_prev);
void			ft_42sh_read(register t_main_42sh *array);
void			**ft_42sh_spl_find(register void **spl,
register size_t max_spl, register char *str, register size_t n);
void			ft_42sh_exit(register size_t exit_code,
register void *name_file, register const char *name_function,
register size_t line);
void			ft_42sh_free_exit(register t_main_42sh *array);
void			ft_42sh_free_script(register t_main_42sh *array);
int				ft_42sh_stub_ioctl(register t_main_42sh *array,
register unsigned long number, register void *lp);

void			ft_42sh_task_init(register t_main_42sh *array,
int argc, char **argv);
void			ft_42sh_task_deinit(register t_main_42sh *array);
void			ft_42sh_task_delete(register t_main_42sh *array);
void			ft_42sh_task_add_bultin(register t_main_42sh *array,
void (*f)(register t_main_42sh *array,
register char *lp_key, register void *str, uint_fast8_t b_type));

#endif
