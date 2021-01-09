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

void	ft_42sh_alias_pars_home(register t_main_42sh *array)
{
	char *tmp;
	char *home;

	if (!(array->pguitar.f_modif.home))
	{
		home = getlogin();
		tmp = ft_strjoin("/Users/", home);
		array->pguitar.f_modif.home = ft_strjoin(tmp, "/.42sh_am_pg");
		ft_free(tmp);
	}
}

char	*ft_42sh_alias_pars_value(register t_main_42sh *array,
		register char *arg, size_t *v_cnt)
{
	size_t	i;
	char	*tmp_arg;

	i = 0;
	if (*arg == '=')
		arg++;
	if (*arg == '\0')
	{
		*v_cnt = 0;
		return (NULL);
	}
	tmp_arg = arg;
	while (*arg && ++i)
	{
		if (*arg == '\n' && ++i)
			array->pguitar.f_modif.new_line++;
		arg++;
	}
	*v_cnt = i;
	return (tmp_arg);
}

char	*ft_42sh_alias_pars_name(register char *arg, size_t *n_cnt,
		register t_main_42sh *array)
{
	size_t	i;
	char	*tmp_arg;

	i = 0;
	tmp_arg = arg;
	while (*arg && *arg != '=' && ++i)
	{
		if (i == 1 && (*arg == '-' || *arg == '/' || *arg == '$'
			|| (*arg == '\\' && *(arg + 1) == '=')))
		{
			ft_42sh_dsp_err_msg_add_n(array,
				"alias: invalid alias name: ", tmp_arg, i);
			return (NULL);
		}
		arg++;
	}
	if (!ft_42sh_alias_pars_name_error(i, arg, tmp_arg, array))
		return (NULL);
	if (n_cnt)
		*n_cnt = i;
	return (arg);
}

void	ft_42sh_alias_pars_new_line(t_pguitar_alias_42sh *list,
		register char *arg, size_t i, size_t j)
{
	int k;

	k = i;
	while (j-- > 0)
	{
		if (arg[i] == '\n')
		{
			list->value[k++] = ' ';
			list->value[k] = '\n';
			j--;
		}
		else
			list->value[k] = arg[i];
		i++;
		k++;
	}
	list->value[k] = '\0';
}

void	ft_42sh_alias_fill_list(t_pguitar_alias_42sh *list,
		register char *arg, register char *lp_arg)
{
	size_t i;
	size_t j;

	i = 0;
	j = list->n_cnt;
	while (j-- > 0)
	{
		list->name[i] = lp_arg[i];
		i++;
	}
	list->name[i] = '\0';
	i = 0;
	j = list->v_cnt;
	if (!arg && list->v_cnt == 0)
	{
		list->value[0] = '\0';
		return ;
	}
	ft_42sh_alias_pars_new_line(list, arg, i, j);
}
