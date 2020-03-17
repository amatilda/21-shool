/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_jobs_list_set_type.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_jobs.h"

void			ft_42sh_jobs_list_set_type(register t_jobs_42sh *jobs,
register t_all_cmd_42sh **spl, register void *cmd)
{
	register size_t				b_type;
	register void				*path;

	path = 0;
	if (spl != 0)
	{
		if (((b_type = spl[0]->b_type) & AUTO_TYPE_FUN_42SH) != 0)
			path = spl[0]->path;
		else if ((b_type & AUTO_TYPE_EXE_42SH) != 0)
		{
			if ((path = ft_42sh_path_join(spl[0]->path, cmd)) == 0)
				ft_42sh_exit(E_MEM_CODE_42SH);
		}
		else if ((b_type & AUTO_TYPE_HASH_42SH) != 0)
			if ((path = ft_strdup(spl[0]->path_hash)) == 0)
				ft_42sh_exit(E_MEM_CODE_42SH);
	}
	else
		b_type = AUTO_TYPE_EXE_42SH;
	jobs->b_type = b_type;
	jobs->path = path;
}
