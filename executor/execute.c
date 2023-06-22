/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:12:49 by smagalha          #+#    #+#             */
/*   Updated: 2023/06/22 17:05:48 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- Will execute the comand if there is only 1 command in the list.
- Otherwise, it will call the command chain.
*/
void	execute_input(t_list *node)
{
	int		pid1;
	char	**envp;

	if (ft_lstsize(node) > 1)
	{
		command_chain(node);
		return ;
	}
	envp = list_to_array();
	pid1 = fork();
	if (pid1 == 0)
	{
		if (is_builtin(node))
			execute_builtin(node);
		else
		{
			if (!access(node->token[0], X_OK))
				node->path = node->token[0];
			execve(node->path, node->token, envp);
		}
	}
	waitpid(pid1, NULL, 0);
	free_keys(envp);
}

/*
- Will check which bultin function to call based on the input.
- If there isn't a match, it will run the path of the binarie.
*/
void	execute_builtin(t_list *node)
{
	if (!ft_strncmp(node->token[0], "cd", 2))
		cmd_cd(node->token);
	else if (!ft_strncmp(node->token[0], "echo", 4))
		cmd_echo(node->token);
	else if (!ft_strncmp(node->token[0], "unset", 5))
		cmd_unset(node->token);
	else if (!ft_strncmp(node->token[0], "env", 3))
		cmd_env();
	else if (!ft_strncmp(node->token[0], "export", 6))
		cmd_export(node->token);
	else if (!ft_strncmp(node->token[0], "pwd", 3))
		cmd_pwd();
	else if (!ft_strncmp(node->token[0], "exit", 4))
		cmd_exit();
}

int	is_builtin(t_list *node)
{
	if (!ft_strncmp(node->token[0], "cd", 2))
		return (1);
	else if (!ft_strncmp(node->token[0], "echo", 4))
		return (1);
	else if (!ft_strncmp(node->token[0], "unset", 5))
		return (1);
	else if (!ft_strncmp(node->token[0], "env", 3))
		return (1);
	else if (!ft_strncmp(node->token[0], "export", 6))
		return (1);
	else if (!ft_strncmp(node->token[0], "pwd", 3))
		return (1);
	else if (!ft_strncmp(node->token[0], "exit", 4))
		return (1);
	else
		return (0);
}
