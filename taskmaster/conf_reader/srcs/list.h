/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wstygg <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:30:21 by wstygg            #+#    #+#             */
/*   Updated: 2020/04/21 16:27:49 by wstygg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "conf_reader.h"
# include <unistd.h>
# include <stdlib.h>

t_list					*list_add_at(t_list *lst, int at, t_task *content);
t_list					*list_remove_at(t_list *lst, int at, int to_free);
t_list					*list_at(t_list *lst, int at);
t_list					*list_remove_front(t_list *list, int to_free);
t_list					*list_remove_back(t_list *list, int to_free);
t_list					*list_add_front(t_list *list, t_task *content);
t_list					*list_add_back(t_list *list, t_task *content);
t_list					*list_create(t_task *content);
t_list					*list_remove_all(t_list *list, int to_free);
int						list_length(t_list *list);

void					ft_crash(const char *msg, ...);

#endif
