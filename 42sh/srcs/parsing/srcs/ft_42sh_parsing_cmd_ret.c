/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_cmd_ret.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_parsing.h"

static void	fn_write(register t_exp_set_42sh *exp_set,
register unsigned char *out, register unsigned char *e)
{
	register unsigned char			litter;
	register unsigned char			*b;

	b = exp_set->lp;
	while (b < e)
	{
		if ((litter = b++[0]) == '\n')
		{
			out[0] = '\\';
			out[1] = 'n';
			out += 2;
		}
		else
			out++[0] = litter;
	}
}

static void	*fn_cmd_view_correction(register t_replase_in_42sh *in,
register t_exp_set_42sh *exp_set, register unsigned char *e,
register size_t count)
{
	register unsigned char			*out;

	if ((out = ft_malloc(count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	out[count] = 0;
	fn_write(exp_set, out, e);
	ft_free(exp_set);
	if ((ft_42sh_parsing_while_availability(in->array, in->prs.jobs,
	out, count)) == 0)
		return (0);
	return (out);
}

static void	*fn_cmd_view(register t_replase_in_42sh *in,
register t_exp_set_42sh *exp_set, register size_t count)
{
	register unsigned char			*b;
	register unsigned char			*e;
	register size_t					save;

	b = exp_set->lp;
	save = count;
	e = b + count;
	while (b < e)
		if (b++[0] == '\n')
			count++;
	if (save == count)
	{
		ft_memcpy(exp_set, exp_set->lp, count + 1);
		if ((ft_42sh_parsing_while_availability(in->array, in->prs.jobs,
		(void *)exp_set, count)) == 0)
			return (0);
		return (exp_set);
	}
	return (fn_cmd_view_correction(in, exp_set, e, count));
}

static void	*fn_ret(register t_replase_in_42sh *in)
{
	register unsigned char			*cmd;

	if (in->prs.jobs->exp_set != 0)
	{
		in->prs.jobs->b_type = AUTO_TYPE_SET_42SH;
		return ((void *)1);
	}
	if (in->prs.pipe_count == 0)
		return (0);
	if ((cmd = ft_strndup("cat", 3)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
	if ((ft_42sh_parsing_while_availability(in->array, in->prs.jobs,
	cmd, 3)) == 0)
		return (0);
	return (cmd);
}

void		*ft_42sh_parsing_cmd_ret(register t_replase_in_42sh *in,
unsigned char **out, register t_exp_set_42sh *exp_set, register size_t count)
{
	register unsigned char			*cmd;

	in->array->sh.lp_cmd = in->prs.start;
	if (in->prs.start == *out)
	{
		ft_free(exp_set);
		while (ft_42sh_parsing_litter_e_f(*out, in->prs.e) != 0 &&
		ft_42sh_pipe_next(in->array, out, in->prs.e) != 0)
			in->prs.pipe_count++;
		if (ft_42sh_parsing_litter_e_f(*out, in->prs.e) == 0)
			return (fn_ret(in));
		in->prs.start = *out;
		count = ft_42sh_replase_count(in, &in->prs.start, out, in->prs.e);
		if (in->array->pr.exit_pars.lp != 0)
			return (0);
		if ((exp_set = ft_malloc(sizeof(t_exp_set_42sh) + count + 1)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH);
		cmd = exp_set->lp;
		cmd[count] = 0;
		ft_42sh_replase(in, cmd, in->prs.start, in->prs.e);
		return (ft_42sh_parsing_cmd_ret(in, out, exp_set, count));
	}
	return (fn_cmd_view(in, exp_set, count));
}
