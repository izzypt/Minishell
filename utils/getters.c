/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:15:14 by simao             #+#    #+#             */
/*   Updated: 2023/06/21 15:37:33 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* returns head of the linked list that holds the parsed input/tokens */
t_list	*list_heads(void)
{
	static t_list	list;

	list.prev = NULL;
	return (&list);
}

t_pipe	*get_pipe(void)
{
	static t_pipe	data;

	return (&data);
}

t_exit	*get_exit(void)
{
	static t_exit	exit_node;

	return (&exit_node);
}
