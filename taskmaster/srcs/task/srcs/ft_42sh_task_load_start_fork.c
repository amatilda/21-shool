/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_load_start_fork.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static void		exit_task(register t_task *task, int exit_code)
{
	char			*b;

	if (exit_code == TASK_EXIT_FORK_STATUS_FAIL_DUP)
		b = "dup2";
	else if (exit_code == TASK_EXIT_FORK_STATUS_FAIL_ENV)
		b = "env";
	else if (exit_code == TASK_EXIT_FORK_STATUS_FAIL_EXECVE)
		b = "execve";
	else if (exit_code == TASK_EXIT_FORK_STATUS_FAIL_PTRACE)
		b = "ptrace";
	else if (exit_code == TASK_EXIT_FORK_STATUS_FAIL_CHDIR)
		b = "chdir";
	else
		b = "unknown";
	task_log("[%s] "TASK_LOG_ERROR" %s\n", task->name, b);
	exit(exit_code);
}

static void		fn_fork_fd(register t_task *task, register t_task_load_fd *fds)
{
	int								fd_null;

	fd_null = fds->fd_null;
	if (fds->fd_err == -1)
		if ((fds->fd_err = dup(fd_null)) == -1)
			exit_task(task, TASK_EXIT_FORK_STATUS_FAIL_DUP);
	if (fds->fd_out == -1)
		if ((fds->fd_out = dup(fd_null)) == -1)
			exit_task(task, TASK_EXIT_FORK_STATUS_FAIL_DUP);
	if (dup2(fd_null, STDIN_FILENO) == -1)
		exit_task(task, TASK_EXIT_FORK_STATUS_FAIL_DUP);
	if (dup2(fds->fd_out, STDOUT_FILENO) == -1)
		exit_task(task, TASK_EXIT_FORK_STATUS_FAIL_DUP);
	if (dup2(fds->fd_err, STDERR_FILENO) == -1)
		exit_task(task, TASK_EXIT_FORK_STATUS_FAIL_DUP);
	close(fd_null);
	close(fds->fd_out);
	close(fds->fd_err);
	fd_null = FD_MAX_STANDART_42SH + 1;
	while (fd_null <= FD_MAX_SUPPORT_42SH)
		close(fd_null++);
	close(FD_TERMINAL_42SH);
	if (get_log()->fd)
		fclose(get_log()->fd);
}

void			ft_42sh_task_load_start_fork(register t_main_42sh *array,
register t_task *task, register t_task_load_fd *fds, register char **arg)
{
	register char				**env_spl;

	fn_fork_fd(task, fds);
	if (task->directory != 0)
		if (chdir(task->directory) == -1)
			exit_task(task, TASK_EXIT_FORK_STATUS_FAIL_CHDIR);
	ft_42sh_signal_default(array, 0);
	if (ft_42sh_cm_export_set_task(array, task->env) == 0)
		exit_task(task, TASK_EXIT_FORK_STATUS_FAIL_ENV);
	env_spl = ft_42sh_exp_split_env(array, TASK_EXIT_FORK_STATUS_FAIL_ENV);
	umask(task->umask);
	errno = 0;
	if (ptrace(PT_TRACE_ME, 0, 0, 0) == -1 && errno != 0)
		exit_task(task, TASK_EXIT_FORK_STATUS_FAIL_PTRACE);
	execve(arg[0], arg, env_spl);
	exit_task(task, TASK_EXIT_FORK_STATUS_FAIL_EXECVE);
}