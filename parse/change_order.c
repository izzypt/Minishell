/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:17:52 by esali             #+#    #+#             */
/*   Updated: 2023/08/07 15:09:13 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// adds a new array-element to char **token
char	**add_new_token(char **token, char *new)
{
	char	**new_lst;
	int		lst_ele;
	int		i;

	lst_ele = 0;
	while (token != NULL && token[lst_ele])
		lst_ele++;
	new_lst = (char **)malloc(sizeof(char *) * (lst_ele + 2));
	if (!new_lst)
		return (NULL);
	i = 0;
	while (token != NULL && token[i])
	{
		new_lst[i] = token[i];
		i++;
	}
	new_lst[i] = new;
	new_lst[i + 1] = '\0';
	if (token)
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

// lst is node with redirection
void	move_tokens_new_ele(t_list *lst)
{
	int		i;
	char	**token;
	char	*path;
	t_list	*new;
	t_list	*list_head;

	i = 1;
	token = NULL;
	while (lst->next->token[i] != NULL)
	{
		token = add_new_token(token, lst->next->token[i]);
		i++;
	}
	lst->next->token = remove_token(lst->next->token);
	path = valid_cmd_path(token[0]);
	new = ft_lstnew(token, path, list_heads());
	list_head = list_heads();
	new->next = list_head->next;
	list_head->next->prev = new;
	list_head->next = new;
}

/* replaces extra tokens after redirections to first node,
that does not have prev builtin */
void	move_tokens(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst->prev;
	while (tmp->prev)
	{
		if ((is_built_in(tmp->token[0]) || tmp->path != NULL) && \
		(tmp->prev->is_head || !is_red(tmp->prev->token[0])))
		{
			i = 1;
			while (lst->next->token[i] != NULL)
			{
				tmp->token = add_new_token(tmp->token, lst->next->token[i]);
				i++;
			}
			lst->next->token = remove_token(lst->next->token);
			return ;
		}
		tmp = tmp->prev;
		if (tmp->token != NULL && is_special_char(tmp->token[0]))
			tmp = tmp->prev;
	}
	if (tmp->prev == NULL)
		move_tokens_new_ele(lst);
}

void	change_order(void)
{
	t_list	*lst;

	lst = list_heads()->next;
	while (lst->next != NULL)
	{
		if (is_red(lst->token[0]) && lst->next->token[1])
		{
			if (lst->prev->prev == NULL)
				move_tokens_new_ele(lst);
			else
				move_tokens(lst);
		}
		lst = lst->next;
	}
	lst = list_heads()->next;
	if (is_red(lst->token[0]))
		add_first_token();
}
