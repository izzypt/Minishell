/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:41:23 by esali             #+#    #+#             */
/*   Updated: 2023/06/26 18:08:11 by esali            ###   ########.fr       */
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

	pid = fork();
	if (pid == 0)
	{
		dup2(get_hdoc()->fd, STDIN_FILENO);
		execve(cur->prev->path, cur->prev->token, NULL);
		exit(0);
	}
	waitpid(pid, NULL, 0);
	dup2(get_pipe()->stdin, STDIN_FILENO);
}

void	heredoc(t_list *cur)
{
	char	*new_line;
	//char	buf[1000];
	//int		nb_read;

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
	write_to_command(cur);
	// nb_read = read(fd, buf, 1000);
	// if (nb_read == -1)
	// 	ft_printf("nb_read = -1");
	// ft_printf("nb_read = %i", nb_read);
	// buf[nb_read] = '\0';
	// ft_printf("%s", buf);

	close(get_hdoc()->fd);
	unlink(cur->next->token[0]);
}


