/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:31 by simao             #+#    #+#             */
/*   Updated: 2023/08/01 17:44:04 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* Should release all allocated resources before exiting */
void	cmd_exit(int number)
{
	t_env	*lst;
	t_env	*tmp;

	ft_printf("Running exit command on process: %d.\n", getpid());
	lst = get_env();
	lst = lst->nxt;
	if (get_data()->envp)
		free_keys(get_data()->envp);
	while (lst != NULL)
	{
		tmp = lst->nxt;
		free(lst->key);
		free(lst->value);
		free(lst);
		lst = tmp;
	}
	exit(number);
}
