/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:23:28 by simao             #+#    #+#             */
/*   Updated: 2023/08/07 14:44:26 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
		close(in_fd);
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

void	input_to_fd(t_list *node, int in_fd)
{
	int	pid;
	int	outfile;
	int	status;

	printf("Input fd is %d\n", in_fd);
	printf("Node value: %s and %s\n", node->path, node->token[0]);
	printf("Infile: %s\n", node->next->next->token[0]);
	printf("Outfile: %s\n", node->next->next->next->next->token[0]);
	outfile = open(node->next->next->next->next->token[0], \
	O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile == -1)
		perror("Error opening outfile");
	printf("Outfile fd: %d\n", outfile);
	pid = fork();
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		dup2(in_fd, STDIN_FILENO);
		execve(node->path, node->token, NULL);
		exit(errno);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	close(in_fd);
	close(outfile);
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
- NOT APPLICABLE to output "<". Those should open the file and cannot be freed.
*/
void	input_to_input(t_list *cmd_node, int fd)
{
	t_list	*input_sign;
	t_list	*first_ocorrence;
	int		file;

	input_sign = cmd_node->next;
	first_ocorrence = cmd_node->next;
	while (check_redirection(input_sign) == 3)
	{
		if (check_redirection(input_sign->next->next) == 3)
			input_sign = input_sign->next->next;
		else
			break ;
	}
	cmd_node->next = input_sign;
	input_sign->prev->next = NULL;
	input_sign->prev = cmd_node->next;
	close(fd);
	file = open(input_sign->next->token[0], O_RDONLY, 0644);
	free_list(first_ocorrence);
	exec_input(cmd_node, file);
}

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
	/*if (check_redirection(node->next->next->next) == 4)
		heredoc_to_append(node);*/
}

void	input_from_fd(t_list *node)
{
	//int		pid;
	int			in;

	in = open(node->next->next->token[0], O_RDONLY, 0644);
	printf("Opened fd is %d\n", in);
	get_data()->executing_cmd = 1;
	exec_input(node, in);
}
