/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:55:45 by simao             #+#    #+#             */
/*   Updated: 2023/08/08 18:53:39 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_file(t_list *node)
{
	int		file;

	ft_printf("Trying to open %s\n", node->token[0]);
	ft_printf("Previous to open %s\n", node->prev->token[0]);
	if (check_redirection(node->prev) == 2)
	{
		file = open(node->token[0], \
		O_WRONLY | O_TRUNC | O_CREAT, 0644);
		ft_printf("Opened in WRITE mode");
	}
	if (check_redirection(node->prev) == 4)
	{
		file = open(node->token[0], \
		O_CREAT | O_APPEND | O_WRONLY, 0644);
		ft_printf("Opened in APPEND mode");
	}
	return (file);
}
