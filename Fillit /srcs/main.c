/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/09/20 21:52:56 by jkrypto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fn_error(void)
{
	write(1, "error\n", 6);
}

int			main(int argc, char **argv)
{
	t_fillit	fill;

	if (argc != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (0);
	}
	fill.fd = open(argv[1], O_RDONLY);
	if (fill.fd == -1)
	{
		fn_error();
		return (0);
	}
	fill.in_r = read(fill.fd, fill.in, BUFF_SIZE);
	close(fill.fd);
	fill.tettrin_c = fill.in_r / 20;
	if (fill.in_r - fill.tettrin_c * 20 != fill.tettrin_c - 1)
	{
		fn_error();
		return (0);
	}
	if (fn_validate(&fill, fill.in) != 0)
		return (0);
	fn_error();
	return (0);
}
