/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:45:42 by simao             #+#    #+#             */
/*   Updated: 2023/05/26 13:52:50 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

void	cmd_ls(void)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(".");
	if (dir == NULL)
	{
		perror("opendir() error");
	}
	entry = readdir(dir);
	while (entry != NULL)
	{
		entry = readdir(dir);
		if (entry)
			printf("%s ", entry->d_name);
	}
	printf("\n");
	closedir(dir);
}
