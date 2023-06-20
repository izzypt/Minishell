/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:50 by simao             #+#    #+#             */
/*   Updated: 2023/06/20 17:23:06 by esali            ###   ########.fr       */
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

	lst = get_env();
	while (lst != NULL)
	{
		if (lst->nxt == NULL)
			break ;
		if (!ft_strncmp(lst->nxt->key, variable[1], ft_strlen(variable[1])))
		{
			tmp = lst->nxt;
			lst->nxt = lst->nxt->nxt;
			free(tmp->value);
			free(tmp->key);
			free(tmp);
			break ;
		}
		lst = lst->nxt;
	}
}
