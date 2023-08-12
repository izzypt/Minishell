/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:23:28 by simao             #+#    #+#             */
/*   Updated: 2023/08/12 16:58:07 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_input(t_list *node, int in_fd)
{
	if (!node->next->next->next)
		input_to_terminal(node, in_fd);
	if (its_a_pipe(node->next->next->next))
		input_to_pipe(node);
	if (its_output(node->next->next->next))
		input_to_fd(node, in_fd);
	if (its_input(node->next->next->next))
		input_to_input(node, in_fd);
	if (its_append(node->next->next->next))
		input_to_append(node, in_fd);
}

void	input_from_fd(t_list *node)
{
	int	in;

	in = open(node->next->next->token[0], O_RDONLY, 0644);
	ft_printf("Opened fd is %d\n", in);
	get_data()->executing_cmd = 1;
	exec_input(node, in);
}
