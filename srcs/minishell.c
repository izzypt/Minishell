/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:45:31 by esali             #+#    #+#             */
/*   Updated: 2023/05/25 19:37:31 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;

	input = "";
	while (1)
	{
		input = readline("");
		if (!ft_strncmp(input, "exit", 4))
			break ;
		free(input);
	}
	return (0);
}
