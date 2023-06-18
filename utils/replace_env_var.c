/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:06:27 by simao             #+#    #+#             */
/*   Updated: 2023/06/18 18:41:42 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	replace_env_var(char *key, char *value)
{
	t_env	*curr;

	curr = get_env();
	curr = curr->nxt;
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
