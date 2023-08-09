/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_chain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:14:14 by simao             #+#    #+#             */
/*   Updated: 2023/08/09 12:33:54 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- Handles the ">" symbol and its logic in the command chain.
- To use with command chain function.
- write_to_fd handles multiple outputs/appends chain.
- Returns the last output in case of multiple in a row to the command chain.
*/
t_list	*handle_output(t_list *curr)
{
	write_to_fd(curr);
	if (its_output(curr->next->next->next) || its_output(curr->next->next))
		curr = curr->next;
	while (its_output(curr->next->next))
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
	if (its_append(curr->next->next->next) || its_append(curr->next->next))
		curr = curr->next;
	while (its_append(curr->next->next))
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
		if (its_a_pipe(curr->prev) && !curr->next)
			output_from_pipe(curr);
		else if (its_a_pipe(curr->next))
			write_to_pipe(curr);
		else if (its_output(curr->next))
			curr = handle_output(curr);
		else if (its_input(curr->next))
			curr = handle_input(curr);
		else if (its_append(curr->next))
			curr = handle_append(curr);
		else if (its_heredoc(curr->next))
			curr = handle_heredoc(curr);
		if (get_data()->exit)
			return ;
		curr = curr->next;
	}
}
