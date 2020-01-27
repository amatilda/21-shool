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

typedef struct				s_pguitar_comp_42sh
{
	char					*cur;
	char					*str;
	char					*dirr;
	char					*open_dirr;
	char					*str_dup;
	size_t					del;
	size_t					type_q;
	size_t					count_str;
	size_t					count_cur;
	size_t					count_cur_litter;
	size_t					count_dirr;
	size_t					*root;
}							t_pguitar_comp_42sh;

typedef struct				s_pguitar_42sh
{
	t_pguitar_comp_42sh		comp;
}							t_pguitar_42sh;

#endif
