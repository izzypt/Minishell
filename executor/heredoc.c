/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:41:23 by esali             #+#    #+#             */
/*   Updated: 2023/08/13 12:02:15 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	if (its_a_pipe(cur->next->next))
		heredoc_to_pipe(cur);
	if (its_output(cur->next->next))
		heredoc_to_fd(cur);
	if (its_append(cur->next->next))
		heredoc_to_append(cur);
}

t_list	*check_next_heredoc(t_list *cur)
{
	while (its_heredoc(cur->next->next) || its_input(cur->next->next))
	{
		if (its_heredoc(cur->next->next))
		{
			close(get_hdoc()->fd);
			unlink(cur->next->token[0]);
			heredoc(cur->next->next);
			return (NULL);
		}
		else if (its_input(cur->next->next))
		{
			if (access(cur->next->next->next->token[0], R_OK) == -1)
			{
				print_dir_error(cur->next->next->next->token[0]);
				return (NULL);
			}
			else
				cur = cur->next->next;
		}
	}
	return (cur);
}

void	write_heredoc(t_list *cur, char *new_line, int fd)
{
	int	len;

	len = maxlen(new_line, cur->next->token[0]);
	while (new_line && ft_strncmp(cur->next->token[0], new_line, len) != 0)
	{
		new_line = check_env(new_line);
		write(fd, new_line, ft_strlen(new_line));
		write(fd, "\n", 1);
		free(new_line);
		new_line = readline(">");
		if (new_line == NULL)
			ft_printf("warning: here-doc delimiter missing\n");
		len = maxlen(new_line, cur->next->token[0]);
	}
	free(new_line);
}

void	heredoc(t_list *cur)
{
	char		*new_line;
	t_heredoc	*hdoc;

	hdoc = get_hdoc();
	hdoc->fd = open(cur->next->token[0], O_APPEND | O_RDWR | O_CREAT, 0644);
	new_line = readline(">");
	if (new_line == NULL)
	{
		ft_printf("warning: here-doc delimiter missing\n");
		return ;
	}
	write_heredoc(cur, new_line, hdoc->fd);
	cur = check_next_heredoc(cur);
	if (!cur)
		return ;
	close(hdoc->fd);
	exec_heredoc(cur);
}
