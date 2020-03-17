/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_parsing.h"

static void		*fn_exp_set_next(register t_replase_in_42sh *in,
register t_jobs_42sh *jobs, unsigned char **out, register unsigned char *e)
{
	register t_exp_set_42sh			*exp_set;
	register size_t					count;
	register unsigned char			*cmd;

	while (ft_42sh_parsing_litter_e_f(*out, e) != 0 &&
	ft_42sh_pipe_next(in->array, out, e) != 0)
		in->prs.pipe_count++;
	if (ft_42sh_parsing_litter_e_f(*out, e) == 0)
	{
		jobs->b_type = AUTO_TYPE_SET_42SH;
		return ((void *)1);
	}
	in->prs.start = *out;
	count = ft_42sh_replase_count(in, &in->prs.start, out, e);
	if (in->array->pr.exit_pars.lp != 0)
		return (0);
	if ((exp_set = ft_malloc(sizeof(t_exp_set_42sh) + count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	cmd = exp_set->lp;
	cmd[count] = 0;
	if (ft_42sh_exp_test_exp(cmd, cmd + count) != 0)
	{
		ft_free(cmd);
		jobs->b_type = AUTO_TYPE_SET_42SH;
		return ((void *)1);
	}
	return (ft_42sh_parsing_cmd_ret(in, out, exp_set, count));
}

static void		*fn_exp_set(register t_replase_in_42sh *in,
register t_jobs_42sh *jobs, unsigned char **out, register unsigned char *e)
{
	register size_t					count;
	register unsigned char			*cmd;
	register t_exp_set_42sh			*exp_set;
	register t_exp_set_42sh			*exp_cur;

	in->prs.start = *out;
	exp_cur = jobs->exp_set;
	while ((count = ft_42sh_replase_count(in, &in->prs.start, out, e)) != 0)
	{
		if (in->array->pr.exit_pars.lp != 0)
			return (0);
		if ((exp_set = ft_malloc(sizeof(t_exp_set_42sh) + count + 1)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		cmd = exp_set->lp;
		cmd[count] = 0;
		ft_42sh_replase(in, cmd, in->prs.start, e);
		exp_set->next = 0;
		if (ft_42sh_exp_test_exp(cmd, cmd + count) == 0)
			return (ft_42sh_parsing_cmd_ret(in, out, exp_set, count));
		exp_set->n = count;
		exp_cur->next = exp_set;
		exp_cur = exp_set;
		in->prs.start = *out;
	}
	return (fn_exp_set_next(in, jobs, out, e));
}

static void		*fn_cmd(t_replase_in_42sh *in,
register t_jobs_42sh *jobs, unsigned char **out, register unsigned char *e)
{
	register size_t					count;
	register unsigned char			*cmd;
	register t_exp_set_42sh			*exp_set;

	in->prs.start = *out;
	count = ft_42sh_replase_count(in, &in->prs.start, out, e);
	if (in->array->pr.exit_pars.lp != 0)
		return (0);
	if ((exp_set = ft_malloc(sizeof(t_exp_set_42sh) + count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	cmd = exp_set->lp;
	cmd[count] = 0;
	ft_42sh_replase(in, cmd, in->prs.start, e);
	if (ft_42sh_exp_test_exp(cmd, cmd + count) == 0)
		return (ft_42sh_parsing_cmd_ret(in, out, exp_set, count));
	jobs->exp_set = exp_set;
	exp_set->next = 0;
	exp_set->n = count;
	return (fn_exp_set(in, jobs, out, e));
}

void			*ft_42sh_parsing_cmd(register t_main_42sh *array,
register t_jobs_42sh *jobs, unsigned char **out, register unsigned char *e)
{
	register unsigned char			*cmd;
	t_replase_in_42sh				in;

	array->pr.lp_cmd = *out;
	in.prs.pipe_count = 0;
	in.array = array;
	in.b_mode = PARSING_MODE_CMD_42SH;
	in.prs.jobs = jobs;
	in.prs.e = e;
	while (ft_42sh_parsing_litter_e_f(*out, e) != 0 &&
	ft_42sh_pipe_next(array, out, e) != 0)
		in.prs.pipe_count++;
	if (ft_42sh_parsing_litter_e_f(*out, e) == 0)
	{
		if ((cmd = ft_strndup("cat", 3)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		array->sh.lp_cmd = *out;
		if ((ft_42sh_parsing_while_availability(array, jobs, cmd, 3)) == 0)
			return (0);
		return (cmd);
	}
	in.b_mode = PARSING_MODE_ARG_42SH;
	return (fn_cmd(&in, jobs, out, e));
}
