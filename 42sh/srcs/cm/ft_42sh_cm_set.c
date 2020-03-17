/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_view(register t_write_buff *out, register t_env_42sh *env)
{
	if ((env->b_type & EXP_TYPE_CORECTION_42SH) == 0)
		return (ft_write_buffer_str_zero(out, env->std.lp_key));
	ft_write_buffer_str(out, env->std.lp_key, env->std.key_count);
	ft_write_buffer_str_zero(out, "='");
	ft_write_buffer_str(out, env->lp_value, env->value_count);
	ft_write_buffer_str_zero(out, "'");
}

void			ft_42sh_cm_set(register t_main_42sh *array,
register char **lp_arg)
{
	register t_env_42sh			*env;
	register t_write_buff		*out;
	char						buff[sizeof(env->number) * 8];

	env = array->env.root.first;
	if (env == 0)
		return (ft_42sh_dsp_err_msg(array, MSG_SET_NONE_42SH));
	if (ft_42sh_pipe_test_fd_dsp(array, STDOUT_FILENO, MSG_SET_42SH) == 0)
		return ;
	out = &array->out;
	while (env != 0)
	{
		if ((env->b_type & EXP_TYPE_NUMBER_42SH) != 0)
		{
			ft_write_buffer_str(out, env->std.lp_key, env->std.key_count + 1);
			ft_write_buffer_str(out, buff, ft_itoa(buff, env->number, 10,
			ITOA_LOWER));
		}
		else
			fn_view(out, env);
		ft_write_buffer_str_zero(out, "\n");
		env = (void *)env->std.next;
	}
	array->env.exit_status->number = STATUS_OK_42SH;
	(void)lp_arg;
}
