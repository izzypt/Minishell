/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:17:44 by smagalha          #+#    #+#             */
/*   Updated: 2023/06/24 23:10:45 by simao            ###   ########.fr       */
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

char	*join_pair(char *key, const char *value)
{
	char			*pair;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	pair = malloc(sizeof(char) * (ft_strlen(key) + ft_strlen(value)) + 2);
	while (key[i] != '\0')
	{
		pair[i] = key[i];
		i++;
	}
	pair[i] = '=';
	i++;
	while (value[j] != '\0')
	{
		pair[i + j] = value[j];
		j++;
	}
	pair[i + j] = '\0';
	return (pair);
}

/*
- It converts the linked list of env variables into a array of strings.
- It returns the array of strings.
- Memory must be released by the caller. Use free_keys().
*/
char	**list_to_array(void)
{
	int		i;
	int		lst_len;
	t_env	*curr;
	char	**strings;

	i = 0;
	curr = get_env()->nxt;
	lst_len = ft_envsize(curr);
	strings = malloc((lst_len + 1) * sizeof(char *));
	while (i < lst_len)
	{
		strings[i] = join_pair(curr->key, curr->value);
		curr = curr->nxt;
		i++;
	}
	strings[i] = NULL;
	return (strings);
}
