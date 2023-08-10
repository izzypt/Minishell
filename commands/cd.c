/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:39 by simao             #+#    #+#             */
/*   Updated: 2023/08/10 22:06:49 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// R_OK: Verifica se o arquivo pode ser lido.
// W_OK: Verifica se o arquivo pode ser escrito.
// X_OK: Verifica se o arquivo pode ser executado.
// F_OK: Verifica se o arquivo existe.

void	ft_chdir(char *parsed_path)
{
	char	cwd[1024];
	char	*oldpwd;

	oldpwd = ft_strdup(getcwd(cwd, sizeof(cwd)));
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
	else
	{
		replace_env_var("OLDPWD", oldpwd);
		replace_env_var("PWD", ft_strdup(getcwd(cwd, sizeof(cwd))));
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
		write(2, "cd: too many arguments\n", 17);
		get_data()->exit = 1;
		return ;
	}
	if (path[1])
		parsed_path = ft_strdup(path[1]);
	else
	{
		if (ft_getenv("HOME"))
			parsed_path = ft_strdup(ft_getenv("HOME"));
		else
		{
			write(2, "cd: HOME not set\n", 17);
			get_data()->exit = 1;
			return ;
		}
	}
	ft_chdir(parsed_path);
	free(parsed_path);
}
