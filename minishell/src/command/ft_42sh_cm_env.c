/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void	ft_42sh_cm_env(register t_main_42sh *array,
register char **lp_arg)
{
	register t_env_42sh		*env;
	register t_write_buff	*out;

	env = array->env.env.first;
	out = &array->out;
	if (env == 0)
		return (ft_42sh_dsp_msg(array, out, MSG_ENV_42SH));
	while (env != 0)
	{
		ft_write_buffer_str_zero(out, env->std.lp_key);
		ft_write_buffer_str_zero(out, "=");
		ft_write_buffer_str_zero(out, env->lp_value);
		ft_write_buffer_str_zero(out, "\n");
		env = (void *)env->std.next;
	}
	(void)lp_arg;
}
