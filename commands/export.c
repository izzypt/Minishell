/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:54:51 by simao             #+#    #+#             */
/*   Updated: 2023/06/18 17:09:29 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- Adds a new node to the list of env variables.
*/
void	cmd_export(char *variable)
{
	char	**input;
	char	**key_value;
	t_env	*lst;

	lst = get_env();
	if (!ft_strchr(variable, '='))
		return ;
	input = ft_split(variable, ' ');
	key_value = ft_split(input[1], '=');
	while (lst->nxt != NULL)
		lst = lst->nxt;
	lst->nxt = malloc(sizeof(t_env));
	lst = lst->nxt;
	lst->key = ft_strdup(key_value[0]);
	lst->value = ft_strdup(key_value[1]);
	lst->nxt = NULL;
	free_keys(input);
	free_keys(key_value);
}
