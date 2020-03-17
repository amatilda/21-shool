/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_parsing_while_error.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_parsing.h"

void	ft_42sh_parsing_while_error(register t_main_42sh *array,
register t_jobs_42sh *jobs, unsigned char **out, register unsigned char *e)
{
	register unsigned char		*msg;
	register unsigned char		*tmp;
	register unsigned char		*lp_cmd;
	register size_t				b_type;

	lp_cmd = *out;
	ft_42sh_parsing_end(array, out, e, ft_42sh_parsing_litter_e_f);
	if ((msg = array->pr.exit_pars.lp) == 0)
		return ;
	array->pr.exit_pars.lp = 0;
	if (((b_type = jobs->b_type) & AUTO_TYPE_ERROR_42SH) != 0)
		return (ft_free(msg));
	if (((b_type & AUTO_TYPE_FUN_42SH) == 0 && b_type != AUTO_TYPE_SET_42SH && (tmp = jobs->path) != 0))
		ft_free(tmp);
	array->sh.lp_cmd = lp_cmd;
	ft_42sh_jobs_set_err(array, msg, "", STATUS_FALTURE_42SH);
	ft_free(msg);
}
