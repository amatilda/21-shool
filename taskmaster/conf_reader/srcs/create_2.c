/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:08:52 by wstygg            #+#    #+#             */
/*   Updated: 2021/01/09 13:51:11 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf_reader.h"
#include "conf.h"

int					create_on_start(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_splitstr(conf);
	if (!split[1])
	{
		ft_error("Error at [%d] line:\n%s\nNo content after \"on_start\" "
				"keyword!\n", i + 1, conf);
		ft_free_split(split);
		return (1);
	}
	if (ft_split_size(split) > 2)
	{
		ft_error("Error at [%d] line:\n%s\nThere have to be only one content "
					"after \"on_start\" keyword!\n", i + 1, conf);
		ft_free_split(split);
		return (1);
	}
	ret = my_atoi(split[1]);
	if (ret != 0 && ret != 1 && (ret = 1))
		ft_error("Error at [%d] line:\n%s\nOn_start flag have to be 1(true) or"
		" 0(false)!\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}

int					create_restart(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_splitstr(conf);
	if (!split[1])
	{
		ft_error("Error at [%d] line:\n%s\nNo content after \"restart\" "
			"keyword!\n", i + 1, conf);
		ft_free_split(split);
		return (2);
	}
	if (ft_split_size(split) > 2)
	{
		ft_error("Error at [%d] line:\n%s\nThere have to be only one content"
			" after \"restart\" keyword!\n", i + 1, conf);
		ft_free_split(split);
		return (2);
	}
	ret = my_atoi(split[1]);
	if ((ret < 0 || ret > 3) && (ret = 2))
		ft_error("Error at [%d] line:\n%s\nRestart flag have to be a value"
		" between 0 and 3 inclusive!\n    0 - Never\n    1 - Always\n"
		"    2 - On crash\n    3 - On good\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}

int					create_retries(char *conf, int i)
{
	int				ret;
	char			**split;

	split = ft_splitstr(conf);
	if (!split[1])
	{
		ft_error("Error at [%d] line:\n%s\nNo content after \"retries\""
			" keyword!\n", i + 1, conf);
		ft_free_split(split);
		return (1);
	}
	if (ft_split_size(split) > 2)
	{
		ft_error("Error at [%d] line:\n%s\nThere have to be only one "
			"content after \"retries\" keyword!\n", i + 1, conf);
		ft_free_split(split);
		return (1);
	}
	ret = my_atoi(split[1]);
	if ((ret < 0 || ret > 999) && (ret = 1))
		ft_error("Error at [%d] line:\n%s\nRetries have to be positive"
				" integer number less than  1000!\n", i + 1, conf);
	ft_free_split(split);
	return (ret);
}

char				*create_stdout(char *conf, int i, char *current)
{
	char			*ret;
	char			**split;

	split = ft_splitstr(conf);
	if (!split[1])
	{
		ft_error("Error at [%d] line:\n%s\nNo content after \"stdout\" "
				"keyword!\n", i + 1, conf);
		ft_free_split(split);
		return (current);
	}
	else if (ft_split_size(split) > 2)
	{
		ft_error("Error at [%d] line:\n%s\nThere have to be only one content"
				" after \"stdout\" keyword!\n", i + 1, conf);
		ft_free_split(split);
		return (current);
	}
	if (!strcmp(split[1], "stderr"))
		ret = (char*)1;
	else if (!(ret = strdup(split[1])))
		ft_crash("Strdup malloc error!\n");
	ft_free_split(split);
	return (ret);
}

char				*create_stderr(char *conf, int i, char *current)
{
	char			*ret;
	char			**split;

	split = ft_splitstr(conf);
	if (!split[1])
	{
		ft_error("Error at [%d] line:\n%s\nNo content after \"stderr\" "
					"keyword!\n", i + 1, conf);
		ft_free_split(split);
		return (current);
	}
	else if (ft_split_size(split) > 2)
	{
		ft_error("Error at [%d] line:\n%s\nThere have to be only one content"
					" after \"stderr\" keyword!\n", i + 1, conf);
		ft_free_split(split);
		return (current);
	}
	if (!strcmp(split[1], "stdout"))
		ret = (char*)1;
	else if (!(ret = strdup(split[1])))
		ft_crash("Strdup malloc error!\n");
	ft_free_split(split);
	return (ret);
}
