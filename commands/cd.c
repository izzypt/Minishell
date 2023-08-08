/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:39 by simao             #+#    #+#             */
/*   Updated: 2023/08/08 10:49:25 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// R_OK: Verifica se o arquivo pode ser lido.
// W_OK: Verifica se o arquivo pode ser escrito.
// X_OK: Verifica se o arquivo pode ser executado.
// F_OK: Verifica se o arquivo existe.

void ft_chdir(char *parsed_path)
{
	if (chdir(parsed_path) != 0)
	{
		if (access(parsed_path, F_OK) == -1)
		{
			write(2, "minishell: cd: no such file or directory\n", 42);
			get_data()->exit = 1;
		}
		else if (access(parsed_path, R_OK | W_OK | X_OK) == -1)
		{
			write(2, "minishell: cd: permission denied\n", 34);
			get_data()->exit = 1;
		}
		else
		{
			write(2, "minishell: cd: not a directory\n", 32);
			get_data()->exit = 1;
		}
	}
}

/*
- chdir() takes a string arg of the path of the dir you want to change to.
- If the directory change is successful, chdir returns 0.
- Update "PWD" and "OLDPWD" env variables once it sucessfully changed dir.
*/
void	cmd_cd(char **path)
{
	char	*parsed_path;

	if (path[1] && path[2])
	{
		ft_printf("cd: too many arguments");
		get_data()->exit = 1;
		return ;
	}
	if (path[1])
		parsed_path = ft_strdup(path[1]);
	else
	{
		parsed_path = ft_getenv("HOME");
		if (!parsed_path)
		{
			ft_printf("cd: HOME not set");
			get_data()->exit = 1;
			return ;
		}
	}
	ft_chdir(parsed_path);
	free(parsed_path);
}
