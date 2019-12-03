/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static void	fn_test_key_add(register t_main_42sh *array,
register t_in_42sh *list, register uint_fast32_t litter, register size_t count)
{
	array->tab.b_auto = 0;
	if (litter == KEY_BACKSPACE_42SH)
		ft_42sh_key_backspace(array, list);
	else if (litter == KEY_DELETE_42SH)
		ft_42sh_key_delete(array, list);
	else if (litter == KEY_ENTER_42SH)
		ft_42sh_dq(array, list);
	else if (litter == KEY_UP_42SH)
		ft_42sh_key_up(array, list);
	else if (litter == KEY_DOWN_42SH)
		ft_42sh_key_down(array, list);
	else if (litter == KEY_RIGHT_42SH)
		ft_42sh_key_right(array, list);
	else if (litter == KEY_LEFT_42SH)
		ft_42sh_key_left(array, list);
	else if (litter == KEY_HOME_42SH)
		ft_42sh_key_home(array, list);
	else if (litter == KEY_END_42SH)
		ft_42sh_key_end(array, list);
	else if (litter >= 0x20 && litter <= 0x10FFFF)
		ft_42sh_key_litter(array, list, litter, count);
}

static void	fn_test_key(register t_main_42sh *array, register t_in_42sh *list,
register uint_fast32_t litter, register size_t count)
{
	if (litter == KEY_TAB_42SH && array->tab.b_auto != 0 &&
	array->tab.b_view == 0)
		ft_42sh_auto_dsp_next_cmd(array, list);
	else if (array->tab.b_limit != 0 || litter == KEY_TAB_42SH)
		ft_42sh_key_tab(array, list);
	else
		fn_test_key_add(array, list, litter, count);
}

void		ft_42sh_read(register t_main_42sh *array)
{
	register size_t			count;

	ft_42sh_dsp_start(array);
	ft_write_buffer(&array->out);
	while (0xFF)
	{
		array->litter[0] = 0;
		count = read(STDIN_FILENO, &array->litter, sizeof(array->litter));
		if ((ssize_t)count < 0)
			ft_42sh_exit(E_READ_CODE_42SH);
		if (count <= 4)
			fn_test_key(array, array->in.in_current, array->litter[0], count);
		ft_write_buffer(&array->out);
	}
}
