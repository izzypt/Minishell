/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:01:05 by esali             #+#    #+#             */
/*   Updated: 2023/07/31 14:17:45 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_is_special_char(char *token)
{
	if (!ft_strncmp(token, "..", 2))
	{
		ft_printf("Command '%s' not found\n", token);
		return (127);
	}
	else if (!ft_strncmp(token, "/\0", 2))
	{
		ft_printf("'/' is a directory\n");
		return (126);
	}
	else if (!ft_strncmp(token, ".\0", 2))
	{
		ft_printf("error: '.'\n");
		return (127);
	}
	return (0);
}

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
	int		check;

	list = list_heads()->next;
	while (list != NULL)
	{
		if (!is_built_in(list->token[0]))
		{
			if (list->path == NULL && access(list->token[0], X_OK) == -1)
			{
				ft_printf("Command '%s' not found\n", list->token[0]);
				return (127);
			}
			check = check_is_special_char(list->token[0]);
			if (check)
				return (check);
		}
		while (list->next != NULL && !is_pipe(list->token[0]))
			list = list->next;
		list = list->next;
	}
	return (0);
}
