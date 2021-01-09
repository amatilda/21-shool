/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_toogle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

void		ft_42sh_auto_toogle(register t_main_42sh *array)
{
	array->lp_auto->b_auto = 0;
	array->lp_auto->b_limit = 0;
	array->lp_auto->b_view = 0;
	if (array->lp_auto == &array->auto_)
		return ;
	array->lp_auto->count_all = 0;
	array->lp_auto->max_litter = 0;
	ft_42sh_auto_free_all_cmd(array);
	array->lp_auto = &array->auto_;
	array->auto_file.spec_sym = ' ';
}
