/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:45:31 by esali             #+#    #+#             */
/*   Updated: 2023/08/12 16:18:35 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	if (argc != 1 || argv[1] != NULL)
		return (0);
	create_env(env);
	increase_shlvl();
	get_data()->exit = 0;
	get_pipe()->stdin = dup(STDIN_FILENO);
	get_pipe()->stdout = dup(STDOUT_FILENO);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	get_data()->envp = list_to_array();
	while (1)
		get_user_input();
	return (0);
}
