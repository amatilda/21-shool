/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguitar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:07:32 by pguitar           #+#    #+#             */
/*   Updated: 2020/01/19 16:07:38 by pguitar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_alias.h"

size_t			ft_42sh_alias_pars_name_error(size_t i, char *arg,
				char *tmp_arg, register t_main_42sh *array)
{
	if (!i && *arg == '=' && *(arg + 1) == '=')
	{
		ft_42sh_dsp_err_msg_add_n(array,
			"alias: not found: ", tmp_arg, 1);
		return (0);
	}
	if (!i)
	{
		ft_42sh_dsp_err_msg_add_n(array,
			"alias: not found: ", tmp_arg, 0);
		return (0);
	}
	if (*arg != '=')
		return (0);
	return (1);
}

static size_t	ft_42sh_alias_pars_dsp_write(t_main_42sh *array,
register t_pguitar_alias_42sh *list)
{
	if (list->n_quote)
	{
		ft_write_buffer_str_zero(&array->out, "'");
		ft_write_buffer_str_zero(&array->out, list->name);
		ft_write_buffer_str_zero(&array->out, "'");
	}
	else
		ft_write_buffer_str_zero(&array->out, list->name);
	ft_write_buffer_str_zero(&array->out, "=");
	if (list->v_cnt == 0)
		ft_write_buffer_str_zero(&array->out, "''");
	else if (list->v_quote)
	{
		ft_write_buffer_str_zero(&array->out, "'");
		ft_42sh_alias_pars_dsp_write_v(array, list);
		ft_write_buffer_str_zero(&array->out, "'");
	}
	else
		ft_42sh_alias_pars_dsp_write_v(array, list);
	ft_write_buffer_str_zero(&array->out, "\n");
	return (1);
}

void			ft_42sh_alias_pars_dsp_all(t_main_42sh *array)
{
	register t_pguitar_alias_42sh *list;

	list = array->pguitar.list;
	if (ft_42sh_pipe_test_fd_dsp(array, STDOUT_FILENO, "alias") == 0)
		return ;
	while (list)
	{
		ft_42sh_alias_pars_dsp_write(array, list);
		list = list->next;
	}
}

static char		*ft_42sh_alias_pars_name_dsp(register char *arg, size_t *n_cnt)
{
	size_t	i;
	char	*tmp_arg;

	i = 0;
	tmp_arg = arg;
	while (*arg && *arg != '=' && ++i)
	{
		if (i == 1 && (*arg == '-' || *arg == '/' || *arg == '$'
			|| (*arg == '\\' && *(arg + 1) == '=')))
			return (NULL);
		arg++;
	}
	if (*arg != '=' || !i)
		return (NULL);
	if (n_cnt)
		*n_cnt = i;
	return (arg);
}

void			ft_42sh_alias_pars_dsp_one(char **lp_arg, t_main_42sh *array)
{
	register t_pguitar_alias_42sh *list;

	list = array->pguitar.list;
	while (*lp_arg)
	{
		if (ft_42sh_alias_pars_name_dsp(*lp_arg, NULL))
		{
			lp_arg++;
			continue ;
		}
		while (list)
		{
			if (!ft_strncmp(*lp_arg, list->name, list->n_cnt)
				&& *(*lp_arg + list->n_cnt) == '\0' &&
				ft_42sh_alias_pars_dsp_write(array, list))
				break ;
			list = list->next;
		}
		list = array->pguitar.list;
		lp_arg++;
	}
}
