/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 14:04:12 by esali             #+#    #+#             */
/*   Updated: 2023/06/18 14:29:10 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- Creates the path of a command by appending the "/" and the command name.
- Checks if we have permissions to exect the command accessing the command path.
- It returns the valid command path.
*/
char	*valid_cmd_path(char *cmd)
{
	char	*command_path;
	char	*temp;
	char	**paths;
	int		i;

	i = 0;
	paths = ft_split(getenv("PATH"), ':');
	while (paths[i] != NULL)
	{
		temp = ft_strjoin(paths[i], "/");
		command_path = ft_strjoin(temp, cmd);
		if (!access(command_path, X_OK))
		{
			free(temp);
			free(paths);
			return (command_path);
		}
		free(command_path);
		free(temp);
		i++;
	}
	free(paths);
	return (NULL);
}
