/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:45:42 by simao             #+#    #+#             */
/*   Updated: 2023/06/18 14:34:08 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
