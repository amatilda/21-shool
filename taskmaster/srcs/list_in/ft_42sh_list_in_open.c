/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_list_in_open.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_list_in.h"
#include <stdbool.h>

static size_t			fn_faill(void *b)
{
	ft_free(b);
	return (false);
}

static size_t			fn_read_fc(register t_main_42sh *array,
register int fd, register t_in_save_42sh *b, register size_t len)
{
	register uint8_t				*tmp;
	register size_t					crc32;

	if (read(fd, b, len) != (ssize_t)len)
	{
		close(fd);
		return (fn_faill(b));
	}
	close(fd);
	if (b->len != len || b->version != VERSION_LIST_42SH)
		return (fn_faill(b));
	ft_42sh_list_in_save_crypto((uint8_t *)b, len);
	crc32 = b->crc32;
	b->crc32 = 0;
	if (ft_crc32_mirror_one(array->lp_crc32_mirror, b, len,
	CRC32_START_MIRROR_42SH) != crc32)
	{
		return (fn_faill(b));
	}
	tmp = (uint8_t *)b;
	crc32 = ft_42sh_list_in_builf_is_file(array, tmp + sizeof(t_in_save_42sh),
	tmp + (len - sizeof(t_in_save_42sh)));
	ft_free(b);
	return (crc32);
}

static size_t			fn_open_fc(register t_main_42sh *array)
{
	register int						fd;
	register char						*home;
	struct stat							st;

	if ((home = ft_42sh_list_in_save_get_path()) == 0)
		return (false);
	if ((fd = open(home, O_RDONLY)) < 0)
		return (fn_faill(home));
	if (stat(home, &st) != 0 || (st.st_mode & S_IFMT) != S_IFREG ||
	st.st_size == 0 || st.st_size > 0x8000000)
	{
		close(fd);
		return (fn_faill(home));
	}
	ft_free(home);
	if ((home = malloc(st.st_size)) == 0)
	{
		close(fd);
		return (false);
	}
	return (fn_read_fc(array, fd, (t_in_save_42sh *)home, st.st_size));
}

void					ft_42sh_list_in_open(register t_main_42sh *array)
{
	if (fn_open_fc(array) == true)
		return ;
	ft_42sh_list_in_create(array, BUFFER_READ_42SH);
}
