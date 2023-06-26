/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:41:23 by esali             #+#    #+#             */
/*   Updated: 2023/06/26 22:04:03 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_next_prompt(void)
{
	char	*input;

	input = readline(">");
	return (input);
}

void	write_to_command(t_list *cur)
{
	int pid;
	int	in;

	pid = fork();
	if (pid == 0)
	{
		in = open(cur->next->token[0], O_RDONLY, 0644);
		dup2(in, STDIN_FILENO);
		if (cur->next->next != NULL)
		{
			//if (check_redirection(cur->next->next) == 1)

		}
		else
			execve(cur->prev->path, cur->prev->token, NULL);
		close(in);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	dup2(get_pipe()->stdin, STDIN_FILENO);
	unlink(cur->next->token[0]);
}

void	heredoc(t_list *cur)
{
	char	*new_line;

	get_hdoc()->fd = open(cur->next->token[0], O_APPEND| O_RDWR | O_CREAT, 0644);
	new_line = get_next_prompt();
	while (ft_strncmp(cur->next->token[0], new_line, ft_strlen(new_line)) != 0)
	{
		write(get_hdoc()->fd, new_line, ft_strlen(new_line));
		write(get_hdoc()->fd, "\n", 1);
		free(new_line);
		new_line = get_next_prompt();
	}
	free(new_line);
	close(get_hdoc()->fd);
	write_to_command(cur);

}


