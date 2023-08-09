/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates_std.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:02:44 by smagalha          #+#    #+#             */
/*   Updated: 2023/08/09 12:17:04 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_stdin_to_pipe(t_list *node)
{
	if (its_a_pipe(node->prev))
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

void	reset_original_std(void)
{
	dup2(get_pipe()->stdin, STDIN_FILENO);
	dup2(get_pipe()->stdout, STDOUT_FILENO);
}
