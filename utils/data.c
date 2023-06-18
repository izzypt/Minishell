/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
/*   Updated: 2023/06/18 15:45:27 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* returns head of linked list */
t_list	*list_heads(void)
{
	static t_list	list;

	return (&list);
}

/* frees **char list */
void	free_tokens(char **list)
{
	int		i;

	i = 0;
	while(list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	print_lists(void)
{
	t_list *list;
	int		i;

	list = list_heads();
	while(list != NULL)
	{
		i = 0;
		while (list->token[i] != NULL)
		{
			printf("%i. %s ", i, list->token[i]);
			i++;
		}
		list = list->next;
	}
}
