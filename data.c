/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
<<<<<<< HEAD:parser/data.c
/*   Updated: 2023/06/16 17:16:22 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
=======
/*   Updated: 2023/06/17 13:32:44 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
>>>>>>> emily-branch:data.c

/* returns head of linked list */
t_list	*list_head(void)
{
	static t_list	list;

	return (&list);
}

<<<<<<< HEAD:parser/data.c
/* frees **token saved inside data struct */
void	free_data(void)
=======
/* frees **char list */
void	free_token(char **list)
>>>>>>> emily-branch:data.c
{
	int		i;

	i = 0;
<<<<<<< HEAD:parser/data.c
	if (!data()->token)
		return ;
	while (data()->token[i])
=======
	while(list[i] != NULL)
>>>>>>> emily-branch:data.c
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
