/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:06:27 by simao             #+#    #+#             */
/*   Updated: 2023/08/09 20:23:29 by esali            ###   ########.fr       */
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
	int		len;

	curr = get_env();
	curr = curr->nxt;
	while (curr != NULL)
	{
		if (ft_strlen(curr->key) > ft_strlen(key))
			len = ft_strlen(curr->key);
		else
			len = ft_strlen(key);
		if (!ft_strncmp(curr->key, key, len))
		{
			if (curr->value)
				free(curr->value);
			curr->value = NULL;
			if (value)
				curr->value = ft_strdup(value);
			return (1);
		}
		curr = curr->nxt;
	}
	return (0);
}
