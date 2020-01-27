/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_setenv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static int		fn_test_space(register char *str)
{
	register unsigned char		litter;

	while ((litter = str[0]) <= 0x20)
		str++;
	if (litter == 0)
		return (0);
	return (1);
}

static void		fn_set_path(register t_main_42sh *array,
register t_env_42sh *list)
{
	if (ft_strcmp(ENV_PATH_42SH, list->key) != 0)
		return ;
	array->env.lp_env_path = list;
	ft_42sh_auto_free_all_cmd(array);
	ft_42sh_auto_create(array);
}

static void		fn_set(register t_main_42sh *array,
register char *key, register char *value)
{
	register t_env_42sh			*list;
	register t_past_sort_42sh	*root;
	register size_t				key_count;
	register size_t				value_count;

	key_count = ft_strlen(key);
	value_count = ft_strlen(value);
	root = &array->env.env;
	if ((list = ft_42sh_list_find_key(root, key, key_count)) == 0)
	{
		list = ft_42sh_env_create(key, key_count, value, value_count);
		ft_42sh_list_sort_paste(root, &list->std, ft_42sh_env_free);
		array->env.count_env++;
		fn_set_path(array, list);
		return ;
	}
	ft_free(list->lp_value);
	if ((key = ft_malloc(value_count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	list->lp_value = key;
	list->value_count = value_count;
	key[value_count] = 0;
	ft_memcpy(key, value, value_count);
	fn_set_path(array, list);
}

void			ft_42sh_cm_setenv(register t_main_42sh *array,
register char **lp_arg)
{
	register char			*str;
	register char			**tmp;
	register size_t			argc;

	if (array->env.env.first == 0)
		return (ft_42sh_dsp_err_msg(array, MSG_ENV_42SH));
	tmp = lp_arg;
	argc = 0;
	while (tmp++[0] != 0)
		argc++;
	if (argc != 2)
		return (ft_42sh_dsp_err_msg(array, MSG_SETENV_42SH));
	if (fn_test_space((str = lp_arg[1])) == 0)
		return (ft_42sh_dsp_err_msg(array, MSG_SETENV_SPACE_42SH));
	fn_set(array, lp_arg[0], str);
	if ((tmp = array->env.lp_spl_env) != 0)
	{
		array->env.lp_spl_env = 0;
		ft_strsplit_free(tmp);
	}
}
