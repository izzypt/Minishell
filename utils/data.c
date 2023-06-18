/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
/*   Updated: 2023/06/18 23:07:31 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* returns head of linked list */
t_list	*list_heads(void)
{
	static t_list	list;

	return (&list);
}

void	print_lists(void)
{
	t_list	*list;
	int		i;

	list = list_heads()->next;
	while (list != NULL)
	{
		i = 0;
		while (list->token[i])
		{
			printf("%i. %s ", i, list->token[i]);
			i++;
		}
		list = list->next;
	}
}
