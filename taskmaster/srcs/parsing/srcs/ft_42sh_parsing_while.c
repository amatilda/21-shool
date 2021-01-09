/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_while.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_parsing.h"

static void			*fn_skip(register unsigned char *b,
register unsigned char *e)
{
	while (b < e)
	{
		b = ft_42sh_parsing_sp(b, e);
		if (ft_42sh_parsing_litter_e(b, e) != 0)
			return (b);
		b++;
	}
	return (b);
}

static size_t		fn_exe(register t_main_42sh *array,
register t_in_42sh *list, unsigned char **out, register unsigned char *e)
{
	register unsigned char				*b;

	b = *out;
	ft_42sh_jobs_list_create_cmd(array, array->pr.lp_cmd, b);
	if (ft_42sh_exe(array, ft_42sh_parsing_litter_e_v(b, e)) == 0)
		return (1);
	b = ft_42sh_parsing_while_logic(array, *out, e);
	b = ft_42sh_parsing_litter_e_l(b, e);
	if (b < e && b[-1] == '\n')
	{
		ft_42sh_dq_test_hrdc(array, list,
		(unsigned char **)&array->dq.hrdoc_start_lp, b - 1);
		b = array->dq.hrdoc_start_lp;
	}
	*out = b;
	array->dq.hrdoc_next_lp = b;
	return (0);
}

static void			fn_set(register t_jobs_42sh *jobs,
register unsigned char *cmd)
{
	ft_42sh_jobs_list_set_type(jobs,
	(t_all_cmd_42sh **)jobs->path, cmd);
	jobs->lp_arg = (char **)cmd;
}

void				ft_42sh_parsing_while(register t_main_42sh *array,
register t_in_42sh *list, unsigned char *b, register unsigned char *e)
{
	register unsigned char			*cmd;
	register size_t					count;
	register t_jobs_42sh			*jobs;

	count = 0;
	while ((b = fn_skip(b, e)) < e)
	{
		jobs = ft_42sh_jobs_create_add_list(array, b, e, ++count);
		if ((cmd = ft_42sh_parsing_cmd(array, jobs, &b, e)) != 0)
		{
			if (ft_42sh_pipe_pre(array, list, array->pr.lp_cmd, e) != 0 &&
			cmd != (unsigned char *)1)
			{
				fn_set(jobs, cmd);
				ft_42sh_parsing_arg(array, jobs, &b, e);
			}
			else if (cmd != (unsigned char *)1)
				ft_free(cmd);
		}
		ft_42sh_parsing_while_error(array, jobs, &b, e);
		if (ft_42sh_parsing_litter_e(b, e) != 0)
			ft_42sh_jobs_list_create_cmd(array, array->pr.lp_cmd, ++b);
		else if ((count = fn_exe(array, list, &b, e)) != 0)
			return ;
	}
}
