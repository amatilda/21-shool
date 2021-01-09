/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 12:52:19 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/18 16:02:32 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf_reader.h"
#include "conf.h"

static void			*splitr(char **split, void *ret)
{
	ft_free_split(split);
	return (ret);
}

static char			*read_content(char *content, int i)
{
	char			*ret;
	char			**split;

	split = ft_splitstr(content);
	if (split[0][strlen(split[0]) - 1] != ':')
	{
		ft_error("Error at [%d] line: %s\n\':\' symbol have to be in the end "
				"of %s!\n", i + 1, content, split[0]);
		return (splitr(split, NULL));
	}
	split[0][strlen(split[0]) - 1] = '\0';
	if (!split[1])
	{
		ft_error("Error at [%d] line: %s\nNo content after \"%s\"!\n", i + 1,
				content, split[0]);
		return (splitr(split, NULL));
	}
	if (ft_split_size(split) > 2)
	{
		ft_error("Error at [%d] line: %s\nThere have to be only one content "
				"after \"%s\"!\n", i + 1, content, split[0]);
		return (splitr(split, NULL));
	}
	ret = my_strjoin(my_strjoin(split[0], "=", 0), split[1], 1);
	return (splitr(split, ret));
}

static int			count_content(char **conf, int i)
{
	int				ret;

	ret = 0;
	while (tab_count(conf[i++]) == 2)
		ret++;
	return (ret);
}

void				create_env(t_task *task, char **c, int *i)
{
	char			*content;
	char			**split;
	char			**env;
	register int	k;

	split = ft_splitstr(c[*i]);
	if (ft_split_size(split) != 1 && ft_error("Error at [%d] line: %s\nContent"
	" for env should have 2 tab depth!\n", *i + 1, c[*i]))
		return (ft_free_split(split));
	k = -1;
	env = my_malloc(sizeof(char *) * (count_content(c, *i + 1) + 1));
	while (c[++(*i)] && (tab_count(c[*i]) == 2 || str_is_empty(c[*i])))
	{
		if (str_is_empty(c[*i]))
			continue ;
		if ((content = read_content(c[*i], *i)))
			env[++k] = content;
	}
	if (!env[0] && ft_error("Env content not provided!\n"))
		free(env);
	else
		task->env = env;
	(*i)--;
	ft_free_split(split);
}
