/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_auto_cmd_env_replase.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_42sh_auto.h"

static size_t	fn_finish(register t_main_42sh *array, register t_in_42sh *list,
register unsigned char *b, register unsigned char *e)
{
	unsigned char				*end;
	unsigned char				*tmp;

	tmp = b;
	if (ft_42sh_dq_test_sintax(array, &tmp, e) != 0)
		return (0);
	end = e;
	tmp = ft_42sh_auto_cmd_env_replase_get(array, b, &end);
	ft_42sh_auto_cmd_env_replase_del(array, list, b, e);
	if (tmp == 0)
		return (1);
	ft_42sh_str_add(array, (void *)tmp, (void *)end, 1);
	ft_free(tmp);
	return (1);
}

static size_t	fn_ret(register unsigned char *dest, size_t n)
{
	ft_free(dest);
	return (n);
}

static void		*fn_set(register unsigned char *dest, unsigned char **end,
register size_t count)
{
	*end = dest + count;
	return (dest);
}

static size_t	fn_test(register t_main_42sh *array, register t_in_42sh *list,
register unsigned char *b, register unsigned char *e)
{
	register unsigned char		*dest;
	unsigned char				*tmp;
	unsigned char				*end;
	register size_t				count;

	if (array->env.b_exp_err != 0)
	{
		count = array->env.n_exp;
		if ((dest = ft_malloc(count)) == 0)
			ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
		tmp = b;
		ft_42sh_auto_cmd_env_close_while(dest, &tmp, e);
		tmp = fn_set(dest, &end, count);
		if (ft_42sh_dq_test_sintax(array, &tmp, end) != 0)
			return (fn_ret(dest, 0));
		end = tmp;
		tmp = ft_42sh_auto_cmd_env_replase_get(array, dest, &end);
		ft_42sh_auto_cmd_env_replase_del(array, list, b, e);
		if (tmp == 0)
			return (fn_ret(dest, 1));
		ft_42sh_str_add(array, (void *)tmp, (void *)end, 1);
		ft_free(tmp);
		return (fn_ret(dest, 1));
	}
	return (fn_finish(array, list, b, e));
}

size_t			ft_42sh_auto_cmd_env_replase(register t_main_42sh *array,
register t_in_42sh *list, register unsigned char *b)
{
	size_t			b_location;
	size_t			tempos;

	if (array->lp_auto != &array->auto_env || array->pguitar.comp.figure == 0)
		return (0);
	b_location = array->b_location;
	array->b_location = LOCATION_STANDART_42SH | LOCATION_NOT_DSP_ERR_42SH
	| LOCATION_NOT_SET_42SH;
	tempos = fn_test(array, list, b - array->env.offset_auto,
	array->env.lp_end_exp);
	array->b_location = b_location;
	return (tempos);
}