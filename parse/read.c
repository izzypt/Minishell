/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:19:55 by simao             #+#    #+#             */
/*   Updated: 2023/08/04 19:01:43 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_user_input(void)
{
	char	*input;

	input = readline("$> ");
	if (input == NULL)
	{
		cmd_exit(get_data()->exit);
		return ;
	}
	if (ft_strlen(input) == 0)
		return ;
	get_data()->input = input;
	if (parse(input))
	{
		execute_input(list_heads()->next, get_data()->envp);
		if (list_heads()->next != NULL)
			free_parse();
	}
	if (input && ft_strlen(input) > 0)
		add_history(get_data()->input);
	free(get_data()->input);
}
