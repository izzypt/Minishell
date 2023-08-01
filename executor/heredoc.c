/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:41:23 by esali             #+#    #+#             */
/*   Updated: 2023/08/01 13:46:32 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_next_prompt(void)
{
	char	*input;

	input = readline(">");
	return (input);
}

char	*check_env(char	*line)
{
	int		*c;
	char	*str;

	c = (int *)malloc(sizeof(int) * 3);
	c[0] = 0;
	c[1] = ft_strlen(line);
	str = ft_strdup(line);
	while (c[0] < c[1])
	{
		if (str[c[0]] == '$')
			str = manage_env(str, c);
		c[0]++;
	}
	free(c);
	free(line);
	return (str);
}

void	exec_heredoc(t_list *cur)
{
	if (!cur->next->next)
		write_to_command(cur);
	if (check_redirection(cur->next->next) == 1)
		heredoc_to_pipe(cur);
	if (check_redirection(cur->next->next) == 2)
		heredoc_to_fd(cur);
	if (check_redirection(cur->next->next) == 4)
		heredoc_to_append(cur);
}

void	heredoc(t_list *cur)
{
	char		*new_line;
	t_heredoc	*hdoc;
	int			len;

	hdoc = get_hdoc();
	hdoc->fd = open(cur->next->token[0], O_APPEND | O_RDWR | O_CREAT, 0644);
	new_line = get_next_prompt();
	if (ft_strlen(cur->next->token[0]) > ft_strlen(new_line))
		len = ft_strlen(cur->next->token[0]);
	else
		len = ft_strlen(new_line);
	while (ft_strncmp(cur->next->token[0], new_line, len) != 0)
	{
		new_line = check_env(new_line);
		write(hdoc->fd, new_line, ft_strlen(new_line));
		write(hdoc->fd, "\n", 1);
		free(new_line);
		new_line = get_next_prompt();
	}
	free(new_line);
	close(hdoc->fd);
}
