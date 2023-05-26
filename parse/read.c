/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:19:55 by simao             #+#    #+#             */
/*   Updated: 2023/05/26 13:35:32 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

void	get_user_input(void)
{
	char	*input;

	input = readline("");
	if (!ft_strncmp(input, "pwd", 3))
		cmd_pwd();
	if (!ft_strncmp(input, "exit", 4))
		exit(0);
	free(input);
}
