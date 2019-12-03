/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static size_t	fn_pwd(register t_string *lp)
{
	register void		*tmp;
	register size_t		tempos;

	if ((tmp = getcwd(0, 0)) == 0)
		return (0);
	lp->buff = tmp;
	tempos = ft_strlen(tmp);
	lp->len = tempos;
	lp->max_len = tempos + 1;
	return (ft_strlen_utf8(tmp));
}

static int		fn_memory(register t_main_42sh *array)
{
	register size_t		tempos;

	array->in.in_first = ft_42sh_list_in_create(array, BUFFER_READ_42SH);
	if ((tempos = fn_pwd(&array->pwd.path)) == 0)
		return (0);
	array->pwd.path_litter = tempos;
	if ((tempos = fn_pwd(&array->pwd.prev_path)) == 0)
		return (0);
	array->pwd.prev_path_litter = tempos;
	return (1);
}

void			ft_42sh_init(register t_main_42sh *array)
{
	array->msg.pre_msg = PRE_MSG_42SH;
	array->msg.pre_msg_litter = PRE_MSG_LITTER_42SH;
	array->msg.pre_msg_sp = MSG_SP_42SH;
	if (tcgetattr(STDOUT_FILENO, &array->tty_change) != 0)
	{
		write(STDERR_FILENO, E_CANON_42SH, LEN_(E_CANON_42SH));
		exit(E_CODE_42SH);
	}
	array->tty = array->tty_change;
	array->tty_change.c_lflag &= ~(ICANON | ECHO);
	array->tty_change.c_cc[VMIN] = 1;
	array->tty_change.c_cc[VTIME] = 0;
	if (tcsetattr(STDOUT_FILENO, TCSANOW, &array->tty_change) != 0)
	{
		write(STDERR_FILENO, E_CANON_42SH, LEN_(E_CANON_42SH));
		exit(E_CODE_42SH);
	}
	ioctl(STDIN_FILENO, TIOCGWINSZ, &array->ws);
	array->out.b = &array->buff_out[0];
	array->out.max = BUFFER_OUT_42SH;
	array->out.fd = STDOUT_FILENO;
	if (fn_memory(array) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH);
}
