/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_cm_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void				ft_42sh_cm_false(register t_main_42sh *array,
register char **lp_arg)
{
	array->env.exit_status->number = STATUS_FALTURE_42SH;
	(void)lp_arg;
}

void				ft_42sh_cm_true(register t_main_42sh *array,
register char **lp_arg)
{
	array->env.exit_status->number = STATUS_OK_42SH;
	(void)lp_arg;
}
