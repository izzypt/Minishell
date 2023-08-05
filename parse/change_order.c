/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:17:52 by esali             #+#    #+#             */
/*   Updated: 2023/08/05 19:24:39 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**add_new_token(char **token, char *new)
{
	char	**new_lst;
	int		lst_ele;
	int		i;

	lst_ele = 0;
	while(token[lst_ele])
		lst_ele++;
	new_lst = (char **)malloc(sizeof(char *) * (lst_ele + 2));
	if (!new_lst)
		return NULL;
	i = 0;
	while (token[i])
	{
		new_lst[i] = token[i];
		i++;
	}
	new_lst[i] = new;
	new_lst[i + 1] = '\0';
	free(token);
	return (new_lst);
}

char	**remove_token(char **token)
{
	char	**new_lst;

	new_lst = (char **)malloc(sizeof(char *) * 2);
	if (!new_lst)
		return (NULL);
	new_lst[0] = token[0];
	new_lst[1] = '\0';
	free(token);
	return (new_lst);
}

void	change_order(void)
{
	t_list	*lst;
	int		i;

	lst = list_heads()->next;
	while (lst->next != NULL)
	{
		if (is_red(lst->token[0]) && lst->next->token[1])
		{
			i = 1;
			while(lst->next->token[i] != NULL)
			{
				lst->prev->token = add_new_token(lst->prev->token, lst->next->token[i]);
				i++;
			}
			lst->next->token = remove_token(lst->next->token);
		}
		lst = lst->next;
	}
}
