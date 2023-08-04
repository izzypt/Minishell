/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:45:41 by smagalha          #+#    #+#             */
/*   Updated: 2023/08/04 12:05:57 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_2d_array(char **array, int rows)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (i < rows)
	{
		if (array[i] != NULL)
		{
			free(array[i]);
			array[i] = NULL;
		}
		i++;
	}
	free(array);
}

void	free_parse(void)
{
	t_list	*node;
	t_list	*tmp;
	int		len;

	node = list_heads()->next;
	len = ft_lstsize(node);
	printf("list size is %d\n", len);
	while (node != NULL)
	{
		tmp = node->next;
		free_2d_array(node->token, len);
		free(node->path);
		free(node);
		node = tmp;
	}
	list_heads()->next = NULL;
}
