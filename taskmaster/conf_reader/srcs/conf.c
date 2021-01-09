/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:09:40 by wstygg            #+#    #+#             */
/*   Updated: 2021/01/09 13:44:14 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf_reader.h"
#include "conf.h"

static char				**read_from_conf(const int fd)
{
	char				**ret;
	char				*str;

	ret = NULL;
	str = NULL;
	while (get_nl(fd, &str) == 1)
		ret = add_to_text(ret, str);
	close(fd);
	if (!ret)
		ft_error("File is empty!");
	return (ret);
}

static void				check_logs(char *str, int *i)
{
	char				**split;

	if (!str)
		return ;
	split = ft_splitstr(str);
	if (ft_split_size(split) != 2)
		return ;
	if (!strcmp(split[0], "log_path:"))
	{
		if (!strcmp(split[1], "null"))
			log_reopen(NULL);
		else
			log_reopen(split[1]);
		(*i)++;
	}
	else
		log_reopen(TASK_LOG_DEFAULT_PATH);
	ft_free_split(split);
}

static t_list			*get_tasks(char **conf)
{
	t_list				*ret;
	int					i;

	i = -1;
	ret = NULL;
	check_logs(conf[0], &i);
	while (conf[++i])
	{
		if (str_is_empty(conf[i]))
			continue ;
		ret = list_add_back(ret, create_task(conf, &i, ret));
	}
	while (--i != -1)
		free(conf[i]);
	free(conf);
	return (ret);
}

t_list					*conf_read(const char *path)
{
	char				**conf;
	int					conf_fd;
	t_list				*task_list;

	if ((conf_fd = open_conf(path)) < 0)
		return (NULL);
	if (!(conf = read_from_conf(conf_fd)))
		return (NULL);
	if (!(task_list = get_tasks(conf)))
		ft_error("No tasks in %s!", path);
	return (task_list);
}
