/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:40:25 by simao             #+#    #+#             */
/*   Updated: 2023/06/18 18:28:42 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_echo(char **line)
{
	int		i;

	i = 0;
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

