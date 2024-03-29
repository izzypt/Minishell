/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:01:24 by simao             #+#    #+#             */
/*   Updated: 2023/08/13 11:16:29 by esali            ###   ########.fr       */
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
		cmd_exit(ft_itoa(errno), 0);
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

	outfile = open(node->next->next->next->next->token[0], \
	O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile == -1)
		perror("Error opening outfile");
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
- Should remove and release the ignored inputs if they are valid files.
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
	while (its_input(input_sign))
	{
		if (access(input_sign->next->token[0], R_OK) == -1)
		{
			print_dir_error(input_sign->next->token[0]);
			return ;
		}
		if (its_input(input_sign->next->next))
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

void	input_to_append(t_list *cmd_node, int in_fd)
{
	int	pid;
	int	outfile;
	int	status;

	status = 0;
	outfile = open(cmd_node->next->next->next->next->token[0], \
	O_APPEND | O_RDWR | O_CREAT, 0644);
	if (outfile == -1)
		perror("Error opening outfile");
	pid = fork();
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		dup2(in_fd, STDIN_FILENO);
		execve(cmd_node->path, cmd_node->token, NULL);
		exit(errno);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	close(in_fd);
	close(outfile);
}
