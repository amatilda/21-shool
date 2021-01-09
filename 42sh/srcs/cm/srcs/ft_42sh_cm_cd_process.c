/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_cd_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_cm.h"

static void			fn_stub(register t_main_42sh *array,
register char *tmp, register void *str, register size_t b_view)
{
	ft_42sh_cm_cd_set(array, (void *)tmp, str, b_view);
	return (ft_free(tmp));
}

void				ft_42sh_cm_cd_process(register t_main_42sh *array,
register char **spl, register void *str, register size_t b_view)
{
	register char					*tmp;
	register char					*tempos;
	struct stat						st;

	while ((tmp = spl++[0]) != 0)
	{
		if (tmp[0] == '.' && tmp[1] == '/')
		{
			if ((tempos = (void *)ft_42sh_path_join(array->pwd.path.buff,
			tmp)) == 0)
				ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
			if ((tmp = (void *)ft_42sh_path_join(tempos, (void *)str)) == 0)
				ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
			ft_free(tempos);
		}
		else if ((tmp = (void *)ft_42sh_path_join(tmp, (void *)str)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
		if (stat(tmp, &st) == 0 && (st.st_mode & S_IFMT) == S_IFDIR)
			return (fn_stub(array, tmp, str, b_view));
		ft_free(tmp);
	}
	ft_42sh_dsp_err_msg_add_n(array,
	WAR_42SH""MSG_CD_NOT_VALID_TXT_42SH""PRTF_RESET, (void *)str, 0);
}
