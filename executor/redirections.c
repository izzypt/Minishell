/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:01 by simao             #+#    #+#             */
/*   Updated: 2023/08/09 12:13:18 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- Checks if there are redirections.
- If there are it will return the corresponding code.
*/
int	check_redirection(t_list *node)
{
	if (!node || !node->token)
		return (0);
	if (!ft_strncmp(node->token[0], "|", 2))
		return (1);
	if (!ft_strncmp(node->token[0], ">", 2))
		return (2);
	if (!ft_strncmp(node->token[0], "<", 2))
		return (3);
	if (!ft_strncmp(node->token[0], ">>", 3))
		return (4);
	if (!ft_strncmp(node->token[0], "<<", 3))
		return (5);
	return (0);
}

/*
- Handles multiple ">>" or ">" after the first ">" or ">>".
- if node->next->next->next is ">" or ">>" ...
- ... it will open the file with the necessary flag.
*/
t_list	*check_red_after_ouput(t_list *node)
{
	t_list	*tmp;
	int		outfile;

	tmp = NULL;
	if (node->next->next->next)
		tmp = node->next->next->next;
	while (tmp && (its_output(tmp) || its_append(tmp)))
	{
		outfile = open_file(tmp->prev);
		close(outfile);
		if (tmp->next->next)
			tmp = tmp->next->next;
		else
			break ;
	}
	return (tmp);
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
	t_list	*tmp;

	redirect_stdin_to_pipe(node);
	tmp = check_red_after_ouput(node);
	if (tmp)
		outfile = open_file(tmp->next);
	else
		outfile = open_file(node->next->next);
	pid = fork();
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		execute_command(node);
		cmd_exit(ft_itoa(errno), 0);
	}
	waitpid(pid, &status, 0);
	close(outfile);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	reset_original_std();
}

/*
- It opens the given file in append mode and writes to it.
- If the previous node is a redirection pipe. it will read from it.
*/
void	append_to_fd(t_list *node)
{
	int		pid;
	int		outfile;
	int		status;
	t_list	*tmp;

	status = 0;
	redirect_stdin_to_pipe(node);
	tmp = check_red_after_ouput(node);
	if (tmp)
		outfile = open_file(tmp->next);
	else
		outfile = open_file(node->next->next);
	pid = fork();
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		execute_command(node);
		close(outfile);
		cmd_exit(ft_itoa(errno), 0);
	}
	close(outfile);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	reset_original_std();
}
