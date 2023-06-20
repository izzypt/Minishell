/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:31 by simao             #+#    #+#             */
/*   Updated: 2023/06/20 15:38:44 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* Should release all allocated resources before exiting */
void	cmd_exit(void)
{
	t_env	*lst;
	t_env	*tmp;

	printf("RUnning exit command.\n");
	lst = get_env();
	lst = lst->nxt;
	while (lst != NULL)
	{
		tmp = lst->nxt;
		free(lst->key);
		free(lst->value);
		free(lst);
		lst = tmp;
	}
	exit(0);
}
