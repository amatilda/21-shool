/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_env_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static t_env_42sh	*fn_pre_test(register t_main_42sh *array,
register char *env, register size_t count)
{
	register size_t				key_count;
	register char				*value;
	register t_env_42sh			*list;

	key_count = 0;
	while (key_count < count && env[key_count] != '=')
		key_count++;
	if ((count -= key_count) <= 1 || key_count == 0)
		return (0);
	value = &env[key_count + 1];
	count--;
	list = ft_42sh_env_create(env, key_count, value, count);
	if (key_count == LEN_(ENV_HOME_42SH) &&
	ft_strncmp(env, ENV_HOME_42SH, key_count) == 0)
	{
		if ((array->lp_home = ft_strndup(value, count)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		array->count_home = count;
	}
	else if (key_count == LEN_(ENV_PATH_42SH) &&
	ft_strncmp(env, ENV_PATH_42SH, key_count) == 0)
		array->env.lp_env_path = list;
	return (list);
}

static int			fn_first(register t_main_42sh *array,
register t_past_sort_42sh *root, register t_env_42sh *list)
{
	if (list == 0)
		return (0);
	array->env.count_env = 1;
	root->first = list;
	root->center = list;
	root->last = list;
	return (1);
}

static void			fn_home(register t_main_42sh *array)
{
	if (array->lp_home == 0)
	{
		array->lp_home = STR_HOME_PATH;
		array->count_home = LEN_(STR_HOME_PATH);
	}
}

void				ft_42sh_env_start(register t_main_42sh *array,
register char **env)
{
	register t_env_42sh			*list;
	register t_past_sort_42sh	*root;
	register char				*str;

	if (env[0] == 0)
		return ;
	while ((str = env++[0]) != 0 &&
	(list = fn_pre_test(array, str, ft_strlen(str))) == 0)
		(void)env;
	if (str == 0 || fn_first(array, (root = &array->env.env), list) == 0)
		return ;
	list->std.next = 0;
	list->std.prev = 0;
	while ((str = env++[0]) != 0)
	{
		if ((list = fn_pre_test(array, str, ft_strlen(str))) != 0)
		{
			ft_42sh_list_sort_paste(root, &list->std, ft_42sh_env_free);
			array->env.count_env++;
		}
	}
	fn_home(array);
}
