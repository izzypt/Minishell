/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:45:31 by esali             #+#    #+#             */
/*   Updated: 2023/07/29 15:27:39 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal;

int	main(int argc, char **argv, char **env)
{

	if (argc != 1 || argv[1] != NULL)
		return (0);
	create_env(env);
	get_data()->exit = 0;
	get_pipe()->stdin = dup(STDIN_FILENO);
	get_pipe()->stdout = dup(STDOUT_FILENO);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	while (1)
		get_user_input();
	return (0);
}
