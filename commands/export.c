/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:54:51 by simao             #+#    #+#             */
/*   Updated: 2023/06/14 15:45:13 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

void	cmd_export(char *variable)
{
	char	**input;
	int		i;

	i = 0;
	if (!ft_strchr(variable, '='))
		return ;
	input = ft_split(variable, ' ');
	while (data()->env_var[i] != NULL)
		i++;
	data()->env_var[i] = input[1];
	i++;
	data()->env_var[i] = NULL;
}
