/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:55:45 by simao             #+#    #+#             */
/*   Updated: 2023/08/03 22:57:00 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_file(t_list *node)
{
	int		file;

	file = open(node->next->next->token[0], \
	O_WRONLY | O_TRUNC | O_CREAT, 0644);
	return (file);
}
