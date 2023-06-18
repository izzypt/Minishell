/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:19:55 by simao             #+#    #+#             */
/*   Updated: 2023/06/18 15:34:23 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_user_input(void)
{
	char	*input;

	input = readline("$> ");
	if (input == CTRL_D)
	{
		cmd_exit();
		return ;
	}	
	if (input && ft_strlen(input) > 0)
		add_history(input);
	parse(input);

	if (!ft_strncmp(input, "cd", 2))
		cmd_cd(input);
	if (!ft_strncmp(input, "echo", 4))
		cmd_echo(input);
	if (!ft_strncmp(input, "unset", 5))
		cmd_unset(input);
	if (!ft_strncmp(input, "env", 3))
		cmd_env();
	if (!ft_strncmp(input, "export", 6))
		cmd_export(input);
	if (!ft_strncmp(input, "pwd", 3))
		cmd_pwd();
	if (!ft_strncmp(input, "exit", 4))
		cmd_exit();

	free(input);
}
