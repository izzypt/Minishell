/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:40:25 by simao             #+#    #+#             */
/*   Updated: 2023/06/27 10:20:39 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_echo(char **line)
{
	int		i;

	i = 0;
	if (!line[1])
		return ;
	if (!ft_strncmp(line[1], "-n", 2))
		i = 2;
	else
		i = 1;
	while (line[i])
	{
		printf("%s ", line[i]);
		i++;
	}
	if (ft_strncmp(line[1], "-n", 2))
		printf("\n");
}

