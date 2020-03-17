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

#include "includes/ft_42sh_cm.h"

static void			fn_join(register t_main_42sh *array,
register void *str, register size_t b_view)
{
	if ((str = (void *)ft_42sh_path_join(array->pwd.path.buff,
	(void *)str)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_42sh_cm_cd_set(array, str, b_view);
	return (ft_free(str));
}

static void			fn_while(register t_main_42sh *array,
register char **spl, register void *str, register size_t b_view)
{
	register void					*tmp;
	struct stat						st;

	while ((tmp = spl++[0]) != 0)
	{
		if ((tmp = (void *)ft_42sh_path_join(tmp, (void *)str)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		if (stat(tmp, &st) != 0 && (st.st_mode & S_IFMT) == S_IFDIR)
		{
			ft_42sh_cm_cd_set(array, tmp, b_view);
			return (ft_free(tmp));
		}
	}
}

static void			fn_pre(register t_main_42sh *array,
register unsigned char *str, register size_t b_view)
{
	register unsigned char			litter;
	register char					**spl;

	b_view = (b_view == 'P') ? CD_PHYSICAL_42SH : CD_LOGIC_42SH;
	if (str == 0 || (litter = str[0]) == 0)
	{
		if ((str = (void *)array->lp_home) != 0)
			return (ft_42sh_cm_cd_set(array, str, b_view));
		return (ft_42sh_cm_cd_set(array, (void *)array->pwd.path.buff,
		b_view));
	}
	if (litter == '-' && str[1] == 0)
	{
		return (ft_42sh_cm_cd_set(array, (void *)array->pwd.prev_path.buff,
		(b_view | CD_VIEW_42SH)));
	}
	b_view = (b_view | CD_CANON_42SH);
	if (litter == '/')
		return (ft_42sh_cm_cd_set(array, str, b_view));
	if ((spl = array->pwd.spl_cd) == 0 || (litter == '.' && str[1] == '/') ||
	(litter == '.' && str[1] == '.' && str[2] == '/'))
		return (fn_join(array, str, b_view));
	fn_while(array, spl, str, b_view);
}

void				ft_42sh_cm_cd(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char			*str;
	register unsigned char			litter;
	register size_t					b_view;

	b_view = 0;
	while ((str = (void *)lp_arg[0]) != 0 && str++[0] == '-' && str[0] != 0)
	{
		if ((litter = str[0]) == 0 || (litter == '-' && str[1] == 0))
		{
			lp_arg++;
			break ;
		}
		while ((litter = str++[0]) != 0 && (litter == 'P' || litter == 'L'))
			b_view = litter;
		if (litter != 0)
			break ;
		lp_arg++;
	}
	if ((str = (void *)lp_arg[0]) != 0 && lp_arg[1] != 0)
		return (ft_42sh_dsp_err_msg(array, MSG_CD_TOO_ARG_42SH));
	fn_pre(array, str, b_view);
}
