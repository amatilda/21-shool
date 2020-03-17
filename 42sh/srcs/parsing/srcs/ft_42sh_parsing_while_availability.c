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

static size_t			fn_exe_availability(register t_main_42sh *array,
register char *cmd, register char *cmd_add)
{
	register void			*tmp;
	struct stat				st;
	register size_t			mode;
	uint_fast8_t			error;

	error = STATUS_NOT_FIN_CMD_42SH;
	if (stat(cmd, &st) == 0)
	{
		mode = st.st_mode;
		if ((mode & S_IFMT) == S_IFDIR)
			tmp = MSG_IS_DIR_42SH;
		else if ((mode & S_IXUSR) | (mode & S_IXGRP) | (mode & S_IXOTH) != 0)
			return (1);
		else
		{
			error = STATUS_DEFINED_CMD_42SH;
			tmp = MSG_EXE_DEFINE_42SH;
		}
	}
	else
		tmp = MSG_EXE_NOT_42SH;
	cmd = (cmd_add == 0) ? cmd : cmd_add;
	ft_42sh_jobs_set_err(array, tmp, cmd, error);
	ft_free(cmd);
	return (0);
}

static t_all_cmd_42sh	**fn_test_cmd_next(register t_main_42sh *array,
register t_all_cmd_42sh **spl, register char *cmd)
{
	register size_t		b_type;

	if (((b_type = spl[0]->b_type) & AUTO_TYPE_ALIAS_42SH) != 0)
	{
		ft_42sh_jobs_set_err(array, MSG_EXE_NOT_42SH, cmd, STATUS_NOT_FIN_CMD_42SH);
		ft_free(cmd);
		return (0);
	}
	if ((b_type & AUTO_TYPE_HASH_42SH) != 0)
	{
		if (fn_exe_availability(array, spl[0]->path_hash, cmd) == 0)
			return (0);
		spl[0]->count_cmd++;
		return (spl);
	}
	if ((spl[0]->b_type & AUTO_TYPE_EXE_42SH) != 0)
	{
		chdir(spl[0]->path);
		if (fn_exe_availability(array, cmd, 0) == 0)
		{
			chdir(array->pwd.path.buff);
			return (0);
		}
		spl[0]->count_cmd++;
		chdir(array->pwd.path.buff);
		return (spl);
	}
	return (spl);
}


static t_all_cmd_42sh	**fn_test_cmd(register t_main_42sh *array,
register char *cmd, register size_t n)
{
	register t_all_cmd_42sh			**spl;
	register void					*tmp;
	t_shield_out_42sh				lp;

	tmp = ft_42sh_str_shield((void *)cmd, (void *)cmd + n, SHIELD_EXTERNALLY, &lp);
	if ((spl =
	(t_all_cmd_42sh **)ft_42sh_spl_find((void **)array->lp_auto->spl_all_cmd,
	array->lp_auto->count_all, tmp, lp.count)) == 0 || spl[0]->std.key_count != lp.count)
	{
		ft_42sh_jobs_set_err(array, MSG_EXE_NOT_CMD_42SH, cmd, STATUS_NOT_FIN_CMD_42SH);
		ft_free(tmp);
		ft_free(cmd);
		return (0);
	}
	ft_free(tmp);
	if ((array->b_location & LOCATION_SCRIPT_42SH) != 0 && n == 2 &&
	cmd[1] == 'g' && (cmd[0] == 'f' || cmd[0] == 'b'))
	{
		ft_42sh_jobs_set_err(array, " "MSG_FG_NOT_CONT_TXT_42SH, "", 0);
		return (0);
	}
	return (fn_test_cmd_next(array, spl, cmd));
}

size_t				ft_42sh_parsing_while_availability(
register t_main_42sh *array, register t_jobs_42sh *jobs,
register unsigned char *b, register size_t n)
{
	register t_all_cmd_42sh			**spl;

	spl = 0;
	if (n == 0)
	{
		ft_42sh_jobs_set_err(array, MSG_EXE_DEFINE_42SH, b, STATUS_DEFINED_CMD_42SH);
		ft_free(b);
		return (0);
	}
	else if (ft_42sh_parsing_path_test((char *)b, (char *)b + n) != 0)
	{
		if (fn_exe_availability(array, (char *)b, 0) == 0)
			return (0);
	}
	else if ((spl = fn_test_cmd(array, (char *)b, n)) == 0)
		return (0);
	jobs->path = (void *)spl;
	return (1);
}
