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
	struct s_std_key_42sh	*prev;
	struct s_std_key_42sh	*next;
}							t_std_key_42sh;

typedef struct				s_all_cmd_42sh
{
	t_std_key_42sh			std;
	size_t					key_litter;
	char					key[];
}							t_all_cmd_42sh;

typedef struct				s_env_42sh
{
	t_std_key_42sh			std;
	char					*lp_value;
	size_t					value_count;
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
	t_past_sort_42sh		env;
	size_t					count_env;
	t_env_42sh				*lp_env_path;
	char					**lp_spl_env;
}							t_env_main_42sh;

typedef struct				s_pwd_42sh
{
	t_string				path;
	size_t					path_litter;
	t_string				prev_path;
	size_t					prev_path_litter;
}							t_pwd_42sh;

typedef struct				s_process_42sh
{
	pid_t					pid;
	uint_fast8_t			b_main_suspend;
}							t_process_42sh;

typedef struct				s_auto_42sh
{
	t_past_sort_42sh		all_cmd;
	t_all_cmd_42sh			**spl_all_cmd;
	size_t					count_all;
	size_t					max_litter;
	uint_fast8_t			b_view;
	size_t					view_raw;
	size_t					b_limit;
	size_t					b_auto;
	size_t					auto_cmd;
	size_t					auto_litter_len;
	size_t					auto_len;
	t_all_cmd_42sh			**auto_spl;
}							t_auto_42sh;

typedef struct				s_main_42sh
{
	t_process_42sh			pr;
	t_in_main_42sh			in;
	t_msg_42sh				msg;
	t_env_main_42sh			env;
	t_auto_42sh				tab;
	t_pwd_42sh				pwd;
	t_string				cmd;
	struct winsize			ws;
	struct termios			tty;
	struct termios			tty_change;
	char					**lp_arg;
	char					*lp_home;
	size_t					count_home;
	char					**lp_spl_path;
	t_in_42sh				*in_dquote;
	char					dquote;
	uint_fast32_t			litter[4];
	uint_fast8_t			b_signo;
	t_write_buff			out;
	char					buff_out[BUFFER_OUT_42SH];
}							t_main_42sh;

typedef struct				s_fun_42sh
{
	char					*name;
	size_t					count;
	void					(*f)(register t_main_42sh *array,
	register char **lp_arg);
}							t_fun_42sh;

extern t_main_42sh			*g_lp_array;
extern t_fun_42sh			g_cmd_array[];

#endif
