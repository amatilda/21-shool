/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_free_all_cmd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		ft_42sh_auto_free_list(register t_all_cmd_42sh *list)
{
	if ((list->b_type & AUTO_TYPE_HASH_42SH) != 0)
		ft_free(list->path_hash);
	ft_free(list);
}

void		ft_42sh_auto_free_all_cmd(register t_main_42sh *array)
{
	register t_all_cmd_42sh		**spl;
	register t_all_cmd_42sh		**tmp;
	register t_all_cmd_42sh		*list;

	spl = array->lp_auto->spl_all_cmd;
	tmp = spl;
	while ((list = spl++[0]) != 0)
		ft_42sh_auto_free_list(list);
	ft_free(tmp);
	array->lp_auto->all_cmd.first = 0;
}
