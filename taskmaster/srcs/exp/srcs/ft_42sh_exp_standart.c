/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exp_standart.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_exp.h"

static void		fn_home(register t_main_42sh *array)
{
	register void					*tmp;
	t_add_exp_42sh					in;

	if (array->home.lp_home != 0 || (tmp = getlogin()) == 0)
		return ;
	if ((tmp = ft_strjoin(EXP_HOME_PATH_42SH, tmp)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	in.value = tmp;
	in.value_end = tmp + ft_strlen(tmp);
	in.b_type = EXP_TYPE_EVERIMENT_42SH;
	ft_42sh_exp_add(array, (void *)EXP_HOME_42SH,
	(void *)EXP_HOME_42SH + sizeof(EXP_HOME_42SH) - 1, &in);
	ft_free(tmp);
}

static void		fn_pwd_set(register t_main_42sh *array,
register void *str)
{
	register size_t		tempos;

	tempos = ft_strlen(str);
	array->pwd.path.buff = str;
	ft_42sh_path_view(array, str, str + tempos);
	if ((array->pwd.prev_path.buff = ft_strndup(str, tempos)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	array->pwd.path.len = tempos;
	array->pwd.prev_path.len = tempos++;
	array->pwd.path.max_len = tempos;
	array->pwd.prev_path.max_len = tempos;
}

static void		fn_pwd(register t_main_42sh *array)
{
	register t_env_42sh			*list;
	struct stat					st_pwd;
	struct stat					st_cur;
	t_string					ret;

	if ((list = ft_42sh_list_find_key(&array->env.root, EXP_PWD_42SH,
	sizeof(EXP_PWD_42SH) - 1)) == 0 || list->lp_value[0] != '/')
		return (fn_pwd_set(array, array->pwd.path.buff));
	if (stat(list->lp_value, &st_pwd) != 0 ||
	(st_pwd.st_mode & S_IFMT) != S_IFDIR ||
	stat(array->pwd.path.buff, &st_cur) != 0
	|| st_pwd.st_dev != st_cur.st_dev || st_pwd.st_ino != st_cur.st_ino)
		return (fn_pwd_set(array, array->pwd.path.buff));
	ft_free(array->pwd.path.buff);
	ft_42sh_path_canon(&ret, (void *)list->lp_value, list->value_count);
	fn_pwd_set(array, ret.buff);
}

static void		fn_ps2(register t_main_42sh *array)
{
	if (array->msg.hrdc != 0)
		return ;
	if ((array->msg.hrdc =
	ft_strdup(PRTF_BOLT""MSG_HEREDOC_42SH""PRTF_RESET)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	array->msg.hrdc_lit = PRE_MSG_HEREDOC_LITTER_42SH;
}

void			ft_42sh_exp_standart(register t_main_42sh *array)
{
	fn_ps2(array);
	fn_home(array);
	fn_pwd(array);
	if (array->lp_spl_path == 0)
		ft_42sh_auto_create(array);
}
