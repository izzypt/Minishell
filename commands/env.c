/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:35 by simao             #+#    #+#             */
/*   Updated: 2023/08/12 18:08:29 by esali            ###   ########.fr       */
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
	while (keys[j])
	{
		if (keys[j])
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
void	cmd_env(char **token)
{
	t_env	*env;

	if (token[1])
	{
		write(2, "env: invalid argument\n", 22);
		get_data()->exit = 2;
		return ;
	}
	env = get_env();
	env = env->nxt;
	if (env == NULL)
	{
		write(2, "No environment variables found.\n", 32);
		return ;
	}
	while (env)
	{
		if (env->value != NULL)
			ft_printf("%s=%s\n", env->key, env->value);
		env = env->nxt;
	}
}
