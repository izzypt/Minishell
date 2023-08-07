/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:01 by simao             #+#    #+#             */
/*   Updated: 2023/08/07 19:21:42 by simao            ###   ########.fr       */
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
/*printf("current node: %s and %s\n", node->path, node->token[0]);
printf("node next: %s and %s\n", node->next->path, node->next->token[0]);
printf("node next: %s and %s\n", node->next->path, node->next->token[0]);
printf("node next: %s and %s\n", node->next->path, node->next->token[0]);*/
void	write_to_fd(t_list *node)
{
	int		pid;
	int		outfile;
	int		status;
	t_list	*tmp;

	redirect_stdin_to_pipe(node);
	if (node->next->next->next)
		tmp = node->next->next->next;
	while (tmp && check_redirection(tmp) == 2)
	{
		printf("Opening file %s\n", tmp->prev->token[0]);
		outfile = open_file(tmp->prev);
		close(outfile);
		printf("Closing file %s\n", tmp->prev->token[0]);
		if (tmp->next->next)
			tmp = tmp->next->next;
		else
			break ;
	}
	printf("The outfile is %s\n", tmp->next->token[0]);
	outfile = open_file(tmp->next);
	pid = fork();
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		if (is_builtin(node))
			execute_builtin(node);
		else
			execve(node->path, node->token, NULL);
		cmd_exit(ft_itoa(errno), 0);
	}
	waitpid(pid, &status, 0);
	close(outfile);
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
		cmd_exit(ft_itoa(errno), 0);
	}
	close(out);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	dup2(get_pipe()->stdin, STDIN_FILENO);
}
