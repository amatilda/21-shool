/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:06:23 by amatilda          #+#    #+#             */
/*   Updated: 2019/10/07 20:58:43 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <grp.h>
# include <pwd.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/stat.h>

# define NAME_PROG					"ls"
# define FLAG_A						'A'
# define FLAG_F						'F'
# define FLAG_RECURS				'R'
# define FLAG_SORT_SIZE				'S'
# define FLAG_FULL_DATE				'T'
# define FLAG_SORT_TIME_CREATION	'U'
# define FLAG_SYSTEM				'a'
# define FLAG_SORT_LAST_CHANGE		'c'
# define FLAG_ONLY_DIR				'd'
# define FLAG_ONLY_GROOP			'g'
# define FLAG_NOT_SORT				'f'
# define FLAG_INFO_FULL				'l'
# define FLAG_ONLY_USER				'o'
# define FLAG_DIR_SLECH				'p'
# define FLAG_REVERSE				'r'
# define FLAG_LAST_MODIF			't'
# define FLAG_SORT_TIME_ACCES		'u'
# define FLAG_ONE_LINE				'1'
# define FT_LS_BUFFER_SIZE			0x4000
# define FT_LS_BUFFER_SIZE_INVALID	0x1000
# define FT_LS_MAX_NAME				0xFF + 1
# define STR_OPTION		"AFRSTUacdgfloprtu1"
# define USAGE_PRE		NAME_PROG": illegal option -- "
# define USAGE_LAST		"\nusage: "NAME_PROG" [-"STR_OPTION"] [file ...]\n"
# define ERROR_NULL_STR	NAME_PROG": fts_open"

typedef struct				s_list_type
{
	union
	{
		size_t				tempos;
		struct				s_ltype
		{
			char			buff;
			char			type;
		}					t_ltype;
	}						t_uni;
}							t_list_type;

typedef struct				s_list_invalid
{
	char					*name;
	struct s_list_invalid	*prev;
	struct s_list_invalid	*next;
	int						errno_;
	mode_t					st_mode_type;
}							t_list_invalid;

typedef struct				s_list_file
{
	char					*name;
	struct s_list_file		*prev;
	struct s_list_file		*next;
	struct timespec			st_timespec;
	char					*patch;
	char					*pw_name;
	char					*gr_name;
	size_t					pw_size;
	size_t					gr_size;
	mode_t					st_mode;
	mode_t					st_mode_type;
	off_t					size_file;
	nlink_t					st_nlink;
	dev_t					st_rdev;
	size_t					len;
}							t_list_file;

typedef struct				s_list_dir
{
	char					*name;
	struct s_list_dir		*prev;
	struct s_list_dir		*next;
	struct timespec			st_timespec;
	off_t					size_file;
}							t_list_dir;

typedef struct				s_fl_ls_list_invalid
{
	t_list_invalid			*first;
	t_list_invalid			*center;
	t_list_invalid			*last;
}							t_fl_ls_list_invalid;

typedef struct				s_fl_ls_list_dir
{
	t_list_dir				*first;
	t_list_dir				*center;
	t_list_dir				*last;
	size_t					count;
}							t_fl_ls_list_dir;

typedef struct				s_fl_ls_list_file
{
	t_list_file				*first;
	t_list_file				*center;
	t_list_file				*last;
	t_list_file				*list_tmp;
	off_t					max_size;
	blkcnt_t				st_blocks;
	nlink_t					max_nlink;
	size_t					max_pw_name;
	size_t					max_gr_name;
}							t_fl_ls_list_file;

typedef struct				s_main
{
	struct timespec			*st_timespec;
	char					option[0x7F];
	t_fl_ls_list_invalid	invalid;
	t_fl_ls_list_file		file;
	t_fl_ls_list_invalid	*inv_new;
	t_fl_ls_list_file		*file_new;
	t_fl_ls_list_dir		*dir_new;
	struct dirent			*dp;
	char					*join;
	int						(*f)();
	char					*err_str;
	char					type;
	time_t					offset_sec;
	time_t					current_moth;
	time_t					current_year;
	size_t					count;
	size_t					count_invalid;
	uint_fast8_t			b_level;
	struct stat				stat_info;
	char					out_pre[FT_LS_MAX_NAME];
	char					b[FT_LS_BUFFER_SIZE];
	char					b_invalid[FT_LS_BUFFER_SIZE_INVALID];
	size_t					count_list;
	size_t					max_len;
	struct winsize			ws;
}							t_main;

int							ft_ls_list_add_invalid(register t_main *array,
	register t_fl_ls_list_invalid *invalid, register char *name);
int							ft_ls_list_add_dir(register t_main *array,
	register t_fl_ls_list_dir *dir, char *name);
int							ft_ls_list_add_file(register t_main *array,
	register t_fl_ls_list_file *file, char *name);
void						ft_ls_display(register t_main *array,
	t_fl_ls_list_invalid *invalid, t_fl_ls_list_file *file,
	uint_fast8_t b_level);
void						ft_ls_display_reverse(register t_main *array,
	register char *list_name);
int							ft_ls_recursive(register t_main *array,
	register t_fl_ls_list_dir *dir, uint_fast8_t b_level);
int							ft_ls_free(register t_main *array,
	register t_list_invalid *invalid, register t_list_file *file,
	register t_list_dir *dir);
ssize_t						ft_ls_sort(register t_main *array,
	register char *root, register char *list,
	ssize_t (*cmp)(register t_main *,
		register char *, register char *));
ssize_t						ft_ls_strcmp_name(register t_main *array,
	register char *root, register char *list);
ssize_t						ft_ls_strcmp_invalid(register t_main *array,
	register char *curent, register char *list);
ssize_t						ft_ls_strcmp_last_modif(register t_main *array,
	register char *curent, register char *list);
ssize_t						ft_ls_strcmp_size(register t_main *array,
	register char *curent, register char *list);
void						fn_dub_char(register t_main *array,
	register const char litter, register size_t dup_count);
void						fn_copy_str_zero(register t_main *array,
	register const char *str);
void						fn_copy_str(register t_main *array,
	register const char *str, register size_t n);
void						fn_copy_str_zero_invalid(register t_main *array,
	register const char *str);
void						fl_ls_add_list_init(register t_main *array,
	t_fl_ls_list_invalid *inv_new, register t_fl_ls_list_file *file_new,
	t_fl_ls_list_dir *dir_new);
void						ft_ls_init_main0(register t_main *array);
void						ft_ls_init_main1(register t_main *array,
	register t_fl_ls_list_dir *dir);
void						fl_ls_add_list_test(register t_main *array,
	register char *list_name, uint_fast8_t b_level);
void						fn_display_info_full(register t_main *array,
	t_fl_ls_list_file *file, register t_list_file *list, uint_fast8_t b_level);
void						ft_ls_display_full_add(register t_main *array,
	t_fl_ls_list_file *file, register t_list_file *list, register char *buff);
void						ft_ls_display_line(register t_main *array,
register t_list_file *list, register char *opt);
void						ft_ls_display_raw(register t_main *array,
register t_list_file *list, register char *opt);

#endif
