/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:59:31 by simao             #+#    #+#             */
/*   Updated: 2023/06/22 15:52:25 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h" //cat parse/todo.txt | grep free | grep list

/*
- If node is the last in the list 
- and previous node is a pipe this function will run.
- 
- 
*/
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

/*
- Executes the given command and output it to the write end of the pipe.
- It will read from the read end of the pipe if the previous node is a pipe.
*/
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

/*
- Will open the file following the node which holds ">"
- If the previous node is a pipe, we will read from the pipe.
- Fork the process and in the child process:
  - swtich the stdoutput to the file
  - execute the command
- At the end we reset the Stdinput of the main process.
*/
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
	dup2(get_pipe()->stdin, STDIN_FILENO);
}

void	append_to_fd(t_list *node)
{
	int		pid;
	int		outfile;
	char	*file;

	file = node->next->next->token[0];
	outfile = open(file, O_CREAT | O_APPEND | O_WRONLY, 0644);
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
	dup2(get_pipe()->stdin, STDIN_FILENO);
}
