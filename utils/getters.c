/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:15:14 by simao             #+#    #+#             */
/*   Updated: 2023/07/31 15:15:47 by smagalha         ###   ########.fr       */
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
