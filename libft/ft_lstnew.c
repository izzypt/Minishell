/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:56:38 by esali             #+#    #+#             */
/*   Updated: 2023/05/27 16:22:32 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *token)
{
	t_list	*new_ele;

	new_ele = malloc(sizeof(t_list));
	if (!new_ele)
		return (NULL);
	new_ele->next = NULL;
	new_ele->token = token;
	return (new_ele);
}
