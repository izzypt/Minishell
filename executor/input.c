/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:23:28 by simao             #+#    #+#             */
/*   Updated: 2023/08/07 16:59:01 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_input(t_list *node, int in_fd)
{
	if (!node->next->next->next)
		input_to_terminal(node, in_fd);
	if (check_redirection(node->next->next->next) == 1)
		input_to_pipe(node);
	if (check_redirection(node->next->next->next) == 2)
		input_to_fd(node, in_fd);
	if (check_redirection(node->next->next->next) == 3)
		input_to_input(node, in_fd);
	if (check_redirection(node->next->next->next) == 4)
		input_to_append(node, in_fd);
}

void	input_from_fd(t_list *node)
{
	int	in;

	in = open(node->next->next->token[0], O_RDONLY, 0644);
	printf("Opened fd is %d\n", in);
	get_data()->executing_cmd = 1;
	exec_input(node, in);
}
