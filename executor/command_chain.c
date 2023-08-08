/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_chain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:14:14 by simao             #+#    #+#             */
/*   Updated: 2023/08/08 11:33:26 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- Iterates through the list of commands.
- It will check if the next node is a redirection or a pipe.
- Each redirection type has a different code :
- 1 = |
- 2 = >
- 3 = <
- 4 = >>
- 5 = <<
*/
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
		{
			write_to_fd(curr);
			if (check_redirection(curr->next->next->next) == 2 \
			|| check_redirection(curr->next->next) == 2)
				curr = curr->next;
			while (check_redirection(curr->next->next) == 2)
				curr = curr->next->next;
		}
		else if (check_redirection(curr->next) == 3)
		{
			input_from_fd(curr);
			if (curr->next->next->next != NULL)
				curr = curr->next->next->next;
		}
		else if (check_redirection(curr->next) == 4)
			append_to_fd(curr);
		else if (check_redirection(curr->next) == 5)
		{
			heredoc(curr->next);
			if (curr->next->next->next != NULL)
				curr = curr->next->next->next;
		}
		//if (get_data()->exit)
		//	return ;
		curr = curr->next;
	}
}

/*
- Checks if there are redirections.
- If there are it will return the corresponding code.
*/
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
	if (!ft_strncmp(node->token[0], ">>", 3))
		return (4);
	if (!ft_strncmp(node->token[0], "<<", 3))
		return (5);
	return (0);
}
