/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:01:05 by esali             #+#    #+#             */
/*   Updated: 2023/07/29 18:36:32 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_built_in(char *token)
{
	if (!ft_strncmp(token, "cd", 2))
		return (1);
	else if (!ft_strncmp(token, "echo", 4))
		return (1);
	else if (!ft_strncmp(token, "unset", 5))
		return (1);
	else if (!ft_strncmp(token, "env", 3))
		return (1);
	else if (!ft_strncmp(token, "export", 6))
		return (1);
	else if (!ft_strncmp(token, "pwd", 3))
		return (1);
	else if (!ft_strncmp(token, "exit", 4))
		return (1);
	else
		return (0);
}

int	check_lexical(void)
{
	t_list	*list;

	list = list_heads()->next;
	while(list != NULL)
	{
		if (!is_built_in(list->token[0]))
		{
			if (list->path == NULL && access(list->token[0], X_OK) == -1)
			{
				ft_printf("Command '%s' not found\n", list->token[0]);
				return (127);
			}
		}
		while (list->next != NULL && !is_pipe(list->token[0]))
			list = list->next;
		list = list->next;
	}
	return (0);
}
