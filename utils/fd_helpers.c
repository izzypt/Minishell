/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:55:45 by simao             #+#    #+#             */
/*   Updated: 2023/08/09 12:17:57 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_file(t_list *node)
{
	int		file;

	ft_printf("Trying to open %s\n", node->token[0]);
	ft_printf("Previous to open %s\n", node->prev->token[0]);
	if (its_output(node->prev))
	{
		file = open(node->token[0], \
		O_WRONLY | O_TRUNC | O_CREAT, 0644);
		ft_printf("Opened in WRITE mode\n");
	}
	if (its_append(node->prev))
	{
		file = open(node->token[0], \
		O_CREAT | O_APPEND | O_WRONLY, 0644);
		ft_printf("Opened in APPEND mode\n");
	}
	return (file);
}
