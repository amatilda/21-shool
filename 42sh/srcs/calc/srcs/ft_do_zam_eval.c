/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_zam_eval.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 19:53:08 by mbrella           #+#    #+#             */
/*   Updated: 2020/06/15 23:31:21 by mbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

char		*return_with_del(char *str)
{
	ft_strdel(&str);
	return (NULL);
}

char		*ft_do_cut(t_cacl_in *in, char *tmp, int *error)
{
	int					di;
	char				*str;
	char				*dop;
	char				*str_for_rec;
	char				*str_for_del;

	di = 0;
	if (tmp[di] == '(' && tmp[di + 1] == '(' && sc_size(&tmp[di], '(') != -1 &&
	sc_size(&tmp[di + 1], '(') != -1 &&
	(sc_size(&tmp[di], '(') - sc_size(&tmp[di + 1], '(')) == 2)
	{
		di = sc_size(&tmp[di], '(') - 3;
		dop = ft_strsub(tmp, 2, di - 2);
		str_for_del = dop;
		str_for_rec = ft_main_calc_rec(in, dop, error);
		if (*error == 1)
			return (return_with_del(str_for_del));
		if (str_for_rec != NULL)
			dop = str_for_rec;
		str = ft_itoa_add((int)eval_expr(in, dop, error, NULL));
		(str_for_del != dop) ? ft_strdel(&str_for_del) : 0;
		ft_strdel(&dop);
		return ((*error == 1) ? return_with_del(str) : str);
	}
	return (NULL);
}

static void	free_str(char *newstr, char *cut_str)
{
	ft_strcat(newstr, cut_str);
	ft_strdel(&cut_str);
}

char		*ft_main_calc_rec(t_cacl_in *in, char *mas, int *error)
{
	char	*newstr;
	char	*cut_str;
	int		i;
	int		d;

	i = 0;
	d = 0;
	newstr = ft_malloc(ft_strlen(mas) * 2 + 1);
	newstr[0] = 0;
	while (i < (int)ft_strlen(mas) && mas[i] != '\0')
	{
		if (mas[i] == '$' && ++d)
		{
			if (!(cut_str = ft_do_cut(in, mas + i + 1, error)))
				return (return_with_del(newstr));
			i += sc_size(&mas[i + 1], mas[i + 1]);
		}
		else
		{
			cut_str = ft_strdup(" ");
			cut_str[0] = mas[i++];
		}
		free_str(newstr, cut_str);
	}
	return ((d > 0) ? newstr : return_with_del(newstr));
}
