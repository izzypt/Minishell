/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:40:25 by simao             #+#    #+#             */
/*   Updated: 2023/06/14 01:03:19 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

void	cmd_echo(char *line)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(line, ' ');
	if (!ft_strncmp(args[1], "-n", 2))
		i = 2;
	else
		i = 1;
	while (args[i])
	{
		printf("%s ", args[i]);
		i++;
	}
	if (ft_strncmp(args[1], "-n", 2))
		printf("\n");
}

