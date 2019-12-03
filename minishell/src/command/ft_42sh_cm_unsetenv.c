/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_unsetenv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_unset(register t_main_42sh *array,
register t_write_buff *out, register char *key)
{
	register t_env_42sh			*list;
	register t_past_sort_42sh	*root;

	root = &array->env.env;
	if ((list = ft_42sh_list_find_key(root, key, ft_strlen(key))) == 0)
		return (ft_42sh_dsp_msg_add(array, out, MSG_UNSETENV_NOT_42SH, key));
	ft_42sh_list_cut(root, &list->std);
	ft_42sh_env_free(list);
	array->env.count_env--;
	if (array->env.lp_env_path != list)
		return ;
	array->env.lp_env_path = 0;
	ft_42sh_auto_free_all_cmd(array);
	ft_42sh_auto_create(array);
}

void			ft_42sh_cm_unsetenv(register t_main_42sh *array,
register char **lp_arg)
{
	register t_write_buff	*out;
	register char			**tmp;
	register size_t			argc;
	register char			**env_spl;

	out = &array->out;
	if (array->env.env.first == 0)
		return (ft_42sh_dsp_msg(array, out, MSG_ENV_42SH));
	tmp = lp_arg;
	argc = 0;
	while (tmp++[0] != 0)
		argc++;
	if (argc != 1)
		return (ft_42sh_dsp_msg(array, out, MSG_UNSETENV_42SH));
	fn_unset(array, out, lp_arg[0]);
	if ((env_spl = array->env.lp_spl_env) != 0)
	{
		array->env.lp_spl_env = 0;
		ft_strsplit_free(env_spl);
	}
}
