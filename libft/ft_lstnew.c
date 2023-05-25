/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:56:38 by esali             #+#    #+#             */
/*   Updated: 2023/04/07 16:07:20 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_ele;

	new_ele = malloc(sizeof(t_list));
	if (!new_ele)
		return (NULL);
	new_ele->next = NULL;
	new_ele->content = content;
	return (new_ele);
}
