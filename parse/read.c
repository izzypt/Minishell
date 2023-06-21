/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:19:55 by simao             #+#    #+#             */
/*   Updated: 2023/06/21 15:05:07 by esali            ###   ########.fr       */
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
	if (ft_strlen(input) == 0)
		return ;
	if (parse(input))
	{
		execute_input(list_heads()->next);
		free_parse();
	}
	free(input);
}
