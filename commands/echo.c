/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:40:25 by simao             #+#    #+#             */
/*   Updated: 2023/08/07 19:47:59 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_option(char *opt)
{
	int	i;

	if (ft_strncmp(opt, "-n", 2))
		return (1);
	i = 1;
	while (opt[i])
	{
		if (opt[i] != 'n')
			return (1);
		i++;
	}
	return (2);
}

void	cmd_echo(char **line)
{
	int		i;

	i = 0;
	if (!line[1])
		return ;
	i = check_option(line[1]);
	if (line[i] == NULL)
		ft_printf("");
	else
	{
		while (line[i + 1])
		{
			ft_printf("%s ", line[i]);
			i++;
		}
		ft_printf("%s", line[i]);
		if (check_option(line[1]) == 1)
			ft_printf("\n");
	}
}
