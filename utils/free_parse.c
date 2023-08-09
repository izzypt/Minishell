/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:45:41 by smagalha          #+#    #+#             */
/*   Updated: 2023/08/09 02:27:03 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_parse(void)
{
	t_list	*node;
	t_list	*tmp;

	node = get_token()->next;
	while (node != NULL)
	{
		tmp = node->next;
		free_keys(node->token);
		free(node->path);
		free(node);
		node = tmp;
	}
	get_token()->next = NULL;
}

/*
- This function releases the list of nodes t_list.
- Same as above, except it takes the start of the list as an argument.
*/
void	free_list(t_list *list)
{
	t_list	*node;
	t_list	*tmp;

	if (list)
		node = list;
	while (node != NULL)
	{
		printf("releasing %s and %s\n", node->path, node->token[0]);
		tmp = node->next;
		free_keys(node->token);
		free(node->path);
		free(node);
		node = tmp;
	}
}
