/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_main_42sh			*g_lp_array;

t_fun_42sh	g_cmd_array[] =
{
	{"env", 3, &ft_42sh_cm_env},
	{"cd", 2, &ft_42sh_cm_cd},
	{"clear", 5, &ft_42sh_cm_clear},
	{"unsetenv", 8, &ft_42sh_cm_unsetenv},
	{"setenv", 6, &ft_42sh_cm_setenv},
	{"exit", 4, &ft_42sh_cm_exit},
	{"echo", 4, &ft_42sh_cm_echo}, {0, 0, 0}
};

int			main(int argc, char **argv, char **env)
{
	static t_main_42sh		array;

	if (isatty(STDOUT_FILENO) == 0)
	{
		write(STDERR_FILENO, E_TERM_42SH, LEN_(E_TERM_42SH));
		return (0);
	}
	g_lp_array = &array;
	ft_42sh_init(&array);
	ft_42sh_env_start(&array, env);
	ft_42sh_auto_create(&array);
	ft_42sh_signal_initilization();
	ft_42sh_read(&array);
	return (0);
	(void)argc;
	(void)argv;
}
