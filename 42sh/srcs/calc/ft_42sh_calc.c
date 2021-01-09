/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_calc.h"

static void				*fn_get(register t_cacl_in *in,
register unsigned char *b, register unsigned char *e)
{
	char					*str;
	char					*newstr;
	int						error;

	error = 0;
	if ((str = ft_strndup((void *)b, e - b)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	if ((newstr = ft_main_calc_rec(in, str, &error)) == NULL)
		return (str);
	free(str);
	return (newstr);
}

static size_t			fn_error(t_main_42sh *array, unsigned char **s,
register void *b, register unsigned char *e)
{
	*s = e;
	if (array->pr.exit_pars.lp != 0 ||
	(array->b_location & LOCATION_NOT_DSP_ERR_42SH) != 0)
	{
		free(b);
		return (0);
	}
	array->pr.exit_pars.lp = b;
	array->pr.exit_pars.error = STATUS_FALTURE_42SH;
	return (0);
}

size_t					ft_42sh_calc_count(t_replase_in_42sh *in_rep,
unsigned char **s, unsigned char **out, register unsigned char *e)
{
	register void			*b;
	t_cacl_in				in;
	register size_t			count;

	b = *out;
	if ((e = ft_42sh_calc_end(b + 1, e)) == 0)
		return (0);
	*out = e;
	in.array = in_rep->array;
	in.b_test = CALC_MODE_ENV_GET;
	in.lp_error = 0;
	b = fn_get(&in, --b, e);
	count = ft_strlen(b);
	free(b);
	if ((b = in.lp_error) != 0)
		return (fn_error(in.array, s, b, e));
	return (count);
}

void					*ft_42sh_calc(t_replase_in_42sh *in_rep,
register unsigned char *dest, unsigned char **out, register unsigned char *e)
{
	register void			*b;
	register size_t			count;
	t_cacl_in				in;

	b = *out;
	if ((e = ft_42sh_calc_end(b + 1, e)) == 0)
		return (0);
	*out = e;
	in.array = in_rep->array;
	in.b_test = CALC_MODE_ENV_GET;
	if ((in_rep->array->b_location & LOCATION_NOT_SET_42SH) == 0)
		in.b_test = in.b_test | CALC_MODE_ENV_SET;
	in.lp_error = 0;
	b = fn_get(&in, --b, e);
	count = ft_strlen(b);
	ft_memcpy(dest, b, count);
	free(b);
	return (dest + count);
}
