/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:44:58 by esali             #+#    #+#             */
/*   Updated: 2023/08/13 12:15:17 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	write_to_command(t_list *cur)
{
	int	pid;
	int	in;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		in = open(cur->next->token[0], O_RDONLY, 0644);
		dup2(in, STDIN_FILENO);
		execve(get_hdoc()->command->path, get_hdoc()->command->token, NULL);
		close(in);
		exit(errno);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	dup2(get_pipe()->stdin, STDIN_FILENO);
	clear_heredocs();
}

void	heredoc_to_pipe(t_list *cur)
{
	int	pid;
	int	in;
	int	status;

	pipe(get_pipe()->fd);
	pid = fork();
	if (pid == 0)
	{
		in = open(cur->next->token[0], O_RDONLY, 0644);
		dup2(in, STDIN_FILENO);
		dup2(get_pipe()->fd[1], STDOUT_FILENO);
		execve(get_hdoc()->command->path, get_hdoc()->command->token, NULL);
		close(in);
		exit(errno);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	dup2(get_pipe()->stdin, STDIN_FILENO);
	clear_heredocs();
}

t_list	*check_heredoc_outputs(t_list *cur)
{
	int		outfile;

	while (its_output(cur->next->next))
	{
		cur = cur->next->next;
		outfile = open(cur->next->token[0], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		close(outfile);
	}
	return (cur);
}

void	heredoc_to_fd(t_list *cur)
{
	int		in;
	int		pid;
	int		outfile;
	int		status;
	t_list	*tmp;

	tmp = cur;
	cur = check_heredoc_outputs(cur);
	outfile = open(cur->next->token[0], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	in = open(tmp->next->token[0], O_RDONLY, 0644);
	pid = fork();
	if (pid == 0)
	{
		dup2(in, STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		execve(get_hdoc()->command->path, get_hdoc()->command->token, NULL);
		exit(errno);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	close(in);
	close(outfile);
	clear_heredocs();
}

void	heredoc_to_append(t_list *cur)
{
	int	in;
	int	pid;
	int	outfile;
	int	status;

	outfile = open(cur->next->next->next->token[0], \
	O_WRONLY | O_APPEND | O_CREAT, 0644);
	pid = fork();
	if (pid == 0)
	{
		in = open(cur->next->token[0], O_RDONLY, 0644);
		dup2(in, STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		execve(get_hdoc()->command->path, get_hdoc()->command->token, NULL);
		close(in);
		exit(errno);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		get_data()->exit = WEXITSTATUS(status);
	close(outfile);
	clear_heredocs();
}
