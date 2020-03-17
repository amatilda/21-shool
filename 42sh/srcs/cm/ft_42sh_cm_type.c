/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void			fn_msg(register t_write_buff *out,
register t_all_cmd_42sh **spl, register unsigned char *b)
{
	register size_t					b_type;

	b_type = spl[0]->b_type;
	if ((b_type & AUTO_TYPE_FUN_42SH) != 0)
		ft_write_buffer_str_zero(out, MSG_TYPE_FUN_42SH);
	else if ((b_type & AUTO_TYPE_EXE_42SH) != 0)
	{
		ft_write_buffer_str_zero(out, MSG_TYPE_EXE_42SH);
		ft_write_buffer_str_zero(out, spl[0]->path);
		ft_write_buffer_str_zero(out, "/");
		ft_write_buffer_str_zero(out, (void *)b);
	}
	else if ((b_type & AUTO_TYPE_ALIAS_42SH) != 0)
	{
		ft_write_buffer_str_zero(out, MSG_TYPE_ALIAS_42SH);
		ft_write_buffer_str_zero(out, spl[0]->path);
	}
}

static size_t		fn_pre(register t_main_42sh *array,
register char **lp_arg)
{
	if (lp_arg[0] == 0)
	{
		array->env.exit_status->number = STATUS_FALTURE_42SH;
		return (0);
	}
	if (ft_42sh_pipe_test_fd_dsp(array, STDOUT_FILENO, MSG_TYPE_42SH) == 0)
		return (0);
	return (1);
}

static void			fn_test(register t_main_42sh *array,
register t_write_buff *out, register unsigned char *b, register size_t n)
{
	struct stat				st;

	if (ft_42sh_parsing_path_test((void *)b, (void *)(b + n)) != 0 &&
	lstat((void *)b, &st) == 0)
	{
		ft_write_buffer_str_zero(out, MSG_TYPE_EXE_42SH);
		ft_write_buffer_str_zero(out, (void *)b);
		return ;
	}
	array->env.exit_status->number = STATUS_FALTURE_42SH;
	ft_write_buffer_str_zero(out, MSG_TYPE_NOT_42SH);
}

void				ft_42sh_cm_type(register t_main_42sh *array,
register char **lp_arg)
{
	register unsigned char			*b;
	register t_all_cmd_42sh			**spl;
	register size_t					n;
	register t_write_buff			*out;

	if (fn_pre(array, lp_arg) == 0)
		return ;
	out = &array->out;
	while ((b = (void *)lp_arg++[0]) != 0)
	{
		ft_write_buffer_str_zero(out, MSG_TYPE_42SH": ");
		ft_write_buffer_str_zero(out, (void *)b);
		n = ft_strlen((void *)b);
		if (n == 0 || (spl = (t_all_cmd_42sh **)
		ft_42sh_spl_find((void **)array->lp_auto->spl_all_cmd,
		array->lp_auto->count_all, (void *)b, n)) == 0 ||
		n != spl[0]->std.key_count)
			fn_test(array, out, b, n);
		else
			fn_msg(out, spl, b);
		ft_write_buffer_str_zero(out, "\n");
	}
}
