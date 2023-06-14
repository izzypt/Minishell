/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:35 by simao             #+#    #+#             */
/*   Updated: 2023/06/14 20:13:48 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

/*
- Struct getter.
- Returns a pointer to the head of the env variables list.
*/
t_env	*get_env(void)
{
	static t_env	data;

	return (&data);
}

/*
- Creates a new node for each variable in env.
- Each node holds the key, the value, and the pair.
*/
void	create_env(char **env)
{
	int		i;
	t_env	*lst;
	char	**keys;

	i = 0;
	lst = get_env();
	while (env[i])
	{
		keys = ft_split(env[i], '=');
		lst->key = keys[0];
		lst->value = keys[1];
		lst->pair = env[i];
		if (env[i + 1] != NULL)
		{
			lst->nxt = malloc(sizeof(t_env));
			lst = lst->nxt;
		}
		else
			lst->nxt = NULL;
		while (*keys++)
			free(*keys);
		i++;
	}
}

/*
- Iterate through the list of env variables and prints each one.
*/
void	cmd_env(void)
{
	t_env	*lst;

	lst = get_env();
	if (lst == NULL)
	{
		printf("No environment variables found.\n");
		return ;
	}
	while (lst)
	{
		printf("%s\n", lst->pair);
		lst = lst->nxt;
	}
}
