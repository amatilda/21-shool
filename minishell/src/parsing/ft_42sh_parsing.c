/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void		fn_free(register char *b, register char **lp_arg,
register char **tmp)
{
	free(b);
	if ((b = lp_arg[0]) != 0)
		free(b);
	while ((b = tmp++[0]) != 0)
		free(b);
	free(lp_arg);
}

static void		fn_command(register t_main_42sh *array, t_fun_42sh *fun,
register char *b, register size_t n)
{
	register char			**tmp;
	register char			*name;
	register char			**lp_arg;

	lp_arg = array->lp_arg;
	tmp = lp_arg + 1;
	while ((name = fun[0].name) != 0)
	{
		if (n == fun[0].count && ft_strncmp(b, name, n) == 0)
		{
			fun[0].f(array, tmp);
			break ;
		}
		fun++;
	}
	if (name == 0)
		ft_42sh_exe(array, lp_arg, b, n);
	fn_free(b, lp_arg, tmp);
}

static void		fn_parsing_command_grup(register t_main_42sh *array,
t_fun_42sh *fun, unsigned char *b, register unsigned char *end)
{
	register t_string		*cmd;
	size_t					tempos;

	cmd = &array->cmd;
	while (b < end)
	{
		ft_42sh_parsing_cmd(array, cmd, &b, end);
		if (cmd->max_len != 0 && cmd->buff[cmd->max_len] != 'F')
			ft_42sh_exit(E_EXE_CODE_42SH);
		tempos = cmd->len;
		ft_42sh_parsing_arg(array, &b, end, tempos);
		if (tempos != 0)
			fn_command(array, fun, cmd->buff, cmd->len);
	}
}

void			ft_42sh_parsing(register t_main_42sh *array,
register t_in_42sh *list)
{
	register t_in_42sh			*parser;
	register unsigned char		*tmp;

	array->tab.b_view = 0;
	if ((parser = array->in_dquote) == 0)
		parser = list;
	else
		array->in_dquote = 0;
	tmp = (unsigned char *)parser->lp_b;
	fn_parsing_command_grup(array, g_cmd_array, tmp, tmp + parser->count);
	ft_42sh_init_out(array, list, 0);
	ft_42sh_dsp_start(array);
}
