/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
/*   Updated: 2023/08/08 11:09:07 by esali            ###   ########.fr       */
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
		if (list->path)
			ft_printf("PATH: %s", list->path);
		ft_printf("\n");
		list = list->next;
	}
}
