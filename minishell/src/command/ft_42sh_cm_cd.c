/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static size_t		fn_test_prev(register t_main_42sh *array,
register unsigned char *str)
{
	register unsigned char	litter;
	register size_t			tempos;

	while ((litter = str++[0]) != 0 && litter <= 0x20)
		(void)str;
	if (litter != '-')
		return (1);
	while ((litter = str++[0]) != 0 && litter <= 0x20)
		(void)str;
	if (litter != 0)
		return (1);
	tempos = (size_t)array->pwd.path.buff;
	array->pwd.path.buff = array->pwd.prev_path.buff;
	array->pwd.prev_path.buff = (void *)tempos;
	tempos = array->pwd.path.len;
	array->pwd.path.len = array->pwd.prev_path.len;
	array->pwd.prev_path.len = tempos;
	tempos = array->pwd.path.max_len;
	array->pwd.path.max_len = array->pwd.prev_path.max_len;
	array->pwd.prev_path.max_len = tempos;
	tempos = array->pwd.path_litter;
	array->pwd.path_litter = array->pwd.prev_path_litter;
	array->pwd.prev_path_litter = tempos;
	return (0);
}

static void			fn_set_path(register t_main_42sh *array,
register t_string *path, register char *str, register size_t n)
{
	if (chdir(str) != 0)
	{
		ft_42sh_dsp_msg_add(array, &array->out, MSG_CD_NOT_VALID_42SH, str);
		free(str);
		return ;
	}
	free(array->pwd.prev_path.buff);
	array->pwd.prev_path = array->pwd.path;
	array->pwd.prev_path_litter = array->pwd.path_litter;
	path->buff = str;
	path->len = n;
	path->max_len = n + 1;
	array->pwd.path_litter = ft_strlen_utf8(str);
}

void				ft_42sh_cm_cd(register t_main_42sh *array,
register char **lp_arg)
{
	register size_t			tempos;
	register char			*str;
	register t_string		*path;
	t_string				ret;

	tempos = 0;
	str = lp_arg[0];
	while (lp_arg++[0] != 0)
		tempos++;
	path = &array->pwd.path;
	if (tempos == 0)
	{
		tempos = array->count_home;
		if ((str = ft_strndup(array->lp_home, tempos)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		return (fn_set_path(array, path, str, tempos));
	}
	if (tempos != 1)
		return (ft_42sh_dsp_msg(array, &array->out, MSG_CD_42SH));
	if (fn_test_prev(array, (unsigned char *)str) == 0)
		return ;
	ft_42sh_parsing_path(&ret, path, str, ft_strlen(str));
	fn_set_path(array, path, ret.buff, ret.len);
}
