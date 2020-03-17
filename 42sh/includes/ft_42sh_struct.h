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
	char					key[];
}							t_all_cmd_42sh;

typedef struct				s_env_42sh
{
	t_std_key_42sh			std;
	char					*lp_value;
	size_t					value_count;
	size_t					value_litter;
	uint_fast8_t			b_type;
	size_t					number;
	char					key[];
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
}							t_msg_42sh;

typedef struct				s_env_main_42sh
{
	t_past_sort_42sh		root;
	size_t					count_env;
	size_t					count_local;
	t_env_42sh				*exit_status;
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
	t_slesh_42sh			**lp_heredok_spl;
	t_slesh_42sh			**lp_heredok_spl_end;
}							t_pipe_42sh;

typedef struct				s_exp_set_42sh
{
	size_t					n;
	struct s_exp_set_42sh	*next;
	unsigned char			lp[];
}							t_exp_set_42sh;

typedef struct				s_exit_pars_42sh
{
	uint_fast8_t			error;
	unsigned char			*lp;
}							t_exit_pars_42sh;

typedef struct				s_jobs_42sh
{
	int						fds[(PIPE_MAX_SUPPORT_FD_42SH + 1) * 2];
	pid_t					pipe_pid[PIPE_MAX_SUPPORT_FD_42SH + 1];
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
	pid_t					pid_grp;
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
	t_pipe_42sh				pipe[];
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
	pid_t					even_child;
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
	unsigned char			restore[];
}							t_alias_42sh;

typedef struct				s_dq_42sh
{
	t_in_42sh				*in_dquote;
	unsigned char			dquote;
	void					*hrdoc_cmp_lp;
	size_t					hrdoc_cmp_count;
	void					*hrdoc_next_lp;
	size_t					hrdoc_next_slesh;
	void					*hrdoc_start_lp;
	t_alias_42sh			*first_alias;
	t_alias_42sh			*last_alias;
	size_t					slesh_alias;
}							t_dq_42sh;

typedef struct				s_sh_42sh
{
	unsigned char			*path;
	size_t					count_path;
	unsigned char			*lp_sh;
	unsigned char			*lp_sh_e;
	unsigned char			*lp_cmd;
}							t_sh_42sh;

typedef struct				s_main_42sh
{
	t_pguitar_42sh			pguitar;
	t_dq_42sh				dq;
	t_process_42sh			pr;
	t_in_main_42sh			in;
	t_msg_42sh				msg;
	t_env_main_42sh			env;
	t_auto_42sh				auto_;
	t_auto_42sh				auto_file;
	t_auto_42sh				auto_env;
	t_select_42sh			slc;
	t_sh_42sh				sh;
	t_pwd_42sh				pwd;
	struct winsize			ws;
	struct termios			tty;
	struct termios			tty_change;
	t_auto_42sh				*lp_auto;
	pid_t					b_rep;
	char					*lp_home;
	size_t					count_home;
	void					*lp_home_tmp;
	size_t					count_home_tmp;
	void					*lp_home_tmp_next;
	char					**lp_spl_path;
	uintmax_t				litter_save[1];
	uintmax_t				litter[BUFFER_LITTER_42SH];
	uint_fast8_t			b_signo;
	uint_fast8_t			b_read;
	uint_fast8_t			b_hash;
	uint_fast8_t			b_quest_exit;
	uint_fast8_t			b_location;
	int						b_tty_out_in;
	int						fd;
	size_t					count_tty_out_in;
	t_write_buff			out;
	t_write_buff			err;
	size_t					b_fd_close;
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

typedef struct				s_add_exp_42sh
{
	void					*value;
	void					*value_end;
	uint_fast8_t			b_type;
}							t_add_exp_42sh;

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

typedef struct				s_replase_in_42sh
{
	t_main_42sh				*array;
	size_t					b_mode;
	t_replase_in_pars_42sh	prs;
	t_replase_in_exp_42sh	exp;
}							t_replase_in_42sh;

typedef struct				s_overlow_byte_in_42sh
{
	char					*repl;
	size_t					n_repl;
}							t_overlow_byte_in_42sh;

#endif
