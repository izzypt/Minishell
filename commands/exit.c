/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:31 by simao             #+#    #+#             */
/*   Updated: 2023/08/05 13:19:39 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* Should release all allocated resources before exiting */
void	cmd_exit(int number)
{
	t_env	*lst;
	t_env	*tmp;

	lst = get_env();
	lst = lst->nxt;
	if (get_data()->envp)
		free_keys(get_data()->envp);
	while (lst != NULL)
	{
		tmp = lst->nxt;
		free(lst->key);
		if (lst->value)
			free(lst->value);
		free(lst);
		lst = tmp;
	}
	free_parse();
	exit(number);
}

void	free_env(void)
{
	t_env	*lst;
	t_env	*tmp;

	lst = get_env();
	lst = lst->nxt;
	while (lst != NULL)
	{
		tmp = lst->nxt;
		free(lst->key);
		if (lst->value)
			free(lst->value);
		free(lst);
		lst = tmp;
	}
}
