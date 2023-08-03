/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:56:51 by simao             #+#    #+#             */
/*   Updated: 2023/08/02 23:42:34 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	int	i;
	int	num_of_cmd;
	int	**fds;
	int	*processes;

	i = 0;
	num_of_cmd = argc;
	fds = malloc(sizeof(int) * num_of_cmd);
	processes = malloc(sizeof(int) * num_of_cmd);
	while (i < num_of_cmd)
		fds[i++] = malloc(sizeof(int) * 2);
	i = 0;
	while (i < argc)
	{
		if (pipe(fd[i]) < 0)
			perror("pipe %d failed to open;", i);
		i++;
	}
}
