/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:01 by simao             #+#    #+#             */
/*   Updated: 2023/08/06 20:32:33 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

	outfile = open_file(node);
	redirect_stdin_to_pipe(node);
	pid = fork();
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		if (is_builtin(node))
			execute_builtin(node);
		else
			execve(node->path, node->token, NULL);
		cmd_exit(errno);
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

	status = 0;
	out = open(node->next->next->token[0], O_CREAT | O_APPEND | O_WRONLY, 0644);
	redirect_stdin_to_pipe(node);
	pid = fork();
	if (pid == 0)
	{
		dup2(out, STDOUT_FILENO);
		if (is_builtin(node))
			execute_builtin(node);
		else
			execve(node->path, node->token, NULL);
		cmd_exit(errno);
	}
	close(out);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	dup2(get_pipe()->stdin, STDIN_FILENO);
}

/*
- Takes whatever it was given with the "<" and outputs to the original stdout.
*/
void	input_to_terminal(t_list *node, int in_fd)
{
	int		pid;
	int		status;

	status = 0;
	get_data()->executing_cmd = 1;
	pid = fork();
	if (pid == 0)
	{
		dup2(in_fd, STDIN_FILENO);
		if (is_builtin(node))
			execute_builtin(node);
		else
			execve(node->path, node->token, NULL);
		cmd_exit(errno);
	}
	waitpid(pid, &status, 0);
	close(in_fd);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	get_data()->executing_cmd = 0;
	dup2(get_pipe()->stdin, STDIN_FILENO);
	dup2(get_pipe()->stdout, STDOUT_FILENO);
}

/*
- Takes whatever it was given with the "<" and outputs to a pipe.
*/
void	input_to_pipe(t_list *node)
{
	int	pid;
	int	in;
	int	status;

	pipe(get_pipe()->fd);
	pid = fork();
	if (pid == 0)
	{
		in = open(node->next->next->token[0], O_RDONLY, 0644);
		dup2(in, STDIN_FILENO);
		dup2(get_pipe()->fd[1], STDOUT_FILENO);
		execve(node->path, node->token, NULL);
		close(in);
		exit(errno);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	dup2(get_pipe()->stdin, STDIN_FILENO);
}

/*
- If multiple input are in sequence, search for the last input of the chain.
- Should remove and release the ignored inputs.
- Example: 
  - If list is : 
  - "cmd < file1 < file2 < file3" => 
  - "cmd < file1"
*/
void	input_to_input(t_list *cmd_node, int fd)
{
	t_list	*input_sign;
	t_list	*tmp;

	input_sign = cmd_node->next;
	tmp = cmd_node->next;
	while (check_redirection(input_sign) == 3)
	{
		if (check_redirection(input_sign->next->next) == 3)
			input_sign = input_sign->next->next;
		else
			break ;
	}
	cmd_node->next = input_sign;
	input_sign = input_sign->prev;
	close(fd);
	/*printf("input sign next: %s\n", input_sign->next->token[0]);
	printf("input sign : %s\n", input_sign->token[0]);
	printf("input sign next next: %s\n", input_sign->next->next->token[0]);*/
	fd = open(input_sign->next->next->token[0], O_RDONLY, 0644);
	input_sign->next = NULL;
	free_list(tmp);
	//print_lists();
	exec_input(cmd_node, fd);
}

void	exec_input(t_list *node, int in_fd)
{
	if (!node->next->next->next)
		input_to_terminal(node, in_fd);
	if (check_redirection(node->next->next->next) == 1)
		input_to_pipe(node);
	/*if (check_redirection(node->next->next->next) == 2)
		input_to_input(node);*/
	if (check_redirection(node->next->next->next) == 3)
		input_to_input(node, in_fd);
	/*if (check_redirection(node->next->next->next) == 4)
		heredoc_to_append(node);*/
}

void	input_from_fd(t_list *node)
{
	//int		pid;
	int		in;

	in = open(node->next->next->token[0], O_RDONLY, 0644);
	get_data()->executing_cmd = 1;
	exec_input(node, in);
}
