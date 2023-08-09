/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
/*   Updated: 2023/08/09 02:26:51 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_lists(void)
{
	t_list	*list;
	int		i;

	list = get_token()->next;
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
