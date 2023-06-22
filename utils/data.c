/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
/*   Updated: 2023/06/22 20:11:39 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
			ft_printf("%i. %s ", i, list->token[i]);
			i++;
		}
		ft_printf("\n");
		list = list->next;
	}
}
