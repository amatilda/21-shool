/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <wstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 23:06:35 by wstygg            #+#    #+#             */
/*   Updated: 2020/06/18 16:12:34 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conf.h"

static int		check_extension(const char *path)
{
	const unsigned long long	path_len = path ? strlen(path) : 0;
	const unsigned long long	ex_len = strlen(TASK_FILE_EXTENSION);
	register unsigned int		i;
	register unsigned int		j;

	if (ex_len + 1 > path_len)
		return (0);
	j = 0;
	i = path_len - ex_len;
	while (i < path_len)
	{
		if (path[i] != TASK_FILE_EXTENSION[j])
			return (0);
		j++;
		i++;
	}
	return (1);
}

int				open_conf(const char *path)
{
	int							ret;

	if (!path)
		return (ft_error("Bad path provided - %s!\n", path));
	if (!check_extension(path))
	{
		return (ft_error("You provided not a *%s file - %s!",
				TASK_FILE_EXTENSION, path));
	}
	if (check_file(path, IS_E) <= 0)
		return (ft_error("No such file - %s!\n", path));
	if ((ret = open(path, O_RDONLY)) < 0)
		return (ft_error("Can't open that file for read - %s!", path));
	if (!check_file(path, IS_R))
	{
		close(ret);
		return (ft_error("Can't read from that file - %s!", path));
	}
	if (check_file(path, IS_D))
	{
		close(ret);
		return (ft_error("It's a directory - %s!", path));
	}
	return (ret);
}
