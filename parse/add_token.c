/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:08:52 by esali             #+#    #+#             */
/*   Updated: 2023/08/09 02:30:13 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_first_token(void)
{
	char	**token;
	t_list	*list_head;
	t_list	*new;
	char	*path;

	token = (char **)malloc(sizeof(char *) * 3);
	if (!token)
		return ;
	token[0] = ft_strdup("echo\0");
	token[1] = ft_strdup("-n\0");
	token[2] = NULL;
	path = NULL;
	list_head = get_token();
	new = ft_lstnew(token, path, list_head);
	new->next = list_head->next;
	list_head->next->prev = new;
	list_head->next = new;
}
