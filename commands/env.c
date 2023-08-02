/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simao <simao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:35 by simao             #+#    #+#             */
/*   Updated: 2023/08/02 16:22:38 by simao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
- Should free the memory allocated from splitting the key/value pair...
  ... of each env variable in the function create_env().
- It can also be used for other situations where split() was used.
*/
void	free_keys(char **keys)
{
	int	j;

	j = 0;
	if (!*keys || !keys[0])
		return ;
	while (keys[j])
	{
		free(keys[j]);
		j++;
	}
	free(keys);
}

/*
- Set the key and the value of each environment variable.
*/
void	set_env_key_value_pair(char **keys, t_env *lst)
{
	if (keys[0] != NULL)
		lst->key = ft_strdup(keys[0]);
	else
		lst->key = NULL;
	if (keys[1] != NULL)
		lst->value = ft_strdup(keys[1]);
	else
		lst->value = NULL;
}

/*
- Creates a new node for each variable in env.
- Each node holds the key and the value of a env variable.
*/
void	create_env(char **env)
{
	int		i;
	t_env	*lst;
	char	**keys;

	i = 0;
	lst = get_env();
	lst->nxt = malloc(sizeof(t_env));
	lst = lst->nxt;
	while (env[i])
	{
		keys = ft_split(env[i], '=');
		set_env_key_value_pair(keys, lst);
		free_keys(keys);
		if (env[i + 1] != NULL)
		{
			lst->nxt = malloc(sizeof(t_env));
			lst = lst->nxt;
		}
		else
			lst->nxt = NULL;
		i++;
	}
}

/*
- Iterate through the list of env variables and prints each one.
*/
void	cmd_env(void)
{
	t_env	*env;

	env = get_env();
	env = env->nxt;
	if (env == NULL)
	{
		ft_printf("No environment variables found.\n");
		return ;
	}
	while (env)
	{
		ft_printf("%s=%s\n", env->key, env->value);
		env = env->nxt;
	}
}
