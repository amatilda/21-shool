/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_test_path_add.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

size_t					ft_42sh_task_test_path_availability(register char *cmd)
{
	struct stat				st;
	register size_t			mode;

	if (stat(cmd, &st) == 0)
	{
		mode = st.st_mode;
		if ((mode & S_IFMT) == S_IFDIR)
			;
		else if ((mode & S_IXUSR) | (mode & S_IXGRP) | (mode & S_IXOTH) != 0)
			return (1);
	}
	return (0);
}

static t_all_cmd_42sh	**fn_test_cmd_next(register t_main_42sh *array,
register t_all_cmd_42sh **spl, register char *cmd)
{
	if ((spl[0]->b_type & AUTO_TYPE_EXE_42SH) != 0)
	{
		chdir(spl[0]->path);
		if (ft_42sh_task_test_path_availability(cmd) == 0)
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

void					*ft_42sh_task_test_path_error_log(register t_task
*task, register void *b, uint8_t b_test, register char **arg)
{
	if (b == 0)
	{
		task_log("[%s] "TASK_LOG_CRITICAL
		" "TASK_LOG_MEMORY".\n", task->name);
		if (arg != 0)
			ft_strsplit_free(arg);
		return ((void *)1);
	}
	else
	{
		if (b_test != 0)
		{
			task_log("[%s] "TASK_LOG_ERROR
			" Invalid command: %s\n", task->name, b);
		}
		else
		{
			task_log("[%s] "TASK_LOG_ERROR
			" Invalid command path specified: %s\n", task->name, b);
		}
		if (arg != 0)
			ft_strsplit_free(arg);
	}
	return (0);
}

t_all_cmd_42sh			**ft_42sh_task_test_path_test_cmd(register
t_main_42sh *array, register t_task *task, register char *cmd,
register size_t n)
{
	register t_all_cmd_42sh			**spl;
	register void					*tmp;
	t_shield_out_42sh				lp;

	if ((tmp = ft_42sh_str_shield((void *)cmd, (void *)cmd + n,
	SHIELD_EXTERNALLY, &lp)) == 0)
		return (ft_42sh_task_test_path_error_log(task, 0, 0, 0));
	if ((spl =
	(t_all_cmd_42sh **)ft_42sh_spl_find((void **)array->lp_auto->spl_all_cmd,
	array->lp_auto->count_all, tmp, lp.count)) == 0 ||
	spl[0]->std.key_count != lp.count)
	{
		ft_free(tmp);
		return (0);
	}
	ft_free(tmp);
	return (fn_test_cmd_next(array, spl, cmd));
}
