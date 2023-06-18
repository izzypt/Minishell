/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/18 17:30:56 by esali            ###   ########.fr       */
=======
/*   Updated: 2023/06/18 17:30:12 by smagalha         ###   ########.fr       */
>>>>>>> main
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

<<<<<<< HEAD
	list = list_heads()->next;
	while(list != NULL)
=======
	list = list_heads();
	list = list->next;
	while (list != NULL)
>>>>>>> main
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
