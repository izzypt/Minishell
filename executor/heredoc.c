/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:41:23 by esali             #+#    #+#             */
/*   Updated: 2023/06/25 11:34:33 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_next_prompt(void)
{
	char	*input;

	input = readline(">");
	return (input);
}

//https://linuxize.com/post/bash-heredoc/?utm_content=cmp-true
//https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/#closing_a_file_descriptor_in_c
void	heredoc(t_list *cur)
{
	char	*new_line;
	int		fd;
	//char	buf[1000];
	//int		nb_read;

	fd = open(cur->next->token[0], O_APPEND| O_RDWR | O_CREAT, 0644);
	new_line = get_next_prompt();
	while (ft_strncmp(cur->next->token[0], new_line, ft_strlen(new_line)) != 0)
	{
		write(fd, new_line, ft_strlen(new_line));
		write(fd, "\n", 1);
		free(new_line);
		new_line = get_next_prompt();
	}
	free(new_line);
	// nb_read = read(fd, buf, 1000);
	// if (nb_read == -1)
	// 	ft_printf("nb_read = -1");
	// ft_printf("nb_read = %i", nb_read);
	// buf[nb_read] = '\0';
	// ft_printf("%s", buf);
	close(fd);
	unlink(cur->next->token[0]);
}


