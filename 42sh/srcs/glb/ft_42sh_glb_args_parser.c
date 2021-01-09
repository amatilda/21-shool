/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh_glb_args_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatilda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 21:58:20 by amatilda          #+#    #+#             */
/*   Updated: 2019/06/25 15:21:12 by amatilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_42sh_glb.h"

static void		fn_add_list(register t_main_42sh *array, register char *name)
{
	register t_glb_list				*list;
	register size_t					count;

	count = ft_strlen(name);
	if ((list = malloc(sizeof(t_glb_list) + count + 1)) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	ft_memcpy(&list->name[0], name, count + 1);
	ft_42sh_glb_list_add_only(array, list);
}

static size_t	fn_count(register t_main_42sh *array)
{
	register t_glb_list				*list;
	register size_t					count;

	list = array->glb.first;
	count = 0;
	while (list != 0)
	{
		count++;
		list = list->next;
	}
	return (count);
}

static char		**fn_finish(register t_main_42sh *array, register size_t count)
{
	register t_glb_list				*list;
	register t_glb_list				*tmp;
	register char					**args;
	register char					**args_save;

	if ((args = malloc((count + 1) * sizeof(char *))) == 0)
		ft_42sh_exit(E_MEM_CODE_42SH, __FILE__, __func__, __LINE__);
	args[count] = 0;
	args_save = args;
	list = array->glb.first;
	while (list != 0)
	{
		args++[0] = ft_strdup(&list->name[0]);
		tmp = list;
		list = list->next;
		ft_free(tmp);
	}
	array->glb.first = 0;
	return (args_save);
}

char			**ft_42sh_glb_args_parser(register t_main_42sh *array,
register char **args, register size_t count)
{
	register char					**args_save;
	register char					*tmp;

	if (count == 1)
		return (args);
	fn_add_list(array, (tmp = args[0]));
	ft_free(tmp);
	args_save = args++;
	while ((tmp = args++[0]) != 0)
	{
		if (ft_42sh_glb(array, tmp) == 0)
			fn_add_list(array, tmp);
		ft_free(tmp);
	}
	ft_free(args_save);
	return (fn_finish(array, fn_count(array)));
}

void			*ft_42sh_glb_parser(register t_main_42sh *array,
register unsigned char *b, size_t *n)
{
	register size_t					count;
	register t_glb_list				*list;
	register t_glb_list				*tmp;

	if ((list = ft_42sh_glb(array, (char *)b)) == 0)
		return (b);
	ft_free(b);
	b = (void *)&list->name[0];
	count = ft_strlen((char *)b);
	*n = count;
	b = ft_strndup((char *)b, count);
	while (list != 0)
	{
		tmp = list;
		list = list->next;
		ft_free(tmp);
	}
	array->glb.first = 0;
	return (b);
}
