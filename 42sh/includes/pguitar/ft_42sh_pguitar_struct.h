/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_pguitar_struct.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:12:24 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:12:28 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_PGUITAR_STRUCT_H
# define FT_42SH_PGUITAR_STRUCT_H

typedef struct					s_pguitar_comp_42sh
{
	char						*cur;
	char						*str;
	char						*dirr;
	char						*open_dirr;
	char						*str_dup;
	char						*dollar;
	char						*cur_dol;
	char						*read_dir;
	size_t						del;
	size_t						count_read;
	char						*caret;
	size_t						figure;
	size_t						type_q;
	size_t						count_str;
	size_t						count_cur;
	size_t						count_cur_litter;
	size_t						count_dirr;
	size_t						count_d;
	size_t						dir_dol;
	size_t						*root;
	size_t						slash;
}								t_pguitar_comp_42sh;

typedef struct					s_pguitar_alias_42sh
{
	char						*name;
	char						*value;
	size_t						n_cnt;
	size_t						v_cnt;
	size_t						n_quote;
	size_t						v_quote;
	size_t						new_line;
	struct s_pguitar_alias_42sh	*next;
	char						lp[1];
}								t_pguitar_alias_42sh;

typedef struct					s_pguitar_alias_file_42sh
{
	size_t						crc32;
	size_t						offset_alias;
	size_t						size_alias;
	char						lp[1];
}								t_pguitar_alias_file_42sh;

typedef struct					s_pguitar_alias_modif_42sh
{
	char						*home;
	size_t						modif;
	size_t						file;
	size_t						del_file;
	size_t						new_line;
	t_pguitar_alias_42sh		*first_list;
}								t_pguitar_alias_modif_42sh;

typedef struct					s_pguitar_42sh
{
	t_pguitar_comp_42sh			comp;
	t_pguitar_alias_modif_42sh	f_modif;
	t_pguitar_alias_42sh		*list;
}								t_pguitar_42sh;

#endif
