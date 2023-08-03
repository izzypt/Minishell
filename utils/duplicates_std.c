/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates_std.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:02:44 by smagalha          #+#    #+#             */
/*   Updated: 2023/08/03 21:50:31 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_stdin_to_pipe(t_list *node)
{
	if (check_redirection(node->prev) == 1)
	{
		close(get_pipe()->fd[1]);
		dup2(get_pipe()->fd[0], STDIN_FILENO);
		close(get_pipe()->fd[0]);
	}
}

void	redirect_stdout_to_pipe(void)
{
	close(get_pipe()->fd[0]);
	dup2(get_pipe()->fd[1], STDOUT_FILENO);
	close(get_pipe()->fd[1]);
}
