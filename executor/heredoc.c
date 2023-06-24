/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:41:23 by esali             #+#    #+#             */
/*   Updated: 2023/06/24 13:17:06 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_next_prompt()
{
	char	*input;

	input = readline(">");
}

//https://linuxize.com/post/bash-heredoc/?utm_content=cmp-true
//https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/#closing_a_file_descriptor_in_c
void	heredoc(t_list *cur)
{
	char	*new_line;
	char	*tmp;

	if (cur->next->token[1] != NULL)
	{
		get_exit()->exit = 1;
		ft_printf("unexpected token: %s\n", cur->next->token[1]);
		return ;
	}
	new_line = get_next_prompt();
	while (ft_strncmp(cur->next->token[0], new_line, ft_strlen(new_line)) != 0)
	{
		tmp = get_hdoc()->input;
		get_hdoc()->input = ft_strjoin(get_hdoc()->input, new_line);
		free(tmp);
		free(new_line);
		new_line = get_next_prompt();
	}
	if (!get_hdoc()->input)
		get_hdoc()->input = new_line;
	else
		free(new_line);
	add_history(get_hdoc()->input);
}


