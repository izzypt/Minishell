/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
<<<<<<< HEAD:parse/data.c
/*   Updated: 2023/06/18 15:23:50 by smagalha         ###   ########.fr       */
=======
/*   Updated: 2023/06/18 14:28:33 by esali            ###   ########.fr       */
>>>>>>> emily-branch:utils/data.c
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* returns head of linked list */
t_list	*list_head(void)
{
	static t_list	list;

	return (&list);
}

/* frees **char list */
void	free_token(char **list)
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

void	print_list()
{
	t_list *list;
	int		i;

	list = list_head();
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
