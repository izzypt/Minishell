/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:19:55 by simao             #+#    #+#             */
/*   Updated: 2023/07/29 17:05:49 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_user_input(void)
{
	char	*input;
	char	**envp;

	input = readline("$> ");
	if (input == CTRL_D)
	{
		cmd_exit();
		return ;
	}
	if (ft_strlen(input) == 0)
		return ;
	get_data()->input = input;
	if (parse(input))
	{
		envp = list_to_array();
		execute_input(list_heads()->next, envp);
		free_parse();
	}
	if (input && ft_strlen(input) > 0)
		add_history(get_data()->input);
	free(get_data()->input);
	if (envp)
		free_keys(envp);
}
