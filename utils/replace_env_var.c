/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:06:27 by simao             #+#    #+#             */
/*   Updated: 2023/06/16 16:43:58 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

void	replace_env_var(char *key, char *value)
{
	t_env	*curr;

	curr = get_env();
	while (curr != NULL)
	{
		if (!ft_strncmp(curr->key, key, strlen(curr->key)))
		{
			free(curr->value);
			curr->value = value;
			break ;
		}
		curr = curr->nxt;
	}
}
