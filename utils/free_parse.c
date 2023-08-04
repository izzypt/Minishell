/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:45:41 by smagalha          #+#    #+#             */
/*   Updated: 2023/08/04 20:45:05 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*void	free_2d_array(char **array, int rows)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (i < rows)
	{
		if (array[i] != NULL)
		{
			ft_printf("token: %s\n", array[i]);
			array[i] = NULL;
		}
		i++;
	}
	i = 0;
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
}*/

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
