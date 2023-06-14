/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:54:51 by simao             #+#    #+#             */
/*   Updated: 2023/06/14 20:36:34 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

/*
- Adds a new node to the list of env variables.
*/
void	cmd_export(char *variable)
{
	char	**input;
	char	*pair;
	char	**key_value;
	t_env	*lst;

	lst = get_env();
	if (!ft_strchr(variable, '='))
		return ;
	input = ft_split(variable, ' ');
	pair = input[1];
	key_value = ft_split(pair, '=');
	while (lst->nxt != NULL)
		lst = lst->nxt;
	lst->nxt = malloc(sizeof(t_env));
	lst = lst->nxt;
	lst->key = key_value[0];
	lst->value = key_value[1];
	lst->pair = pair;
	lst->nxt = NULL;
}
