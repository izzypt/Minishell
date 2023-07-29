/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:01 by simao             #+#    #+#             */
/*   Updated: 2023/07/29 19:23:14 by esali            ###   ########.fr       */
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
		//ft_printf("command chain: %s\n", curr->token[0]);
		if (check_redirection(curr->prev) == 1 && !curr->next)
			output_from_pipe(curr);
		else if (check_redirection(curr->next) == 1)
			write_to_pipe(curr);
		else if (check_redirection(curr->next) == 2)
			write_to_fd(curr);
		else if (check_redirection(curr->next) == 3)
			input_from_fd(curr);
		else if (check_redirection(curr->next) == 4)
			append_to_fd(curr);
		else if (check_redirection(curr->next) == 5)
		{
			heredoc(curr->next);
			curr = curr->next->next;
		}
		curr = curr->next;
	}
	free_parse();
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
	if (!ft_strncmp(node->token[0], ">>", 2))
		return (4);
	if (!ft_strncmp(node->token[0], "<<", 2))
		return (5);
	return (0);
}
