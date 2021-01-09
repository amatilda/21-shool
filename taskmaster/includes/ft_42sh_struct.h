/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:24:38 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_STRUCT_H
# define FT_42SH_STRUCT_H

# include "pguitar/ft_42sh_pguitar_struct.h"

typedef struct				s_shield_out_42sh
{
	size_t					count;
	size_t					count_litter;
}							t_shield_out_42sh;

typedef struct				s_past_sort_42sh
{
	void					*first;
	void					*center;
	void					*last;
}							t_past_sort_42sh;

typedef struct				s_std_key_42sh
{
	char					*lp_key;
	size_t					key_count;
	size_t					key_litter;
	struct s_std_key_42sh	*prev;
	struct s_std_key_42sh	*next;
}							t_std_key_42sh;

typedef struct				s_all_cmd_42sh
{
	t_std_key_42sh			std;
	char					add_litter;
	void					*path;
	void					*path_hash;
	size_t					count_cmd;
	uint_fast8_t			b_type;
	char					key[1];
}							t_all_cmd_42sh;

typedef struct				s_env_42sh
{
	t_std_key_42sh			std;
	char					*lp_value;
	size_t					value_count;
	size_t					value_litter;
	uint_fast8_t			b_type;
	size_t					number;
	char					key[1];
}							t_env_42sh;

typedef struct				s_slesh_42sh
{
	size_t					count;
	size_t					count_litter;
}							t_slesh_42sh;

typedef struct				s_in_42sh
{
	char					*lp_current;
	char					*lp_b;
	size_t					max;
	size_t					count;
	size_t					count_litter;
	size_t					count_litter_current;
	struct s_in_42sh		*prev;
	struct s_in_42sh		*next;
	char					*lp_b_dup;
	size_t					max_dup;
	size_t					count_dup;
	size_t					count_litter_dup;
	size_t					count_litter_current_dup;
	size_t					slesh_current;
	size_t					slesh_max;
	size_t					slesh_max_dup;
	t_slesh_42sh			**spl_slesh;
	t_slesh_42sh			**spl_slesh_dup;
}							t_in_42sh;

typedef struct				s_in_main_42sh
{
	t_in_42sh				*in_current;
	t_in_42sh				*in_last;
	t_in_42sh				*in_first;
	uint_fast8_t			in_count;
}							t_in_main_42sh;

typedef struct				s_msg_42sh
{
	char					*pre_msg;
	char					*pre_msg_sp;
	uint_fast8_t			pre_msg_litter;
	char					*hrdc;
	size_t					hrdc_lit;
}							t_msg_42sh;

typedef struct				s_env_main_42sh
{
	t_past_sort_42sh		root;
	size_t					count_env;
	size_t					count_local;
	t_env_42sh				*exit_status;
	t_env_42sh				*shell_pid;
	t_env_42sh				*last_pid;
	unsigned char			*lp_end_exp;
	size_t					n_exp;
	size_t					b_exp_err;
	uint_fast8_t			offset_auto;
}							t_env_main_42sh;

typedef struct				s_pwd_42sh
{
	t_string				path;
	t_string				prev_path;
	unsigned char			*path_view;
	t_shield_out_42sh		sh_path_view;
	char					**spl_cd;
}							t_pwd_42sh;

typedef struct				s_pipe_42sh
{
	uint_fast16_t			b_flag;
	int						fd_1;
	int						fd_2;
	void					*lp_heredok_b;
	void					*lp_heredok_e;
	uint_fast8_t			b_heredok;
}							t_pipe_42sh;

typedef struct				s_exp_set_42sh
{
	size_t					n;
	struct s_exp_set_42sh	*next;
	unsigned char			lp[1];
}							t_exp_set_42sh;

typedef struct				s_add_exp_42sh
{
	void					*value;
	void					*value_end;
	uint_fast8_t			b_type;
}							t_add_exp_42sh;

typedef struct				s_exit_pars_42sh
{
	uint_fast8_t			error;
	unsigned char			*lp;
}							t_exit_pars_42sh;

typedef struct				s_jobs_42sh
{
	int						fds[(FD_MAX_SUPPORT_42SH + 1) * 2];
	pid_t					pipe_pid[FD_MAX_SUPPORT_42SH + 1];
	size_t					id;
	size_t					b_pipe_fd;
	unsigned char			*cmd;
	int						stat_loc;
	uint_fast8_t			count_pipes;
	uint_fast8_t			b_type;
	uint_fast8_t			error;
	size_t					b_flag_close;
	size_t					b_fd_left;
	size_t					b_fd_right;
	pid_t					pid;
	pid_t					pid_view;
	size_t					count;
	void					*path;
	char					**lp_arg;
	struct s_jobs_42sh		*prev;
	struct s_jobs_42sh		*next;
	struct s_jobs_42sh		*prev_id;
	struct s_jobs_42sh		*next_id;
	size_t					n;
	int						fd_pipe;
	t_exp_set_42sh			*exp_set;
	t_exp_set_42sh			*exps_set;
	t_exp_set_42sh			*exps_set_end;
	size_t					exps_loop;
	t_exp_set_42sh			*exps_set_tmp;
	t_pipe_42sh				pipe[1];
}							t_jobs_42sh;

typedef struct				s_process_42sh
{
	unsigned char			*lp_cmd;
	char					**lp_msg_sgnl;
	t_jobs_42sh				*jobs_last;
	t_jobs_42sh				*jobs_cut;
	t_jobs_42sh				*jobs_current;
	t_jobs_42sh				*jobs_minus;
	t_jobs_42sh				*jobs_plus;
	t_past_sort_42sh		jb;
	t_past_sort_42sh		jb_id;
	pid_t					pid_main;
	pid_t					pid_fork;
	pid_t					pid_not_fork;
	int						even_fds[1 * 2];
	pid_t					pid_grup;
	uint_fast8_t			b_auto_view;
	size_t					count_runing;
	t_exit_pars_42sh		exit_pars;
}							t_process_42sh;

typedef struct				s_auto_42sh
{
	t_past_sort_42sh		all_cmd;
	t_all_cmd_42sh			**spl_all_cmd;
	size_t					count_all;
	size_t					max_litter;
	size_t					view_raw;
	size_t					b_limit;
	size_t					b_auto;
	size_t					auto_cmd;
	size_t					auto_litter_len;
	size_t					auto_len;
	char					spec_sym;
	uint_fast8_t			b_view;
	t_all_cmd_42sh			**auto_spl;
	size_t					count_new_alias;
}							t_auto_42sh;

typedef struct				s_select_42sh
{
	unsigned char			*b;
	unsigned char			*e;
	size_t					count_litter;
	void					*lp_clipboard;
	size_t					clipboard_count;
}							t_select_42sh;

typedef struct				s_alias_42sh
{
	size_t					offset;
	size_t					offset_end;
	size_t					n;
	struct s_alias_42sh		*next;
	unsigned char			restore[1];
}							t_alias_42sh;

typedef struct				s_dq_42sh
{
	t_in_42sh				*in_dquote;
	unsigned char			dquote;
	void					*hrdoc_cmp_lp;
	size_t					hrdoc_cmp_count;
	uint8_t					b_hrdoc;
	void					*hrdoc_next_lp;
	size_t					hrdoc_next_slesh;
	void					*hrdoc_start_lp;
	t_alias_42sh			*first_alias;
	t_alias_42sh			*last_alias;
	size_t					slesh_alias;
}							t_dq_42sh;

typedef struct				s_sh_42sh
{
	char					**lp_arg;
	unsigned char			*path;
	size_t					count_path;
	unsigned char			*lp_sh;
	unsigned char			*lp_sh_e;
	unsigned char			*lp_cmd;
}							t_sh_42sh;

typedef struct				s_logins_42sh
{
	t_std_key_42sh			std;
	unsigned char			*home_dir;
	size_t					home_dir_count;
}							t_logins_42sh;

typedef struct				s_home_42sh
{
	char					*lp_home;
	size_t					count_home;
	void					*lp_home_tmp_b;
	void					*lp_home_tmp_e;
	t_logins_42sh			*list;
}							t_home_42sh;

typedef struct				s_task_main
{
	pthread_t				thread;
	pthread_mutex_t			mutex;
	size_t					count_read;
	void					*path_file;
	void					*task_list;
	size_t					b_init;
	size_t					b_delete;
	size_t					b_reload;
	size_t					b_cmd;
}							t_task_main;

typedef struct				s_glb_list
{
	struct s_glb_list		*prev;
	struct s_glb_list		*next;
	char					name[1];
}							t_glb_list;

typedef struct				s_glb_main
{
	t_glb_list				*first;
	t_glb_list				*last;
}							t_glb_main;

typedef struct				s_main_42sh
{
	t_pguitar_42sh			pguitar;
	void					*draynor;
	t_task_main				task;
	t_dq_42sh				dq;
	t_process_42sh			pr;
	t_in_main_42sh			in;
	t_msg_42sh				msg;
	t_env_main_42sh			env;
	t_auto_42sh				auto_;
	t_auto_42sh				auto_file;
	t_auto_42sh				auto_env;
	t_select_42sh			slc;
	t_pwd_42sh				pwd;
	t_home_42sh				home;
	struct winsize			ws;
	t_sh_42sh				sh;
	t_past_sort_42sh		login;
	t_glb_main				glb;
	struct termios			tty;
	struct termios			tty_change;
	t_auto_42sh				*lp_auto;
	char					**lp_spl_path;
	uintmax_t				litter_save[1];
	uintmax_t				litter[BUFFER_LITTER_42SH];
	uint_fast8_t			b_signo;
	uint_fast8_t			b_read;
	uint_fast8_t			b_hash;
	uint_fast8_t			b_quest_exit;
	uint_fast8_t			b_location;
	int						b_tty_out_in;
	size_t					count_tty_out_in;
	t_write_buff			out;
	t_write_buff			err;
	size_t					b_fd_close;
	uint_fast8_t			b_mode;
	char					buff_err[BUFFER_ERR_42SH];
	char					buff_out[BUFFER_OUT_42SH];
	uint32_t				lp_crc32_mirror[CRC32_DEPTH_42SH * 0x100];
}							t_main_42sh;

extern t_main_42sh			*g_lp_array;

typedef struct				s_add_litter_42sh
{
	size_t					count;
	size_t					count_litter;
	uint_fast8_t			correction;
}							t_add_litter_42sh;

typedef struct				s_replase_in_pars_42sh
{
	unsigned char			*e;
	t_jobs_42sh				*jobs;
	size_t					pipe_count;
	unsigned char			*start;
}							t_replase_in_pars_42sh;

typedef struct				s_replase_in_exp_42sh
{
	unsigned char			*key;
	size_t					key_count;
	t_env_42sh				*env;
}							t_replase_in_exp_42sh;

typedef struct				s_replase_in_hrdc_42sh
{
	uint_fast8_t			b_test;
}							t_replase_in_hrdc_42sh;

typedef struct				s_replase_in_42sh
{
	t_main_42sh				*array;
	size_t					b_mode;
	t_replase_in_pars_42sh	prs;
	t_replase_in_exp_42sh	exp;
	t_replase_in_hrdc_42sh	hrdc;
}							t_replase_in_42sh;

typedef struct				s_overlow_byte_in_42sh
{
	char					*repl;
	size_t					n_repl;
}							t_overlow_byte_in_42sh;

#endif
