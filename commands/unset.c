/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:50 by simao             #+#    #+#             */
/*   Updated: 2023/06/18 16:11:47 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
- Removes a node from the list of env variables.
- Still need to fix for the case where the key is at the head of the list.
*/
void	cmd_unset(char *variable)
{
	t_env	*lst;
	t_env	*tmp;
	char	**input;

	lst = get_env();
	input = ft_split(variable, ' ');
	while (lst != NULL && input[1])
	{
		if (lst->nxt == NULL)
			break ;
		if (!ft_strncmp(lst->nxt->key, input[1], ft_strlen(input[1])))
		{
			tmp = lst->nxt;
			lst->nxt = lst->nxt->nxt;
			free(tmp);
			break ;
		}
		lst = lst->nxt;
	}
}
