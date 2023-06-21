/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:59:31 by simao             #+#    #+#             */
/*   Updated: 2023/06/21 02:11:06 by simao            ###   ########.fr       */
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
	dup2(get_pipe()->stdin, STDIN_FILENO);
}

void	write_to_pipe(t_list *node)
{
	int			pid1;

	if (check_redirection(node->prev) == 1)
	{
		get_pipe()->stdin = dup(STDIN_FILENO);
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
	int		pid;
	int		outfile;
	char	*file;

	file = node->next->next->token[0];
	outfile = open(file, O_WRONLY | O_CREAT, 0644);
	if (check_redirection(node->prev) == 1)
	{
		close(get_pipe()->fd[1]);
		dup2(get_pipe()->fd[0], STDIN_FILENO);
		close(get_pipe()->fd[0]);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		execve(node->path, node->token, NULL);
	}
	close(outfile);
	waitpid(pid, NULL, 0);
}

void	append_to_fd(t_list *node)
{
	node = node;
}
