/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagalha <smagalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:17:44 by smagalha          #+#    #+#             */
/*   Updated: 2023/06/21 19:34:51 by smagalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_envsize(t_env *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->nxt;
		i++;
	}
	return (i);
}

void	list_to_array(void)
{
	int		len;
	t_env	*curr;
	//char	**array;

	curr = get_env()->nxt;
	printf("curent data %s\n", curr->key);
	len = ft_envsize(curr);
	printf("Linked list size : %d\n", len);
	//array = malloc(sizeof(len) * (char *))


}
