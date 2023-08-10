/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:01 by simao             #+#    #+#             */
/*   Updated: 2023/08/10 12:47:08 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	if (its_output(node->next->next) || its_append(node->next->next))
		tmp = node->next->next;
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
- Checks if there are any input redirections after the output ">".
*/
int	ouput_to_input(t_list *node)
{
	t_list	*tmp;
	int		infile;

	tmp = NULL;
	infile = 0;
	if (node->next->next)
		tmp = node->next->next;
	while (tmp && its_input(tmp))
	{
		if (tmp->next->next)
			tmp = tmp->next->next;
		else
			break ;
	}
	if (tmp != NULL)
		infile = open(tmp->next->token[0], O_RDONLY, 0644);
	return (infile);
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
	int		infile;
	t_list	*tmp;

	redirect_stdin_to_pipe(node);
	tmp = check_red_after_ouput(node->next);
	infile = ouput_to_input(node->next);
	if (tmp)
		outfile = open_file(tmp->next);
	else
		outfile = open_file(node->next->next);
	pid = fork();
	if (pid == 0)
	{
		if (infile)
			dup2(infile, STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		execute_command(node);
		cmd_exit(ft_itoa(errno), 0);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	close(outfile);
	close(infile);
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
	tmp = check_red_after_ouput(node->next);
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
