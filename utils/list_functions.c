/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:14:32 by esali             #+#    #+#             */
/*   Updated: 2023/08/06 12:02:17 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew(char **token, char *path, t_list *lst_old)
{
	t_list	*new_ele;

	new_ele = malloc(sizeof(t_list));
	if (!new_ele)
		return (NULL);
	new_ele->next = NULL;
	new_ele->token = token;
	new_ele->path = path;
	new_ele->is_head = 0;
	new_ele->prev = lst_old;
	return (new_ele);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

char	*ft_getenv(char *key)
{
	t_env	*lst;

	lst = get_env();
	lst = lst->nxt;
	while (lst != NULL)
	{
		if (!ft_strncmp(lst->key, key, ft_strlen(key)))
		{
			return (lst->value);
			break ;
		}
		lst = lst->nxt;
	}
	return (NULL);
}
