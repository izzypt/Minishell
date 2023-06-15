/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:39 by simao             #+#    #+#             */
/*   Updated: 2023/06/15 12:06:11 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

// R_OK: Verifica se o arquivo pode ser lido.
// W_OK: Verifica se o arquivo pode ser escrito.
// X_OK: Verifica se o arquivo pode ser executado.
// F_OK: Verifica se o arquivo existe. 

/*
- chdir() takes a string arg of the path of the dir you want to change to. 
- If the directory change is successful, chdir returns 0. 
- Otherwise, if it returns -1, the dir change failed.

- Still missing , the change of the environment variable "PWD" and "OLDPWD"
*/
void	cmd_cd(char *path)
{
	if (chdir(path) != 0)
	{
		if (access(path, F_OK) == -1)
			write(2, "minishell: cd: no such file or directory\n", 42);
		else if (access(path, R_OK | W_OK | X_OK) == -1)
			write(2, "minishell: cd: permission denied\n", 34);
		else
			write(2, "minishell: cd: not a directory\n", 32);
		write(2, path, ft_strlen(path));
		write(2, "\n", 1);
	}
}
