/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_exe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_not_find(register t_main_42sh *array,
register t_write_buff *out, register char *cmd, register size_t n)
{
	ft_42sh_dsp_msg(array, out, MSG_EXE_NOT_CMD_42SH);
	ft_write_buffer_str(out, cmd, n);
	ft_write_buffer_str_zero(out, "\n");
}

static void		fn_finish(register t_main_42sh *array,
register t_write_buff *out, register pid_t pid)
{
	int							stat_loc;

	array->pr.b_main_suspend = 1;
	wait4(pid, &stat_loc, 0, 0);
	array->pr.b_main_suspend = 0;
	tcsetattr(STDOUT_FILENO, TCSANOW, &array->tty_change);
	if (WIFSIGNALED(stat_loc) && WTERMSIG(stat_loc) == SIGINT)
		ft_write_buffer_str_zero(out, "\n\x1b[J");
}

static void		fn_exe(register t_main_42sh *array,
register char **lp_arg)
{
	register char				**env_spl;
	register t_write_buff		*out;
	register pid_t				pid;

	if ((env_spl = array->env.lp_spl_env) == 0)
	{
		env_spl = ft_42sh_env_split(array->env.env.first,
		array->env.count_env);
		array->env.lp_spl_env = env_spl;
	}
	out = &array->out;
	ft_write_buffer(out);
	if ((pid = fork()) == 0)
	{
		tcsetattr(STDOUT_FILENO, TCSANOW, &array->tty);
		array->pr.pid = pid;
		execve(lp_arg[0], lp_arg, env_spl);
		ft_42sh_exit(E_EXE_CODE_42SH);
	}
	else if (pid < 0)
		return (ft_42sh_dsp_msg(array, out, MSG_FOOR_42SH));
	fn_finish(array, out, pid);
}

static int		fn_test_exe(register t_string *root, register char *cmd,
register size_t n, register char **lp_arg)
{
	register size_t			tempos;
	t_string				ret;
	struct stat				st;

	ft_42sh_parsing_path(&ret, root, cmd, n);
	if (lstat(ret.buff, &st) == 0)
	{
		tempos = st.st_mode;
		if ((tempos & S_IFMT) == S_IFREG &&
		((tempos & S_IXUSR) | (tempos & S_IXGRP) | (tempos & S_IXOTH) != 0))
		{
			lp_arg[0] = ret.buff;
			return (1);
		}
		else
		{
			free(ret.buff);
			return (2);
		}
	}
	free(ret.buff);
	return (0);
}

void			ft_42sh_exe(register t_main_42sh *array,
register char **lp_arg, register char *cmd, register size_t n)
{
	register char			**spl;
	register t_write_buff	*out;
	register size_t			tempos;
	register uint_fast8_t	b_test;
	t_string				root;

	out = &array->out;
	if ((b_test = fn_test_exe(&array->pwd.path, cmd, n, lp_arg)) == 1)
		return (fn_exe(array, lp_arg));
	else if (b_test == 2)
		return (ft_42sh_dsp_msg_add_n(array, MSG_EXE_DEFINE_42SH, cmd, n));
	if ((spl = array->lp_spl_path) == 0)
		return (fn_not_find(array, out, cmd, n));
	while ((tempos = (size_t)spl++[0]) != 0)
	{
		root.buff = (char *)tempos;
		tempos = ft_strlen((char *)tempos);
		root.len = tempos;
		root.max_len = tempos;
		if ((b_test = fn_test_exe(&root, cmd, n, lp_arg)) == 1)
			return (fn_exe(array, lp_arg));
		else if (b_test == 2)
			return (ft_42sh_dsp_msg_add_n(array, MSG_EXE_DEFINE_42SH, cmd, n));
	}
	fn_not_find(array, out, cmd, n);
}
