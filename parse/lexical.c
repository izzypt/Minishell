/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:01:05 by esali             #+#    #+#             */
/*   Updated: 2023/08/10 20:25:21 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_is_special_char(char *token)
{
	if (!ft_strncmp(token, "..\0", 3))
	{
		ft_printf("Command '%s' not found\n", token);
		return (127);
	}
	else if (!ft_strncmp(token, "/\0", 2))
	{
		ft_printf("'/' Is a directory\n");
		return (126);
	}
	else if (!ft_strncmp(token, ".\0", 2))
	{
		ft_printf("Error: '.'\n");
		return (127);
	}
	else if (!ft_strncmp(token, "./\0", 3))
	{
		ft_printf("'./' Is a directory\n");
		return (126);
	}
	return (0);
}

int	check_options(char **token)
{
	if (token[1] == NULL)
		return (0);
	else if (!ft_strncmp(token[0], "echo", 4))
		return (0);
	else if (token[1][0] == '-')
	{
		ft_printf("%s: %s: invalid option\n", token[0], token[1]);
		return (2);
	}
	return (0);
}

int	check_lexical(void)
{
	t_list	*list;
	int		check;

	list = get_token()->next;
	while (list != NULL)
	{
		if (!is_built_in(list->token[0]) && !is_red(list->token[0]))
		{
			if (list->path == NULL && access(list->token[0], X_OK) == -1)
			{
				ft_printf("Command '%s' not found\n", list->token[0]);
				return (127);
			}
			check = check_is_special_char(list->token[0]);
		}
		else
			check = check_options(list->token);
		if (check)
			return (check);
		while (list->next != NULL && !is_pipe(list->token[0]))
			list = list->next;
		list = list->next;
	}
	return (0);
}

int	is_built_in(char *token)
{
	if (!ft_strncmp(token, "cd\0", 3))
		return (1);
	else if (!ft_strncmp(token, "echo\0", 5))
		return (1);
	else if (!ft_strncmp(token, "unset\0", 6))
		return (1);
	else if (!ft_strncmp(token, "env\0", 4))
		return (1);
	else if (!ft_strncmp(token, "export\0", 7))
		return (1);
	else if (!ft_strncmp(token, "pwd\0", 4))
		return (1);
	else if (!ft_strncmp(token, "exit\0", 5))
		return (1);
	else
		return (0);
}

int	check_quote(char *input, char c, int i)
{
	if (input[i] == c)
	{
		i++;
		while (input[i] != c && input[i])
			i++;
		if (!input[i])
			ft_printf("Expected closing '%c'\n", c);
	}
	return (i);
}
