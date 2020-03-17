/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_cm.h"

static void		fn_view(register t_write_buff *out, register t_env_42sh *env)
{
	if ((env->b_type & EXP_TYPE_CORECTION_42SH) == 0)
	{
		ft_write_buffer_str_zero(out, env->std.lp_key);
	}
	else
	{
		ft_write_buffer_str(out, env->std.lp_key, env->std.key_count);
		ft_write_buffer_str_zero(out, "='");
		ft_write_buffer_str(out, env->lp_value, env->value_count);
		ft_write_buffer_str_zero(out, "'");
	}
	ft_write_buffer_str_zero(out, "\n");
}

static void		fn_all(register t_main_42sh *array,
register t_env_42sh *env, register t_write_buff *out)
{
	if (env == 0)
		return (ft_42sh_dsp_err_msg(array, MSG_EXPR_NONE_42SH));
	if (ft_42sh_pipe_test_fd_dsp(array, STDOUT_FILENO, MSG_EXPR_42SH) == 0)
		return ;
	while (env != 0)
	{
		if ((env->b_type & EXP_TYPE_EVERIMENT_42SH) != 0)
		{
			ft_write_buffer_str_zero(out, MSG_EXPR_VIEW_42SH);
			fn_view(out, env);
		}
		env = (void *)env->std.next;
	}
}

static void		fn_one_view(register t_env_42sh *list,
register t_write_buff *out)
{
	char						buff[sizeof(list->number) * 8];
	register size_t				b_type;

	if (((b_type = list->b_type) & EXP_TYPE_EVERIMENT_42SH) != 0)
		ft_write_buffer_str_zero(out, MSG_EXPR_VIEW_42SH);
	else if ((b_type & EXP_TYPE_NUMBER_42SH) != 0)
	{
		ft_write_buffer_str_zero(out, MSG_EXPR_SET_VIEW_42SH);
		ft_write_buffer_str(out, list->std.lp_key, list->std.key_count + 1);
		ft_write_buffer_str(out, buff, ft_itoa(buff, list->number, 10,
		ITOA_LOWER));
		ft_write_buffer_str_zero(out, "\n");
		return ;
	}
	else
		ft_write_buffer_str_zero(out, MSG_EXPR_SET_VIEW_42SH);
	fn_view(out, list);
}

static void		fn_one(register t_main_42sh *array,
register t_past_sort_42sh *env, register char **lp_arg,
register t_write_buff *out)
{
	register t_env_42sh				*list;
	register unsigned char			*str;
	register unsigned char			*tmp;
	register unsigned char			litter;
	register size_t					n;

	while ((str = (void *)lp_arg++[0]) != 0)
	{
		tmp = str;
		while ((litter = tmp[0]) != 0 && litter != '=')
			tmp++;
		n = tmp - str;
		if (n == 0 || (list = ft_42sh_list_find_key((void *)env,
		(void *)str, n)) == 0)
		{
			ft_42sh_dsp_err_msg_add_n(array, MSG_EXPR_NOT_FIND_42SH, str, n);
			continue ;
		}
		fn_one_view(list, out);
	}
}

void			ft_42sh_cm_export(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char			*str;
	register unsigned char			litter;
	register size_t					b_view;

	b_view = 0;
	while ((str = (void *)lp_arg[0]) != 0 && str++[0] == '-')
	{
		lp_arg++;
		if ((litter = str[0]) == 0 || (litter == '-' && str[1] == 0))
			break ;
		while ((litter = str++[0]) != 0 && litter == 'p')
			b_view = litter;
		if (litter != 0)
			return (ft_42sh_dsp_err_msg_add_n(array, MSG_BAD_OPTION_42SH,
			(void *)str - 1, ft_strlen_utf8_litter(str[-1])));
	}
	if ((str = (void *)lp_arg[0]) == 0)
		return (fn_all(array, array->env.root.first, &array->out));
	if (b_view == 0)
		ft_42sh_cm_export_set(array, lp_arg);
	else
		return (fn_one(array, &array->env.root, lp_arg, &array->out));
}
