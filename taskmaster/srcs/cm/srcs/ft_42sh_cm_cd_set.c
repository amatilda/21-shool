/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_cd_set.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

static void		fn_set_add(register t_main_42sh *array,
register unsigned char *str, register size_t count)
{
	t_add_exp_42sh				in;

	ft_free(array->pwd.prev_path.buff);
	array->pwd.prev_path = array->pwd.path;
	array->pwd.path.buff = (void *)str;
	array->pwd.path.len = count;
	array->pwd.path.max_len = count + 1;
	ft_42sh_path_view(array, str, str + count);
	in.value = str;
	in.value_end = str + count;
	in.b_type = EXP_TYPE_EVERIMENT_42SH;
	ft_42sh_exp_add(array, (void *)EXP_PWD_42SH,
	(void *)EXP_PWD_42SH + sizeof(EXP_PWD_42SH) - 1, &in);
	str = (void *)array->pwd.prev_path.buff;
	in.value = str;
	in.value_end = str + array->pwd.prev_path.len;
	in.b_type = EXP_TYPE_EVERIMENT_42SH;
	ft_42sh_exp_add(array, (void *)EXP_OLDPWD_42SH,
	(void *)EXP_OLDPWD_42SH + sizeof(EXP_OLDPWD_42SH) - 1, &in);
}

static size_t	fn_set(register t_main_42sh *array,
register unsigned char *str, register size_t b_view, register size_t count)
{
	t_string					ret;

	if (chdir((void *)str) == -1)
		return (0);
	if ((b_view & CD_CANON_42SH) == 0)
	{
		if ((str = ft_strdup((void *)str)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	}
	else
	{
		ft_42sh_path_canon(&ret, str, count);
		str = (void *)ret.buff;
		count = ret.len;
	}
	fn_set_add(array, str, count);
	if ((b_view & CD_VIEW_42SH) == 0 ||
	ft_42sh_pipe_test_fd_dsp(array, STDOUT_FILENO, MSG_CD_42SH) == 0)
		return (1);
	ft_write_buffer_str_zero(&array->out, (void *)array->pwd.path_view);
	ft_write_buffer_str_zero(&array->out, "\n");
	return (1);
}

static void		fn_physical(register t_main_42sh *array,
register unsigned char *str, register unsigned char *dir,
register size_t b_view)
{
	if (fn_set(array, str, b_view, ft_strlen((void *)str)) == 0)
	{
		ft_42sh_dsp_err_msg_add_n(array,
		WAR_42SH""MSG_CD_NOT_VALID_TXT_42SH""PRTF_RESET, (void *)dir, 0);
	}
}

void			ft_42sh_cm_cd_set(register t_main_42sh *array,
register unsigned char *str, register unsigned char *dir,
register size_t b_view)
{
	register unsigned char		*tmp;

	if ((b_view & CD_PHYSICAL_42SH) == 0)
		return (fn_physical(array, str, dir, b_view));
	if (chdir((void *)str) == -1)
	{
		return (ft_42sh_dsp_err_msg_add_n(array,
		WAR_42SH""MSG_CD_NOT_VALID_TXT_42SH""PRTF_RESET, (void *)dir, 0));
	}
	if ((tmp = (void *)getcwd(0, 0)) == 0)
	{
		ft_42sh_dsp_err_msg(array,
		WAR_42SH""MSG_CD_CHDIR_TXT_42SH""PRTF_RESET);
		if (chdir(array->pwd.path.buff) == -1)
		{
			if (chdir((void *)'/') == -1)
				ft_42sh_exit(E_CD_CODE_42SH, __FILE__, __func__, __LINE__);
			fn_set(array, (void *)'/', b_view, 1);
		}
		return ;
	}
	if (fn_set(array, tmp, b_view, ft_strlen((void *)tmp)) == 0)
		ft_42sh_dsp_err_msg_add_n(array,
		WAR_42SH""MSG_CD_DENIED_TXT_42SH""PRTF_RESET, (void *)dir, 0);
	ft_free(tmp);
}
