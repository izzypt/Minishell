/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_chain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:14:14 by simao             #+#    #+#             */
/*   Updated: 2023/08/09 01:54:15 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- Handles the ">" symbol and its logic in the command chain.
- To use with command chain function.
*/
t_list	*handle_output(t_list *curr)
{
	write_to_fd(curr);
	if (check_redirection(curr->next->next->next) == 2 \
	|| check_redirection(curr->next->next) == 2)
		curr = curr->next;
	while (check_redirection(curr->next->next) == 2)
		curr = curr->next->next;
	return (curr);
}

/*
- Handles the "<" symbol and its logic in the command chain..
- To use with command chain function.
*/
t_list	*handle_input(t_list *curr)
{
	input_from_fd(curr);
	if (curr->next->next->next != NULL)
		curr = curr->next->next->next;
	return (curr);
}

/*
- Handles the ">>" symbol and its logic in the command chain..
- To use with command chain function.
*/
t_list	*handle_append(t_list *curr)
{
	append_to_fd(curr);
	if (check_redirection(curr->next->next->next) == 4 \
	|| check_redirection(curr->next->next) == 4)
		curr = curr->next;
	while (check_redirection(curr->next->next) == 4)
		curr = curr->next->next;
	return (curr);
}

/*
- Handles the "<<" symbol and its logic in the command chain.
- To use with command chain function.
*/
t_list	*handle_heredoc(t_list *curr)
{
	heredoc(curr->next);
	if (curr->next->next->next != NULL)
		curr = curr->next->next->next;
	return (curr);
}

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
			curr = handle_output(curr);
		else if (check_redirection(curr->next) == 3)
			curr = handle_input(curr);
		else if (check_redirection(curr->next) == 4)
			curr = handle_append(curr);
		else if (check_redirection(curr->next) == 5)
			curr = handle_heredoc(curr);
		if (get_data()->exit)
			return ;
		curr = curr->next;
	}
}
