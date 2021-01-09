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
# include "conf_reader.h"

# define TASK_EXIT_FORK_STATUS_FAIL_DUP						255
# define TASK_EXIT_FORK_STATUS_FAIL_ENV						254
# define TASK_EXIT_FORK_STATUS_FAIL_EXECVE					253
# define TASK_EXIT_FORK_STATUS_FAIL_PTRACE					252
# define TASK_EXIT_FORK_STATUS_FAIL_CHDIR					251

typedef	struct			s_task_find_cmd
{
	char				*cmd;
	void				(*f)(register t_main_42sh *array,
	register char **lp_arg);
}						t_task_find_cmd;

typedef	struct			s_task_load_fd
{
	int					fd_null;
	int					fd_out;
	int					fd_err;
	int					retries;
	t_jobs				*jobs_b;
}						t_task_load_fd;

typedef	struct			s_task_status_total
{
	size_t				critical;
	size_t				faill;
	size_t				starting;
	size_t				runing;
	size_t				stop;
	size_t				completed;
	size_t				completed_falled;
	size_t				quits;
	size_t				not_auto_start;
}						t_task_status_total;

t_log					*get_log(void);

void					ft_42sh_task_set_fd(register t_main_42sh *array);

void					ft_42sh_task_load(register t_main_42sh *array,
register t_list *task_list);
void					ft_42sh_task_load_singl(register t_main_42sh *array,
register t_list *task_list, register t_task *task,
register t_jobs *jobs_b);
size_t					ft_42sh_task_load_start(register t_main_42sh *array,
register t_task *task, register t_task_load_fd *fds, register char **arg);
size_t					ft_42sh_task_load_start_singl(register
t_main_42sh *array, register t_task *task, register t_task_load_fd *fds,
register char **arg);
void					ft_42sh_task_load_start_fork(register t_main_42sh
*array, register t_task *task, register t_task_load_fd *fds,
register char **arg);

char					**ft_42sh_task_test_path(register t_main_42sh *array,
register t_task *task, register void *b, register size_t n);
size_t					ft_42sh_task_test_path_availability(register char *cmd);
void					*ft_42sh_task_test_path_error_log(register t_task *task,
register void *b, uint8_t b_test, register char **arg);
t_all_cmd_42sh			**ft_42sh_task_test_path_test_cmd(register
t_main_42sh *array, register t_task *task, register char *cmd,
register size_t n);
char					**ft_42sh_task_arguments(register unsigned char *dest,
register unsigned char *b, unsigned char *e);
size_t					ft_42sh_task_arguments_count(register
unsigned char *dest, unsigned char *b, unsigned char **end);

size_t					ft_42sh_task_load_start_error(register t_task *task,
register char *str, register char *name, register size_t n);
size_t					ft_42sh_task_load_start_critical(register t_task *task,
register char *str);

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
void					ft_42sh_task_cmd_status(register t_main_42sh *array,
register char **lp_arg);

void					ft_42sh_task_cmd_status_col(register t_main_42sh *array,
t_task *task);
size_t					ft_42sh_task_cmd_status_pre_test(register
t_main_42sh *array);
void					ft_42sh_task_cmd_status_pre_table(register
t_main_42sh *array);
void					ft_42sh_task_cmd_status_pre_total(register
t_main_42sh *array);

size_t					ft_42sh_cm_export_set_task(register t_main_42sh *array,
register char **lp_arg);

void					ft_42sh_task_upd_status(register t_main_42sh *array);
void					ft_42sh_task_upd_status_add(register t_jobs *jobs_b,
register t_task *task, register time_t time_cur, int status);
void					ft_42sh_task_upd_status_time(register t_jobs *jobs_b,
register time_t time_cur);

void					ft_42sh_task_thread(register t_main_42sh *array);
size_t					ft_42sh_task_thread_init(register t_main_42sh *array);
void					ft_42sh_task_thread_deinit(register
t_main_42sh *array);
void					ft_42sh_task_thread_share(register
t_main_42sh *array);
void					ft_42sh_task_thread_excluze(register
t_main_42sh *array);
void					ft_42sh_task_thread_unshare(register
t_main_42sh *array);
void					ft_42sh_task_thread_unexcluze(register
t_main_42sh *array);

void					ft_42sh_task_cmd_pause(register t_main_42sh *array,
register char **lp_arg);
void					ft_42sh_task_cmd_pause_all(register t_task *task,
time_t time_cur);
void					ft_42sh_task_cmd_pause_kill(register t_task *task,
register t_jobs *jobs_b, time_t time_cur, int status);

void					ft_42sh_task_cmd_resume(register t_main_42sh *array,
register char **lp_arg);
void					ft_42sh_task_cmd_resume_all(register t_task *task,
time_t time_cur);
void					ft_42sh_task_cmd_resume_kill(register t_task *task,
register t_jobs *jobs_b, time_t time_cur, int status);

void					ft_42sh_task_cmd_stop(register t_main_42sh *array,
register char **lp_arg);
void					ft_42sh_task_cmd_stop_all(register t_task *task,
time_t time_cur);
void					ft_42sh_task_cmd_stop_kill(register t_task *task,
register t_jobs *jobs_b, time_t time_cur);

void					ft_42sh_task_cmd_run(register t_main_42sh *array,
register char **lp_arg);
void					ft_42sh_task_cmd_run_kill(register t_main_42sh *array,
register t_list *task_list, register t_task *task, register t_jobs *jobs_b);
void					ft_42sh_task_cmd_run_all(register t_main_42sh *array,
register t_list *task_list, register t_task *task);

size_t					ft_42sh_task_init_path_file(register t_main_42sh *array,
register void *str, char *type);

void					ft_42sh_task_auto(register t_main_42sh *array);

size_t					ft_42sh_task_cmd_other_to_many(register
t_main_42sh *array, register char **lp_arg, register void *name);

void					ft_42sh_task_cmd_delete_wait(register
t_main_42sh *array);

void					*ft_42sh_task_cmd_other_load_test(register
t_main_42sh *array, register char **lp_arg, void *name);

void					ft_42sh_task_cmd_reload_stop(register
t_main_42sh *array, register t_list *task_list_old,
register t_list *task_list_new);
void					ft_42sh_task_cmd_reload_move_jobs(register
t_list *task_list_old, register t_list *task_list_new);
void					ft_42sh_task_cmd_reload_start(register
t_main_42sh *array, register t_list *task_list_new);
void					ft_42sh_task_load_one(register t_main_42sh *array,
register t_list *task_list);

void					ft_42sh_task_cmd_restart(register t_main_42sh *array,
register char **lp_arg);

void					ft_42sh_task_load_clean(register t_task_load_fd *fds,
char ***arg);

size_t					ft_42sh_task_load_start_fd(register t_task *task,
register t_task_load_fd *fds);

size_t					ft_42sh_task_load_on_start(t_jobs *jobs_b,
t_jobs *jobs_e, register t_task *task);

#endif
