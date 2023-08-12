/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:12:49 by smagalha          #+#    #+#             */
/*   Updated: 2023/08/12 17:12:46 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- Check if the given node is a built-in function or not.
- Executes accordingly.
*/
void	execute_command(t_list *node)
{
	if (is_builtin(node))
		execute_builtin(node);
	else
		execve(node->path, node->token, NULL);
}

/*
- Will execute the comand if there is only 1 command in the list.
- Otherwise, it will call the command chain.
*/
void	execute_input(t_list *node, char **envp)
{
	int		pid1;
	int		status;

	if (ft_lstsize(node) > 1)
		command_chain(node);
	else if (is_builtin(node))
		execute_builtin(node);
	else
	{
		get_data()->executing_cmd = 0;
		pid1 = fork();
		if (pid1 == 0)
		{
			if (!access(node->token[0], X_OK))
				node->path = ft_strdup(node->token[0]);
			execve(node->path, node->token, envp);
			if (errno == 13)
				cmd_exit(ft_strdup("126"), 0);
			cmd_exit(ft_itoa(errno), 0);
		}
		waitpid(pid1, &status, 0);
		if (WIFEXITED(status))
			get_data()->exit = WEXITSTATUS(status);
		get_data()->executing_cmd = 0;
	}
}

/*
- Will check which bultin function to call based on the input.
- NO return value.
*/
void	execute_builtin(t_list *node)
{
	if (!ft_strncmp(node->token[0], "cd\0", 3))
		cmd_cd(node->token);
	else if (!ft_strncmp(node->token[0], "echo\0", 5))
		cmd_echo(node->token);
	else if (!ft_strncmp(node->token[0], "unset\0", 6))
		cmd_unset(node->token);
	else if (!ft_strncmp(node->token[0], "env\0", 4))
		cmd_env(node->token);
	else if (!ft_strncmp(node->token[0], "export\0", 7))
		cmd_export(node->token);
	else if (!ft_strncmp(node->token[0], "pwd\0", 4))
		cmd_pwd();
	else if (!ft_strncmp(node->token[0], "exit\0", 5))
	{
		if (node->token[1] && node->token[2])
			cmd_exit(ft_strdup(node->token[1]), 5);
		else if (node->token[1])
			cmd_exit(ft_strdup(node->token[1]), 1);
		cmd_exit(ft_itoa(get_data()->exit), 1);
	}
}

/*
- Checks if te given node is trying to execute a built-in command
- Returns 1 if there is match, 0 otherwise.
*/
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
