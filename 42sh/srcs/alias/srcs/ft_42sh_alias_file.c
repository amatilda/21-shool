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

static void		ft_42sh_alias_write_lists(register
t_pguitar_alias_42sh *list, char **lp_r)
{
	while (list)
	{
		ft_memcpy(*lp_r, list, sizeof(t_pguitar_alias_42sh) +
			list->n_cnt + list->v_cnt + 2);
		*lp_r = *lp_r + sizeof(t_pguitar_alias_42sh) + list->n_cnt
			+ list->v_cnt + 2;
		list = list->next;
	}
}

static size_t	ft_42sh_alias_size_lists(register
t_pguitar_alias_42sh *list)
{
	size_t i;

	i = 0;
	while (list)
	{
		i += sizeof(t_pguitar_alias_42sh) + list->n_cnt + list->v_cnt + 2;
		list = list->next;
	}
	return (i);
}

size_t			ft_42sh_alias_file_init(t_pguitar_alias_file_42sh **file,
size_t *i, char **lp_r, register t_main_42sh *array)
{
	if (array->pguitar.f_modif.file && !array->pguitar.f_modif.modif)
		return (1);
	if (!(array->pguitar.list) && array->pguitar.f_modif.del_file)
	{
		unlink(array->pguitar.f_modif.home);
		return (1);
	}
	else if (!(array->pguitar.list))
		return (1);
	if (!(*file = malloc(sizeof(t_pguitar_alias_file_42sh) + *i)))
		ft_42sh_exit(E_MEM_CODE_42SH);
	ft_memset(*file, 'F', sizeof(t_pguitar_alias_file_42sh) + *i);
	(*file)->offset_alias = (*file)->lp - (char *)(*file);
	(*file)->size_alias = *i;
	*lp_r = (void *)(*file)->lp;
	return (0);
}

void			ft_42sh_alias_file(register t_main_42sh *array)
{
	int							fd;
	size_t						i;
	char						*lp_r;
	t_pguitar_alias_42sh		*list;
	t_pguitar_alias_file_42sh	*file;

	list = array->pguitar.list;
	i = ft_42sh_alias_size_lists(list);
	if (ft_42sh_alias_file_init(&file, &i, &lp_r, array))
		return ;
	ft_42sh_alias_write_lists(list, &lp_r);
	if ((fd = open(array->pguitar.f_modif.home, O_CREAT | O_TRUNC | O_RDWR,
		S_IWUSR | S_IRUSR)) < 0)
	{
		free(file);
		return (ft_42sh_dsp_err_msg(array,
			WAR_PR_42SH": could not open file"PRTF_RESET));
	}
	file->crc32 = ft_crc32_mirror_one(array->lp_crc32_mirror, (unsigned char*)
	(((void *)file) + sizeof(file->crc32)), (sizeof(t_pguitar_alias_file_42sh)
	+ i) - sizeof(file->crc32), CRC32_START_MIRROR_42SH);
	write(fd, file, sizeof(t_pguitar_alias_file_42sh) + i);
	close(fd);
	free(file);
}
