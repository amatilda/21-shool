/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_while.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_parsing.h"

static t_jobs_42sh	*fn_not_cmd(register t_main_42sh *array,
register t_parsing_in_42sh *in, register char *cmd)
{
	array->exit_status = 0x7F;
	ft_42sh_dsp_err_msg_add(array, MSG_EXE_NOT_CMD_42SH, cmd);
	ft_strsplit_free(in->lp_arg);
	return (0);
}

static size_t		fn_test_cmd_exe(register t_main_42sh *array,
register t_parsing_in_42sh *in, register t_all_cmd_42sh **spl,
register char *cmd)
{
	chdir(spl[0]->path);
	if (ft_42sh_exe_availability(array, cmd) == 0)
	{
		chdir(array->pwd.path.buff);
		ft_strsplit_free(in->lp_arg);
		return (0);
	}
	chdir(array->pwd.path.buff);
	return (1);
}

t_jobs_42sh			*ft_42sh_parsing_while_availability(
register t_main_42sh *array, register t_parsing_in_42sh *in, unsigned char *b,
register unsigned char *end)
{
	register t_all_cmd_42sh			**spl;
	register char					*cmd;
	register size_t					n;

	cmd = in->cmd.buff;
	n = in->cmd.len;
	in->lp_arg[0] = cmd;
	spl = 0;
	if (ft_42sh_parsing_path_test(cmd, cmd + n) != 0)
	{
		if (ft_42sh_exe_availability(array, cmd) == 0)
		{
			ft_strsplit_free(in->lp_arg);
			return (0);
		}
	}
	else if ((spl = (t_all_cmd_42sh **)
	ft_42sh_spl_find((void **)array->lp_auto->spl_all_cmd,
	array->lp_auto->count_all, cmd, n)) == 0 || spl[0]->std.key_count != n)
		return (fn_not_cmd(array, in, cmd));
	else if (spl[0]->b_type == AUTO_TYPE_EXE &&
	fn_test_cmd_exe(array, in, spl, cmd) == 0)
		return (0);
	return (ft_42sh_jobs_create_add_list(array, in->lp_arg, spl,
	ft_42sh_pipe_next_count(array, b, end)));
}
