/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:59:31 by simao             #+#    #+#             */
/*   Updated: 2023/06/20 13:28:28 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h" //cat parse/todo.txt | grep free | grep list

void	output_from_pipe(t_list *node)
{
	int	pid2;

	pid2 = fork();
	if (pid2 == 0)
	{
		close(get_pipe()->fd[1]);
		dup2(get_pipe()->fd[0], STDIN_FILENO);
		close(get_pipe()->fd[0]);
		execve(node->path, node->token, NULL);
	}
	close(get_pipe()->fd[1]);
	close(get_pipe()->fd[0]);
	waitpid(pid2, NULL, 0);
}

void	write_to_pipe(t_list *node)
{
	int			pid1;

	if (check_redirection(node->prev) == 1)
	{
		close(get_pipe()->fd[1]);
		dup2(get_pipe()->fd[0], STDIN_FILENO);
		close(get_pipe()->fd[0]);
	}
	pipe(get_pipe()->fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(get_pipe()->fd[0]);
		dup2(get_pipe()->fd[1], STDOUT_FILENO);
		close(get_pipe()->fd[1]);
		execve(node->path, node->token, NULL);
	}
	waitpid(pid1, NULL, 0);
}

void	write_to_fd(t_list *node)
{
	node = node;
}

void	append_to_fd(t_list *node)
{
	node = node;
}
