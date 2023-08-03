/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:59:31 by simao             #+#    #+#             */
/*   Updated: 2023/08/03 14:21:15 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- If node is the last in the list
- and previous node is a pipe this function will run.
*/
void	output_from_pipe(t_list *node)
{
	int	pid;
	int	status;

	get_data()->executing_cmd = 1;
	pid = fork();
	if (pid == 0)
	{
		close(get_pipe()->fd[1]);
		dup2(get_pipe()->fd[0], STDIN_FILENO);
		close(get_pipe()->fd[0]);
		if (is_builtin(node))
			execute_builtin(node);
		else
			execve(node->path, node->token, NULL);
		exit(errno);
	}
	close(get_pipe()->fd[1]);
	close(get_pipe()->fd[0]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	get_data()->executing_cmd = 0;
	dup2(get_pipe()->stdin, STDIN_FILENO);
}

/*
- Executes the given command and output it to the write end of the pipe.
- It will read from the read end of the pipe if the previous node is a pipe.
*/
void	write_to_pipe(t_list *node)
{
	int	status;

	if (check_redirection(node->prev) == 5)
		return ;
	redirect_stdin_to_pipe(node);
	pipe(get_pipe()->fd);
	get_data()->executing_cmd = 1;
	get_data()->pid = fork();
	if (get_data()->pid == 0)
	{
		close(get_pipe()->fd[0]);
		dup2(get_pipe()->fd[1], STDOUT_FILENO);
		close(get_pipe()->fd[1]);
		if (is_builtin(node))
			execute_builtin(node);
		else
			execve(node->path, node->token, NULL);
		exit(errno);
	}
	waitpid(get_data()->pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	get_data()->executing_cmd = 0;
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
	int		status;

	outfile = open(node->next->next->token[0], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	redirect_stdin_to_pipe(node);
	pid = fork();
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		if (is_builtin(node))
			execute_builtin(node);
		else
			execve(node->path, node->token, NULL);
		exit(errno);
	}
	close(outfile);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
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
	int		status;

	out = open(node->next->next->token[0], O_CREAT | O_APPEND | O_WRONLY, 0644);
	redirect_stdin_to_pipe(node);
	pid = fork();
	if (pid == 0)
	{
		dup2(out, STDOUT_FILENO);
		execve(node->path, node->token, NULL);
		exit(errno);
	}
	close(out);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	dup2(get_pipe()->stdin, STDIN_FILENO);
}

void	input_from_fd(t_list *node)
{
	int		pid;
	int		in;
	int		status;

	in = open(node->next->next->token[0], O_RDONLY, 0644);
	get_data()->executing_cmd = 1;
	pid = fork();
	if (pid == 0)
	{
		dup2(in, STDIN_FILENO);
		execve(node->path, node->token, NULL);
		exit(errno);
	}
	close(in);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	get_data()->executing_cmd = 0;
	dup2(get_pipe()->stdin, STDIN_FILENO);
	dup2(get_pipe()->stdout, STDOUT_FILENO);
}
