/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:59:31 by simao             #+#    #+#             */
/*   Updated: 2023/08/09 01:52:34 by simao            ###   ########.fr       */
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
		redirect_stdin_to_pipe(node);
		execute_command(node);
		cmd_exit(ft_itoa(errno), 0);
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
	if (check_redirection(node->prev) == 3)
		return ;
	redirect_stdin_to_pipe(node);
	pipe(get_pipe()->fd);
	get_data()->executing_cmd = 1;
	get_data()->pid = fork();
	if (get_data()->pid == 0)
	{
		redirect_stdout_to_pipe();
		execute_command(node);
		cmd_exit(ft_itoa(errno), 0);
	}
	waitpid(get_data()->pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	get_data()->executing_cmd = 0;
}
