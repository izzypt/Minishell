/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:31 by simao             #+#    #+#             */
/*   Updated: 2023/06/22 23:58:47 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* Should release all allocated resources before exiting */
void	cmd_exit(void)
{
	t_env	*lst;
	t_env	*tmp;

	printf("RUnning exit command on process: %d.\n", getpid());
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
