/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:55:45 by simao             #+#    #+#             */
/*   Updated: 2023/08/13 12:16:20 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_file(t_list *node)
{
	int		file;

	if (its_output(node->prev))
	{
		file = open(node->token[0], \
		O_WRONLY | O_TRUNC | O_CREAT, 0644);
	}
	if (its_append(node->prev))
	{
		file = open(node->token[0], \
		O_CREAT | O_APPEND | O_WRONLY, 0644);
	}
	return (file);
}

void	clear_heredocs(void)
{
	t_list	*tmp;

	tmp = get_hdoc()->command;
	while (tmp)
	{
		if (its_heredoc(tmp) && !access(tmp->next->token[0], R_OK))
			unlink(tmp->next->token[0]);
		tmp = tmp->next;
	}
}
