/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:41:23 by esali             #+#    #+#             */
/*   Updated: 2023/06/25 10:17:18 by esali            ###   ########.fr       */
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
	char	*tmp;
	//int		file;

	// if (cur->next->token[1] != NULL)
	// {
	// 	get_data()->exit = 1;
	// 	ft_printf("unexpected token: %s\n", cur->next->token[1]);
	// 	return ;
	// }
	get_hdoc()->input = ft_calloc(sizeof(char), 1);
	new_line = get_next_prompt();
	while (ft_strncmp(cur->next->token[0], new_line, ft_strlen(new_line)) != 0)
	{
		tmp = get_hdoc()->input;
		get_hdoc()->input = ft_strjoin(get_hdoc()->input, new_line);
		free(tmp);
		tmp = get_hdoc()->input;
		get_hdoc()->input = ft_strjoin(get_hdoc()->input, "\n");
		free(tmp);
		free(new_line);
		new_line = get_next_prompt();
	}
	get_data()->input = ft_strjoin(get_hdoc()->input, new_line);
	free(new_line);
	ft_printf("%s\n", get_hdoc()->input);
	free(get_hdoc()->input);
}


