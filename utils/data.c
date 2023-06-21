/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:51 by esali             #+#    #+#             */
/*   Updated: 2023/06/21 14:44:17 by esali            ###   ########.fr       */
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
		ft_printf("path: %s\n", list->path);
		while (list->token[i])
		{
			ft_printf("%i. %s ", i, list->token[i]);
			i++;
		}
		ft_printf("\n");
		list = list->next;
	}
}

t_exit	*get_exit(void)
{
	static t_exit	exit;

	return (&exit);
}
