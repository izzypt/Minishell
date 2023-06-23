/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:59:31 by simao             #+#    #+#             */
/*   Updated: 2023/06/23 01:29:15 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h" //cat parse/todo.txt | grep free | grep list

/*
- If node is the last in the list 
- and previous node is a pipe this function will run.
*/
void	output_from_pipe(t_list *node)
{
	int	pid2;
	int	child_id;

	pid2 = fork();
	if (pid2 == 0)
	{
		child_id = getpid();
		close(get_pipe()->fd[1]);
		dup2(get_pipe()->fd[0], STDIN_FILENO);
		close(get_pipe()->fd[0]);
		if (is_builtin(node))
			execute_builtin(node);
		else
			execve(node->path, node->token, NULL);
	}
	close(get_pipe()->fd[1]);
	close(get_pipe()->fd[0]);
	waitpid(pid2, NULL, 0);
	kill(child_id, SIGKILL);
	dup2(get_pipe()->stdin, STDIN_FILENO);
}

/*
- Executes the given command and output it to the write end of the pipe.
- It will read from the read end of the pipe if the previous node is a pipe.
*/
void	write_to_pipe(t_list *node)
{
	int			pid1;
	int			child_id;

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
		child_id = getpid();
		close(get_pipe()->fd[0]);
		dup2(get_pipe()->fd[1], STDOUT_FILENO);
		close(get_pipe()->fd[1]);
		if (is_builtin(node))
			execute_builtin(node);
		else
			execve(node->path, node->token, NULL);
	}
	waitpid(pid1, NULL, 0);
	kill(child_id, SIGKILL);
}

/*
- Will open the file following the node which holds ">"
- If the previous node is a pipe, we will read from the pipe.
- Fork the process and in the child process:
  - swtich the stdoutput to the file
  - execute the command
- At the end we reset the stdouput of the main process.
*/
void	write_to_fd(t_list *node)
{
	int		pid;
	int		outfile;

	outfile = open(node->next->next->token[0], O_WRONLY | O_CREAT, 0644);
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
		if (is_builtin(node))
			execute_builtin(node);
		else
			execve(node->path, node->token, NULL);
	}
	close(outfile);
	waitpid(pid, NULL, 0);
	dup2(get_pipe()->stdin, STDIN_FILENO);
	dup2(get_pipe()->stdout, STDOUT_FILENO);
}

/*
- It opens the given file in append mode and writes to it.
- If the previous node is a redirection pipe. it will read from it.
*/
void	append_to_fd(t_list *node)
{
	int		pid;
	int		out;

	out = open(node->next->next->token[0], O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (check_redirection(node->prev) == 1)
	{
		close(get_pipe()->fd[1]);
		dup2(get_pipe()->fd[0], STDIN_FILENO);
		close(get_pipe()->fd[0]);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(out, STDOUT_FILENO);
		execve(node->path, node->token, NULL);
	}
	close(out);
	waitpid(pid, NULL, 0);
	dup2(get_pipe()->stdin, STDIN_FILENO);
}

void	input_from_fd(t_list *node)
{
	int		pid;
	int		in;

	in = open(node->next->next->token[0], O_RDONLY, 0644);
	pid = fork();
	if (pid == 0)
	{
		dup2(in, STDIN_FILENO);
		execve(node->path, node->token, NULL);
	}
	close(in);
	waitpid(pid, NULL, 0);
	dup2(get_pipe()->stdin, STDIN_FILENO);
	dup2(get_pipe()->stdout, STDOUT_FILENO);
}
