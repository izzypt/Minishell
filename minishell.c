/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:45:31 by esali             #+#    #+#             */
/*   Updated: 2023/06/22 17:33:37 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	if (argc != 1 || argv[1] != NULL)
		return (0);
	create_env(env);
	get_exit()->exit = 0;
	get_pipe()->stdin = dup(STDIN_FILENO);
	get_pipe()->stdout = dup(STDOUT_FILENO);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	while (1)
		get_user_input();
	return (0);
}
