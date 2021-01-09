/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_save_file.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_list_in.h"

char				*ft_42sh_list_in_save_get_path(void)
{
	char					*home;
	char					*tmp;

	if ((home = getlogin()) != 0)
	{
		if ((tmp = ft_strjoin("/Users/", home)) != 0)
		{
			home = ft_strjoin(tmp, "/.42sh_am_pg_fc");
			ft_free(tmp);
			return (home);
		}
	}
	return (0);
}

static void			fn_save_file(t_in_save_42sh *b, char *home)
{
	int							fd;

	if ((fd = open(home, O_CREAT | O_TRUNC | O_RDWR, S_IWUSR | S_IRUSR)) < 0)
		return ;
	write(fd, b, b->len);
	close(fd);
}

void				ft_42sh_list_in_save_file(t_in_save_42sh *b)
{
	char					*home;

	if ((home = ft_42sh_list_in_save_get_path()) == 0)
		return ;
	fn_save_file(b, home);
	ft_free(b);
	ft_free(home);
}
