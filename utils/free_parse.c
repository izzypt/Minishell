/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:45:41 by smagalha          #+#    #+#             */
/*   Updated: 2023/06/18 18:57:05 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_parse(void)
{
	t_list	*node;
	t_list	*tmp;

	node = list_heads()->next;
	while (node != NULL)
	{
		tmp = node->next;
		free_keys(node->token);
		free(node->path);
		free(node);
		node = tmp;
	}
	list_heads()->next = NULL;
}
