/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_comp_pars_dir.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:08:54 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:08:57 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_42sh_auto_comp.h"

int			ft_42sh_auto_comp_strncmp_tilda(register char *s1,
register char *s2, register size_t n)
{
	register size_t i;
	register size_t j;

	if (n == 0)
		return (0);
	i = 0;
	j = 0;
	if (s2[j] == '\\' && (s2[j + 1] == ' ' || s2[j + 1] == '\''
		|| s2[j + 1] == '\"'))
	{
		n--;
		j++;
	}
	while (s1[i] != 0 && s1[i] == s2[j] && i < n)
	{
		i++;
		j++;
		if (s2[j] == '\\' && ++j)
			n--;
	}
	if (s2[j] == '\0' || s1[i] == '\0')
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

static void	ft_42sh_auto_comp_str_add_tilda(t_main_42sh *array,
register t_in_42sh *list_text, t_logins_42sh *tmp_list)
{
	size_t	j;
	char	*str;
	char	*tmp;

	j = ft_strlen(tmp_list->std.lp_key) + 1;
	str = ft_strndup(array->pguitar.comp.cur + j,
		array->pguitar.comp.count_cur_litter - j);
	tmp = str;
	str = ft_strjoin((char *)tmp_list->home_dir, str);
	free(tmp);
	ft_42sh_str_delete(array, list_text, array->pguitar.comp.cur,
	array->pguitar.comp.count_cur_litter);
	ft_42sh_str_add(array, str, str + ft_strlen(str), 0);
	free(str);
}

static void	ft_42sh_auto_comp_str_del_tilda(t_main_42sh *array,
register t_in_42sh *list_text, t_logins_42sh *tmp_list, size_t i)
{
	if (i == 1 && ft_42sh_auto_comp_strncmp(array->pguitar.comp.str,
		tmp_list->std.lp_key, ft_strlen(tmp_list->std.lp_key)) != 0)
	{
		ft_42sh_str_delete(array, list_text, array->pguitar.comp.cur + 1,
		array->pguitar.comp.count_cur_litter - 1);
		ft_42sh_str_add(array, tmp_list->std.lp_key,
			tmp_list->std.lp_key + ft_strlen(tmp_list->std.lp_key), 0);
	}
	else if (i == 1)
		ft_42sh_auto_comp_str_add_tilda(array, list_text, tmp_list);
	if (array->lp_auto->all_cmd.first)
		ft_42sh_auto_create_array(array, array->lp_auto->all_cmd.first,
	array->lp_auto->count_all);
	if (i == 1)
		ft_42sh_auto_toogle(array);
}

static void	ft_42sh_auto_comp_add_files_tilda(t_main_42sh *array,
register t_in_42sh *list_text)
{
	size_t			i;
	t_logins_42sh	*tmp_list;
	t_logins_42sh	*list;

	i = 0;
	(void)list_text;
	list = array->login.first;
	if (array->lp_auto->all_cmd.first != 0)
		return ;
	while (list)
	{
		if (ft_42sh_auto_comp_strncmp_tilda(array->pguitar.comp.str,
		list->std.lp_key,
			ft_strlen(list->std.lp_key)) == 0)
		{
			ft_42sh_auto_add_list(array, list->std.lp_key, ' ');
			if (i == 0)
				tmp_list = list;
			i++;
		}
		list = (t_logins_42sh*)list->std.next;
	}
	ft_42sh_auto_comp_str_del_tilda(array, list_text, tmp_list, i);
}

size_t		ft_42sh_auto_comp_pars_dir_tilda(register t_main_42sh *array,
register t_in_42sh *list)
{
	size_t			i;
	register char	*str;

	i = array->pguitar.comp.count_str;
	str = array->pguitar.comp.str;
	while (*str != '~' && i-- != 0)
		str++;
	if (*str != '~' || (str > array->pguitar.comp.str && *(str - 1) != ':'))
		return (0);
	i = array->pguitar.comp.count_str - i;
	if (i == 0)
		i = 1;
	if (*str == '~' && (*(str + 1)) == '/')
		return (ft_42sh_auto_comp_pars_dir_tilda_slash(array, i));
	array->pguitar.comp.str += i;
	array->pguitar.comp.count_str -= i;
	i = ft_42sh_replase_home_test(array, (unsigned char*)array->pguitar.comp.str
		- i, (unsigned char*)(array->pguitar.comp.str), (unsigned char*)
		(array->pguitar.comp.str + array->pguitar.comp.count_str));
	array->pguitar.comp.dirr = ft_strdup("~");
	array->pguitar.comp.count_dirr = 1;
	ft_42sh_auto_comp_add_files_tilda(array, list);
	return (1);
}
