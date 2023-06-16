/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:39 by simao             #+#    #+#             */
/*   Updated: 2023/06/16 17:21:45 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// R_OK: Verifica se o arquivo pode ser lido.
// W_OK: Verifica se o arquivo pode ser escrito.
// X_OK: Verifica se o arquivo pode ser executado.
// F_OK: Verifica se o arquivo existe. 

/*
- chdir() takes a string arg of the path of the dir you want to change to. 
- If the directory change is successful, chdir returns 0. 
- Update "PWD" and "OLDPWD" env variables once it sucessfully changed dir.
*/
void	cmd_cd(char *path)
{
	char	cwd[1024];
	char	**path1;
	char	*oldpwd;

	path1 = ft_split(path, ' ');
	oldpwd = ft_strdup(getcwd(cwd, sizeof(cwd)));
	if (chdir(path1[1]) != 0)
	{
		printf("chdir(path) : %d\n", chdir(path));
		if (access(path1[1], F_OK) == -1)
			write(2, "minishell: cd: no such file or directory\n", 42);
		else if (access(path1[1], R_OK | W_OK | X_OK) == -1)
			write(2, "minishell: cd: permission denied\n", 34);
		else
			write(2, "minishell: cd: not a directory\n", 32);
	}
	else
	{
		replace_env_var("OLDPWD", oldpwd);
		replace_env_var("PWD", getcwd(cwd, sizeof(cwd)));
	}
}
