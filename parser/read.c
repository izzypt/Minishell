/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:19:55 by simao             #+#    #+#             */
/*   Updated: 2023/06/14 12:28:45 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

void	get_user_input(void)
{
	char	*input;

	input = readline("$> ");
	if (input == CTRL_D)
		exit(0);
	if (input && ft_strlen(input) > 0)
		add_history(input);
	parse(input);

	if (!ft_strncmp(input, "echo", 4))
		cmd_echo(input);
	if (!ft_strncmp(input, "env", 3))
		cmd_env();
	/*if (!ft_strncmp(input, "ls", 2))
	 	cmd_ls();
	if (!ft_strncmp(input, "pwd", 3))
		cmd_pwd();
	if (!ft_strncmp(input, "exit", 4))
		exit(0);
	*/

	free(input);
	free_data();
}
