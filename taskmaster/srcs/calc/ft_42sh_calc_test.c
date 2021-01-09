/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_calc_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_calc.h"

static size_t			fn_error(register t_cacl_in *in)
{
	char					*str;

	if ((str = in->lp_error) != 0)
	{
		ft_42sh_dq_test_err_n(in->array, str, "", 0);
		free(str);
	}
	return (0);
}

static size_t			fn_finish(register t_cacl_in *in,
register unsigned char *b, register unsigned char *e)
{
	char					*str;
	char					*newstr;
	int						error;

	if ((str = ft_strndup((void *)b, e - b)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	error = 0;
	if ((newstr = ft_main_calc_rec(in, str, &error)) == NULL)
	{
		free(str);
		if (error != 0)
			return (fn_error(in));
		return (1);
	}
	free(str);
	free(newstr);
	return (1);
}

size_t					ft_42sh_calc_test(register t_main_42sh *array,
unsigned char **out, register unsigned char *e)
{
	register unsigned char	*b;
	t_cacl_in				in;

	b = *out;
	if ((e = ft_42sh_calc_end(b + 1, e)) == 0)
		return (0);
	*out = e;
	in.array = array;
	in.b_test = CALC_MODE_ENV_GET;
	in.lp_error = 0;
	return (fn_finish(&in, --b, e));
}