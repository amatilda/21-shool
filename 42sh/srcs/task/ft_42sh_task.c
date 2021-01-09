/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_task.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_task.h"

void		ft_42sh_task_delete(register t_main_42sh *array)
{
	(void)array;
}

void		ft_42sh_task_init(register t_main_42sh *array,
int argc, char **argv)
{
	(void)array;
	(void)argv;
	(void)argc;
}

void		ft_42sh_task_add_bultin(register t_main_42sh *array,
void (*f)(register t_main_42sh *array,
register char *lp_key, register void *str, uint_fast8_t b_type))
{
	(void)array;
	(void)f;
}
