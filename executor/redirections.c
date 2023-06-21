/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:01 by simao             #+#    #+#             */
/*   Updated: 2023/06/20 00:38:42 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	command_chain(t_list *node)
{
	t_list	*curr;

	curr = node;
	while (curr != NULL)
	{
		if (check_redirection(curr->prev) == 1 && !curr->next)
			output_from_pipe(curr);
		else if (check_redirection(curr->next) == 1)
			write_to_pipe(curr);
		else if (check_redirection(curr->next) == 2)
			write_to_fd(curr);
		else if (check_redirection(curr->next) == 4)
			append_to_fd(curr);
		curr = curr->next;
	}
	free_parse();
}

int	check_redirection(t_list *node)
{
	if (!node || !node->token)
		return (0);
	if (!ft_strncmp(node->token[0], "|", 2))
		return (1);
	if (!ft_strncmp(node->token[0], ">", 2))
		return (2);
	if (!ft_strncmp(node->token[0], "<", 2))
		return (3);
	if (!ft_strncmp(node->token[0], ">>", 2))
		return (4);
	if (!ft_strncmp(node->token[0], "<<", 2))
		return (5);
	//printf("Did not enter any options!\n");
	return (0);
}
