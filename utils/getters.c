/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:15:14 by simao             #+#    #+#             */
/*   Updated: 2023/08/09 02:24:07 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* returns head of the linked list that holds the parsed input/tokens */
t_list	*get_token(void)
{
	static t_list	list;

	list.prev = NULL;
	list.is_head = 1;
	return (&list);
}

t_pipe	*get_pipe(void)
{
	static t_pipe	data;

	return (&data);
}

t_data	*get_data(void)
{
	static t_data	data_node;

	return (&data_node);
}

t_heredoc	*get_hdoc(void)
{
	static t_heredoc	h_data;

	return (&h_data);
}
