/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task_test_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_task.h"

static char			**fn_pre(register t_task *task, register void *b,
register size_t n)
{
	register char					**arg;

	if (n == 0)
		return (0);
	if ((arg = ft_42sh_task_arguments(ft_malloc(n) ,b , b + n)) == 0)
		return (ft_42sh_task_test_path_error_log(task, 0, 0, 0));
	return (arg);
}

static char			**fn_finish_good(register char **arg,
register void *b, register void *tmp)
{
	ft_free(b);
	arg[0] = tmp;
	return (arg);
}

char				**ft_42sh_task_test_path(register t_main_42sh *array,
register t_task *task, register void *b, register size_t n)
{
	register t_all_cmd_42sh			**spl;
	register void					*tmp;
	register char					**arg;

	if ((arg = fn_pre(task, b, n)) <= (char **)1)
		return (arg);
	b = arg[0];
	n = ft_strlen(b);
	if (ft_42sh_parsing_path_test((char *)b, (char *)b + n) != 0)
	{
		if (ft_42sh_task_test_path_availability(b) == 0)
			return (ft_42sh_task_test_path_error_log(task, b, 0, arg));
		if ((tmp = ft_strndup(b, n)) == 0)
			return (ft_42sh_task_test_path_error_log(task, 0, 0, arg));
		return (fn_finish_good(arg, b, tmp));
	}
	if ((size_t)(spl = ft_42sh_task_test_path_test_cmd(array, task, b, n)) <= 1)
		return (ft_42sh_task_test_path_error_log(task, b, 1, arg));
	tmp = spl[0]->path;
	if ((tmp = ft_42sh_path_join(tmp, b)) == 0)
		return (ft_42sh_task_test_path_error_log(task, 0, 0, arg));
	return (fn_finish_good(arg, b, tmp));
}
