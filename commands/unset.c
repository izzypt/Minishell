/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:50 by simao             #+#    #+#             */
/*   Updated: 2023/08/10 20:23:38 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- Removes a node from the list of env variables.
- Still need to fix for the case where the key is at the head of the list.
*/
void	cmd_unset(char **variable)
{
	t_env	*lst;
	t_env	*tmp;
	int		i;

	if (!variable[1])
		return ;
	i = 1;
	while(variable[i])
	{
		lst = get_env();
		while (lst->nxt != NULL)
		{
			if (!ft_strncmp(lst->nxt->key, variable[i], \
			maxlen(variable[i], lst->nxt->key)))
			{
				tmp = lst->nxt;
				lst->nxt = lst->nxt->nxt;
				free(tmp->value);
				free(tmp->key);
				free(tmp);
			}
			lst = lst->nxt;
		}
		i++;
	}
}
