/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

t_main_42sh			*g_lp_array;

int			main(int argc, char **argv, char **env)
{
	static t_main_42sh		array;

	g_lp_array = &array;
	array.b_mode = MODE_DEBUG_42SH;
	ft_42sh_init(&array, argc, argv, env);
	ft_42sh_read(&array);
	return (0);
}
