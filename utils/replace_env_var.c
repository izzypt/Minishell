/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:06:27 by simao             #+#    #+#             */
/*   Updated: 2023/08/03 23:35:44 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- Return 1 if it has replaced an env variable value.
- Return 0 if it has not replaced env variable value or hasn't found a key.
*/
int	replace_env_var(char *key, char *value)
{
	t_env	*curr;

	curr = get_env();
	curr = curr->nxt;
	while (curr != NULL)
	{
		if (!ft_strncmp(curr->key, key, strlen(curr->key)))
		{
			free(curr->value);
			curr->value = ft_strdup(value);
			return (1);
		}
		curr = curr->nxt;
	}
	return (0);
}
