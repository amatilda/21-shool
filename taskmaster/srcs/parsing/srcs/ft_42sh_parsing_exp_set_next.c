/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_exp_set_next.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_parsing.h"

static void				*fn_set(register t_exp_set_42sh *exp_set,
register size_t count)
{
	register unsigned char			*cmd;

	cmd = exp_set->lp;
	cmd[count] = 0;
	return (cmd);
}

static void				*fn_finish(register t_jobs_42sh *jobs,
register unsigned char *cmd)
{
	ft_free(cmd);
	jobs->b_type = AUTO_TYPE_SET_42SH;
	return ((void *)1);
}

void					*ft_42sh_parsing_exp_set_next(register
t_replase_in_42sh *in, register t_jobs_42sh *jobs, unsigned char **out,
register unsigned char *e)
{
	register t_exp_set_42sh			*exp_set;
	register size_t					count;
	register unsigned char			*cmd;
	register unsigned char			*save;

	while (ft_42sh_parsing_litter_e_f(*out, e) != 0 &&
	ft_42sh_pipe_next(in->array, out, e) != 0)
		in->prs.pipe_count++;
	if (ft_42sh_parsing_litter_e_f(*out, e) == 0)
	{
		jobs->b_type = AUTO_TYPE_SET_42SH;
		return ((void *)1);
	}
	in->prs.start = *out;
	save = *out;
	count = ft_42sh_replase_count(in, &in->prs.start, out, e);
	if (in->array->pr.exit_pars.lp != 0)
		return (0);
	if ((exp_set = ft_malloc(sizeof(t_exp_set_42sh) + count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	cmd = fn_set(exp_set, count);
	ft_42sh_replase(in, cmd, save, e);
	if (ft_42sh_exp_test_exp(cmd, cmd + count) != 0)
		return (fn_finish(jobs, cmd));
	return (ft_42sh_parsing_cmd_ret(in, out, exp_set, count));
}
