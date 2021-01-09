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

static void	ft_42sh_alias_read_create_list(t_pguitar_alias_42sh
*lp_alias, t_pguitar_alias_42sh **lp_first)
{
	void *lp_n;
	void *lp_new;

	lp_n = lp_alias->lp;
	lp_new = (*lp_first)->lp;
	(*lp_first)->name = lp_new;
	ft_memcpy(lp_new, lp_n, lp_alias->n_cnt + 1);
	lp_n += lp_alias->n_cnt + 1;
	lp_new += lp_alias->n_cnt + 1;
	(*lp_first)->value = lp_new;
	ft_memcpy(lp_new, lp_n, lp_alias->v_cnt + 1);
	(*lp_first)->n_cnt = lp_alias->n_cnt;
	(*lp_first)->v_cnt = lp_alias->v_cnt;
	(*lp_first)->n_quote = lp_alias->n_quote;
	(*lp_first)->v_quote = lp_alias->v_quote;
	(*lp_first)->new_line = lp_alias->new_line;
}

static void	ft_42sh_alias_read_cycle(t_pguitar_alias_42sh *lp_alias,
t_pguitar_alias_42sh **lp_first, register t_main_42sh *array)
{
	t_pguitar_alias_42sh *lp_prev;

	lp_prev = 0;
	while (0xFF)
	{
		if (!((*lp_first) = ft_malloc(sizeof(t_pguitar_alias_42sh) +
			lp_alias->v_cnt + lp_alias->n_cnt + 2)))
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
		ft_42sh_alias_read_create_list(lp_alias, lp_first);
		if (!(array->pguitar.list))
			array->pguitar.list = (*lp_first);
		if (lp_prev != 0)
			lp_prev->next = (*lp_first);
		if (lp_alias->next == 0)
			break ;
		lp_prev = (*lp_first);
		lp_alias = ((void *)lp_alias) + sizeof(t_pguitar_alias_42sh) +
			lp_alias->v_cnt + lp_alias->n_cnt + 2;
		(*lp_first) = (*lp_first)->next;
	}
	(*lp_first)->next = NULL;
}

static void	ft_42sh_alias_read_file_offset(void **lp,
register t_main_42sh *array)
{
	size_t						tempos;
	t_pguitar_alias_42sh		*lp_alias;
	t_pguitar_alias_42sh		*lp_first;

	tempos = ((t_pguitar_alias_file_42sh*)(*lp))->offset_alias;
	lp_alias = (t_pguitar_alias_42sh*)((*lp) + tempos);
	ft_42sh_alias_read_cycle(lp_alias, &lp_first, array);
}

static void	ft_42sh_alias_read_close_fd(int fd, int free_lp, void *lp)
{
	close(fd);
	if (free_lp == 1)
		ft_free(lp);
}

void		ft_42sh_alias_read_file(register t_main_42sh *array,
int fd)
{
	struct stat	st;
	void		*lp;

	if ((fd = open(array->pguitar.f_modif.home, O_RDONLY)) < 0)
		return ;
	array->pguitar.f_modif.file = 1;
	stat(array->pguitar.f_modif.home, &st);
	if (st.st_size > 1048576 || st.st_size == 0)
		return (ft_42sh_alias_read_close_fd(fd, 0, NULL));
	if (!(lp = ft_malloc(st.st_size)))
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	if (read(fd, lp, st.st_size) < 0)
	{
		ft_42sh_alias_read_close_fd(fd, 1, lp);
		return (ft_42sh_dsp_err_msg(array,
			WAR_PR_42SH": could not open file"PRTF_RESET));
	}
	if (((t_pguitar_alias_file_42sh*)lp)->crc32 !=
	ft_crc32_mirror_one(array->lp_crc32_mirror, (unsigned char*)((lp +
	sizeof(((t_pguitar_alias_file_42sh*)lp)->crc32))), st.st_size -
	sizeof(((t_pguitar_alias_file_42sh*)lp)->crc32), CRC32_START_MIRROR_42SH))
		return (ft_42sh_alias_read_close_fd(fd, 1, lp));
	ft_42sh_alias_read_file_offset(&lp, array);
	ft_free(lp);
	close(fd);
}
